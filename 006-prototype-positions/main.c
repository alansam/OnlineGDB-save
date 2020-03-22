
#include <stdio.h>

int main(int argc, char const * argv[])
{
  void func1(int);

  printf("Argument 0: %s\n", argv[0]);
  func1(argc);

  return 0;
}

void func1(int ac)
{
  printf("%s\n", __func__);

  void func2(int);
  printf("Argument: %d\n", ac);
  func2(ac);

  return;
}

void func2(int a1)
{
  printf("%s\n", __func__);
  printf("Argument: %d\n", a1 + 1);

  return;
}
