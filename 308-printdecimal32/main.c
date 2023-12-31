//  @see: https://stackoverflow.com/questions/57017033/why-doesnt-this-decimal32-value-have-the-expected-bit-pattern/57017430#57017430

//  opts: -Wall -Wpedantic -lgmp -std=gnu2x -fsanitize=address

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

static uint8_t exponent_msbs[] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1,
    2, 2, 2, 2, 2, 2, 2, 2,
    0, 0, 1, 1, 2, 2, 255, 255
};

static uint8_t coefficient_msbs[] =
{
    0, 1, 2, 3, 4, 5, 6, 7,
    0, 1, 2, 3, 4, 5, 6, 7,
    0, 1, 2, 3, 4, 5, 6, 7,
    8, 9, 8, 9, 8, 9, 255, 255
};


static void print_bits(const char *pre, 
  uint32_t value, int len, const char *post)
{
  printf("%s", pre);
  for(int i = (len - 1); i >= 0; i--) {
    printf("%d", (value>>i)&1);
  }
  printf("%s", post);
}

#define shift_sign 31
#define shift_combination 26
#define width_combination 5
#define shift_exponent 20
#define width_exponent 6
#define width_coefficient 20
#define bias 101

static const uint32_t mask_combination = (1<<width_combination) - 1;
static const uint32_t mask_exponent = (1<<width_exponent) - 1;
static const uint32_t mask_coefficient = (1<<width_coefficient) - 1;

void print_decimal32(_Decimal32 dvalue)
{
    uint32_t uvalue = 0;
    memcpy((uint8_t*)&uvalue, (uint8_t*)&dvalue, sizeof(uvalue));

    uint32_t combination = (uvalue>>shift_combination) & mask_combination;
    uint32_t sign = uvalue>>shift_sign;
    uint32_t exponent_hi = exponent_msbs[combination];
    uint32_t coefficient_hi = coefficient_msbs[combination];
    uint32_t exponent_lo = (uvalue>>shift_exponent)&mask_exponent;
    uint32_t coefficient_lo = uvalue & mask_coefficient;

    int32_t exponent = (exponent_hi << width_exponent) + exponent_lo - bias;
    uint32_t coefficient =  (coefficient_hi << width_coefficient) + coefficient_lo;

    printf("Hex:       %08x\n", uvalue);
    print_bits("Binary: ", uvalue, 32, "\n");
    printf("s %x, comb %x, eh %x, el %x, ch %x, cl %x, e %x, c %x\n",
        sign, combination, exponent_hi, exponent_lo,
        coefficient_hi, coefficient_lo, exponent, coefficient);
    printf("Result: %d x 10^%d\n", coefficient, exponent);
}

void BIS_print_decimal32(_Decimal32 dvalue)
{
    uint32_t uvalue = 0;
    // static_assert(sizeof(_Decimal32) == sizeof(uint32_t), "");
    memcpy(&uvalue, &dvalue, sizeof(uvalue));

    uint32_t sign = (uvalue >> 31) & 1;
    uint32_t combination = (uvalue >> (20 + 6)) & 0b11111;
    uint32_t exponent = (uvalue >> (20)) & 0b111111;
    uint32_t coefficient = uvalue & 0b111111111111111111;

    // binary integer significant field
    uint32_t two_bits_after_the_sign_bit = (uvalue >> (32 - 3)) & 3;
    uint32_t significand = 0;
    // If the 2 bits after the sign bit are "00", "01", or "10",
    if (two_bits_after_the_sign_bit != 0b11) {
        // then the exponent field consists of the 8 bits following the sign bit,
        exponent = (uvalue >> (32 - 9)) & 0xff;
        exponent -= 101;
        // and the significand is the remaining 23 bits, with an implicit leading 0 bit: 
        significand = uvalue & 0b111111111111111111111;
    } else {
        // TODO:
        assert(0);
        abort();
        // If the 2 bits after the sign bit are "11", 
        // then the 8-bit exponent field is shifted 2 bits to the right
        // (after both the sign bit and the "11" bits thereafter), 
        // and the represented significand is in the remaining 21 bits. 
        // In this case there is an implicit (that is, not stored) leading 3-bit sequence "100" 
        // in the true significand. 
    }

    // TODO: handle NAN and INF
    uint32_t four_bits_after_the_sign_bit = (uvalue >> (32 - 5)) & 0xf;
    if (four_bits_after_the_sign_bit == 0b1111) {
        assert(0);
        abort();
    }

    printf("value = %+d * 10^%d * %d\n",
        (int)sign,
        (int)exponent,
        (int)significand
    );
}

