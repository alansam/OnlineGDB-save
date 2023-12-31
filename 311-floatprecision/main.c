
#include <stdio.h>
#include <stdint.h>
#include <gmp.h>

int main() {
  // I'm wondering why 4.20 turns  to 419.999969 in line 3 instead of 420?

  puts("float");
  float amount = 4.20F;
  printf("amount: %f\n", amount);
  printf("pennies: %f\n", amount * 100.f);  // <-- line 3
  printf("amount: %.19f\n", amount);
  printf("pennies: %.19f\n", amount * 100.f);
  putchar('\n');

  puts("double");
  double damount = 4.20;
  printf("amount: %f\n", damount);
  printf("pennies: %f\n", damount * 100.);
  printf("amount: %.19f\n", damount);
  printf("pennies: %.19f\n", damount * 100.);
  putchar('\n');

  puts("long double");
  long double lamount = 4.20L;
  printf("amount: %Lf\n", lamount);
  printf("pennies: %Lf\n", lamount * 100.L);
  printf("amount: %.39Lf\n", lamount);
  printf("pennies: %.39Lf\n", lamount * 100.L);
  putchar('\n');

  puts("GMP float");
  mpf_set_default_prec(200ul);
  mpf_t mamount;
  mpf_t mpennies;
  mpf_t m100;
  mpf_init(mamount);
  mpf_init(mpennies);
  mpf_init(m100);

  mpf_set_d(mamount, 4.20);
  mpf_set_ui(m100, 100u);
  gmp_printf("amount: %Ff\n", mamount);
  mpf_mul(mpennies, mamount, m100);
  gmp_printf("pennies: %Ff\n", mpennies);

  mpf_set_d(mamount, 4.20);
  gmp_printf("amount: %.39Ff\n", mamount);
  mpf_mul(mpennies, mamount, m100);
  gmp_printf("pennies: %.39Ff\n", mpennies);

  mpf_clear(mamount);
  mpf_clear(mpennies);
  putchar('\n');

  puts("GMP integer with scale");
  mpz_t zamount;
  uint64_t zamount_scale;
  mpz_t zpennies;
  uint64_t zpennies_scale;
  mpz_t zwork;
  mpz_t zquot;
  mpz_t zremd;
  mpz_inits(zamount, zpennies, zwork, zquot, zremd, NULL);
  mpz_set_ui(zamount, 420ul);
  zamount_scale = 2ul;
  zpennies_scale = 8ul;

  gmp_printf("amount: %09Zd %09d\n", zamount, zamount_scale);
  mpz_ui_pow_ui(zwork, 10ul, zamount_scale);
  gmp_printf("scale: %09Zd <- %lu ** %lu\n", zwork, 10ul, zamount_scale);
  mpz_tdiv_qr(zquot, zremd, zamount, zwork);
  gmp_printf("amount: %09Zd %09Zd (%Zd.%Zd)\n", zquot, zremd, zquot, zremd);
  mpz_ui_pow_ui(zwork, 10ul, zpennies_scale - zamount_scale);
  gmp_printf("scale: %09Zd <- %lu ** %lu\n", zwork, 10ul, zpennies_scale - zamount_scale);
  mpz_mul(zpennies, zamount, zwork);
  gmp_printf("pennies: %012Zd <- %012Zd * %012Zd\n", zpennies, zamount, zwork);
  mpz_ui_pow_ui(zwork, 10ul, zpennies_scale);
  gmp_printf("scale: %09Zd <- %lu ** %lu\n", zwork, 10ul, zpennies_scale);
  mpz_tdiv_qr(zquot, zremd, zpennies, zwork);
  gmp_printf("pennies: %09Zd %09Zd (%Zd.%Zd)\n", zquot, zremd, zquot, zremd);


  mpz_clears(zamount, zpennies, zwork, zquot,zremd, NULL);
  putchar('\n');

  double frac = 3. / 10.;
  printf("%.19f %.19f\n", frac, frac * 10.);
  frac = 4.25;
  printf("frac %.19f %a\n", frac, frac);
  putchar('\n');

  double fric;
  char const * cf = "0x1.1p+2";
  sscanf(cf, "%la", &fric);
  printf("fric %.19f %a\n", fric, fric);
  putchar('\n');

  int ipennies = (int) ((amount * 100.0f) - .5f);
  float carryover = ((amount * 100.0f) - .5f) - (float) ipennies;
  if (carryover >= .5f) { ++ipennies; }
  printf("pennies %d %f\n", ipennies, carryover);
  putchar('\n');

  ipennies = (int) ((damount * 100.0) - .5);
  double dcarryover = ((damount * 100.0) - .5) - (float) ipennies;
  if (dcarryover >= .5f) { ++ipennies; }
  printf("pennies %d %f\n", ipennies, dcarryover);
  putchar('\n');

  return 0;
}

