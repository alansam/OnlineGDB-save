
#include <stdio.h>
#include <stdint.h>

static
void fnuc(char const * str) {
  printf("Fnuction %s(): from %s()\n", __func__, str);
  return;
}

int main() {
  void (*fp1)(char const *);

  fp1 = fnuc;

  puts("Call fnuc():");
  (***********fp1)(__func__);
  putchar('\n');

  uint8_t * fff = (uint8_t *) fp1;
  size_t fff_sz = ((void *) main - (void *) fnuc); // TODO: ugh! Maybe find a better way ...
  printf("main() : %p - fnuc() : %p - sz : %zu\n", (void *) main, (void *) fnuc, fff_sz);
  puts("Dissamble fnuc():");
  for (size_t p_ = 0; p_ < fff_sz; ++p_) {
    printf("%5zu - %08lx - %p: %02x\n", p_, p_, (void *) fff + p_, fff[p_]);
  }
  putchar('\n');

  return 0;
}