int declet_to_decimal(uint32_t declet) {
    uint32_t b3 = (declet >> 3) & 1;
    if (b3 == 0) {
        uint32_t b9b8b7 = (declet >> 7) & 0b111;
        uint32_t b6b5b4 = (declet >> 4) & 0b111;
        uint32_t b2b1b0 = (declet >> 0) & 0b111;
        return b9b8b7 * 100 + b6b5b4 * 10 + b2b1b0;
    }
    // TODO: Densely packed decimal encoding rules[4]
    assert(0);
    abort();
    return 0;
}

void DPD_print_decimal32(_Decimal32 dvalue)
{
    uint32_t uvalue = 0;
    // static_assert(sizeof(_Decimal32) == sizeof(uint32_t), "");
    memcpy(&uvalue, &dvalue, sizeof(uvalue));

    uint32_t sign = (uvalue >> 31) & 1;
    uint32_t combination = (uvalue >> (20 + 6)) & 0b11111;
    uint32_t exponent = (uvalue >> (20)) & 0b111111;
    uint32_t coefficient = uvalue & 0b111111111111111111;

   // TODO: handle NAN and INF
    uint32_t four_bits_after_the_sign_bit = (uvalue >> (32 - 5)) & 0xf;
    if (four_bits_after_the_sign_bit == 0b1111) {
        assert(0);
        abort();
    }

    // Densely packed decimal significand field
    uint32_t two_bits_after_the_sign_bit = (uvalue >> (32 - 3)) & 3;
    uint32_t leading_decimal_digit = 0;
    // If the 2 bits after the sign bit are "00", "01", or "10",
    if (two_bits_after_the_sign_bit != 0b11) {
        // If the first two bits after the sign bit are "00", "01", or "10", 
        // then those are the leading bits of the exponent,
        exponent = (two_bits_after_the_sign_bit << 6) | exponent;
        exponent -= 101;
        // and the three bits after that are interpreted as the leading decimal digit (0 to 7):
        uint32_t three_bits_after_the_two_bits_after_sign_bit = (uvalue >> (32 - 6)) & 0b111; 
        leading_decimal_digit = three_bits_after_the_two_bits_after_sign_bit;
        printf("leading_decimal_digit: %d\n", leading_decimal_digit);
    } else {
        // TODO:
        assert(0);
        abort();
    }

    uint32_t significand = coefficient;
    uint32_t declet1 = (significand >> 10) & 0b1111111111;
    uint32_t declet2 = significand & 0b1111111111;

    uint32_t decimal1 = declet_to_decimal(declet1);
    uint32_t decimal2 = declet_to_decimal(declet2);

    uint32_t truesignificand = 
        leading_decimal_digit * 1000000 + 
        decimal1 * 1000 + 
        decimal2;


    printf("value = %+d * 10^%d * %d\n",
        (int)sign,
        (int)exponent,
        (int)truesignificand
    );
}

#define PRINT_DECIMAL32(VALUE)  do{ \
    printf("==> Decimal32: " #VALUE " <== \n"); \
    print_decimal32(VALUE); \
    printf("# BIS_print_decimal32\n"); \
    BIS_print_decimal32(VALUE); \
    printf("# DPD_print_decimal32\n"); \
    DPD_print_decimal32(VALUE); \
    printf("\n\n"); \
    }while(0)

int main()
{
    PRINT_DECIMAL32(1);
    PRINT_DECIMAL32(2);
    PRINT_DECIMAL32(3);
    PRINT_DECIMAL32(4);
    return 0;
}
