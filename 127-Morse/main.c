
#include <stdio.h>

typedef struct morse morse;
struct morse {
  char letter;
  char code[20];
};

static
morse const alphabet[] = {
  { 'A', "\u2022\u2011", },             // •‑
  { 'B', "\u2011\u2022\u2022\u2022", }, // ‑•••
  { 'C', "\u2011\u2022\u2011\u2022", }, // ‑•‑•
  { 'D', "\u2011\u2022\u2022", },       // ‑••
  { 'E', "\u2022", },                   // •
  { 'F', "\u2022\u2022\u2011\u2022", }, // ••‑•
  { 'G', "\u2011\u2011\u2022", },       // ‑‑•
  { 'H', "\u2022\u2022\u2022\u2022", }, // ••••
  { 'I', "\u2022\u2022", },             // ••
  { 'J', "\u2022\u2011\u2011\u2011", }, // •‑‑‑
  { 'K', "\u2011\u2022\u2011", },       // ‑•‑
  { 'L', "\u2022\u2011\u2022\u2022", }, // •‑••
  { 'M', "\u2011\u2011", },             // ‑‑
  { 'N', "\u2011\u2022", },             // ‑•
  { 'O', "\u2011\u2011\u2011", },       // ‑‑‑
  { 'P', "\u2022\u2011\u2011\u2022", }, // •‑‑•
  { 'Q', "\u2011\u2011\u2022\u2011", }, // ‑‑•‑
  { 'R', "\u2022\u2011\u2022", },       // •‑•
  { 'S', "\u2022\u2022\u2022", },       // •••
  { 'T', "\u2011", },                   // ‑
  { 'U', "\u2022\u2022\u2011", },       // ••‑
  { 'V', "\u2022\u2022\u2022\u2011", }, // •••‑
  { 'W', "\u2022\u2011\u2011", },       // •‑‑
  { 'X', "\u2011\u2022\u2022\u2011", }, // ‑••‑
  { 'Y', "\u2011\u2022\u2011\u2011", }, // ‑•‑‑
  { 'Z', "\u2011\u2011\u2022\u2011", }, // ‑‑•‑
};
static
size_t const alphabet_sz = sizeof(alphabet) / sizeof(*alphabet);

static
morse const numbers[] = {
  { '0', "\u2011\u2011\u2011\u2011\u2011", }, // ‑‑‑‑‑
  { '1', "\u2022\u2011\u2011\u2011\u2011", }, // •‑‑‑‑
  { '2', "\u2022\u2022\u2011\u2011\u2011", }, // ••‑‑‑
  { '3', "\u2022\u2022\u2022\u2011\u2011", }, // •••--
  { '4', "\u2022\u2022\u2022\u2022\u2011", }, // ••••-
  { '5', "\u2022\u2022\u2022\u2022\u2022", }, // •••••
  { '6', "\u2011\u2022\u2022\u2022\u2022", }, // ‑••••
  { '7', "\u2011\u2011\u2022\u2022\u2022", }, // ‑‑•••
  { '8', "\u2011\u2011\u2011\u2022\u2022", }, // ‑‑‑••
  { '9', "\u2011\u2011\u2011\u2011\u2022", }, // ‑‑‑‑•
};
static
size_t const numbers_sz = sizeof(numbers) / sizeof(*numbers);

int main() {
  for (size_t m_ = 0; m_ < alphabet_sz; ++m_) {
    printf(" %c %s\n", alphabet[m_].letter, alphabet[m_].code);
  }

  for (size_t n_ = 0; n_ < numbers_sz; ++n_) {
    printf(" %c %s\n", numbers[n_].letter, numbers[n_].code);
  }

  return 0;
}

