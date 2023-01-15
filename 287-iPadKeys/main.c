
#include <stdio.h>

#define ROW 4
#define SHIFT 4

typedef struct keys keys;
struct keys {
  char const * const nm;
  char const * const keys;
};

static
keys const ipad_keys[][SHIFT] = {
// ! Keyboard option keys:
  {
    {          "", "` 1 2 3 4 5 6 7 8 9 0 - =", },
    {      "+opt", "` ¡ ™ £ ¢ ∞ § ¶ • ª º – ≠", },
    {     "shift", "~ ! @ # $ % ^ & * ( ) _ +", },
    { "shift+opt", "` ⁄ € ‹ › ﬁ ﬂ ‡ ° · ‚ — ±", },
  },
  {
    {          "", "   q w e r t y u i o p [ ] \\", },
    {      "+opt", "   œ ∑ ´ ® † ¥ ¨ ˆ ø π “ ‘ «", },
    {     "shift", "   Q W E R T Y U I O P { } |", },
    { "shift+opt", "   Œ „ ´ ‰ ˇ Á ¨ ˆ Ø ∏ ” ’ »", },
  },
  {
    {          "", "    a s d f g h j k l ; '", },
    {      "+opt", "    å ß ∂ ƒ © ˙ ∆ ˚ ¬ … æ", },
    {     "shift", "    A S D F G H J K L : \"", },
    { "shift+opt", "    Å Í Î Ï ˝ Ó Ô  Ò Ú Æ", },
  },
  {
    {          "", "     z x c v b n m , . /", },
    {      "+opt", "     Ω ≈ ç √ ∫ ˜ µ ≤ ≥ ÷", },
    {     "shift", "     Z X C V B N M < > ?", },
    { "shift+opt", "     ¸ ˛ Ç ◊ ı ˜ Â ¯ ˘ ¿", },
  },
};
static
size_t const ipad_keys_sz = sizeof ipad_keys / sizeof *ipad_keys;

int main() {
  printf("iPad keyboard option keys:\n");

  for (size_t k_ = 0ul; k_ < ipad_keys_sz; ++k_) {
    printf("Row %3zu:\n", k_ + 1);
    for (size_t s_ = 0ul; s_ < SHIFT; ++s_) {
      printf("%20s: %s\n", ipad_keys[k_][s_].nm, ipad_keys[k_][s_].keys);
    }
    putchar('\n');
  }
  putchar('\n');

  return 0;
}
