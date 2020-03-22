#include <stdio.h>
#include <limits.h>

int main(int argc, char const * argv[]) {

  printf("From limits.h:\n");
	printf(" CHAR_BIT: %1$4d [%1$02hhx]\n", CHAR_BIT);
	printf(" CHAR_MIN: %1$4hhd [%1$02hhx]\n", CHAR_MIN);
	printf(" CHAR_MAX: %1$4hhd [%1$02hhx]\n", CHAR_MAX);
	printf("SCHAR_MIN: %1$4hhd [%1$02hhx]\n", SCHAR_MIN);
	printf("SCHAR_MAX: %1$4hhd [%1$02hhx]\n", SCHAR_MAX);
	printf("UCHAR_MAX: %1$4hhu [%1$02hhx]\n", UCHAR_MAX);
	printf(" SHRT_MIN: %1$6hd [%1$04hx]\n", SHRT_MIN);
	printf(" SHRT_MAX: %1$6hd [%1$04hx]\n", SHRT_MAX);
	printf("USHRT_MAX: %1$6hu [%1$04hx]\n", USHRT_MAX);
	printf("  INT_MIN: %1$11d [%1$08x]\n", INT_MIN);
	printf("  INT_MAX: %1$11d [%1$08x]\n", INT_MAX);
	printf(" UINT_MAX: %1$11u [%1$08x]\n", UINT_MAX);
	printf(" LONG_MIN: %1$20ld [%1$016lx]\n", LONG_MIN);
	printf(" LONG_MAX: %1$20ld [%1$016lx]\n", LONG_MAX);
	printf("ULONG_MAX: %1$20lu [%1$016lx]\n", ULONG_MAX);
  putchar('\n');

  printf("From calculation:\n");
  printf("  signed char  min=%1$4hhd [%1$02hhx]\n", -(char) ((unsigned char) ~0 >> 1) - 1);
  printf("  signed char  max=%1$4d [%1$02x]\n", (char) ((unsigned char) ~0 >> 1));
  printf("unsigned char  max=%1$4hhu [%1$02hhx]\n", ((unsigned char) ~0));
  printf("  signed short min=%1$6hd [%1$04hx]\n", -(short) ((unsigned short) ~0 >> 1) - 1);
  printf("  signed short max=%1$6hd [%1$04hx]\n", (short) ((unsigned short) ~0 >> 1));
	printf("unsigned short max=%1$6hu [%1$04hx]\n", ((unsigned short) ~0));
  printf("  signed int   min=%1$11d [%1$08x]\n", -(int) ((unsigned int) ~0 >> 1) - 1);
  printf("  signed int   max=%1$11d [%1$08x]\n", (int) ((unsigned int) ~0 >> 1));
	printf("unsigned int   max=%1$11u [%1$08x]\n", ((unsigned int) ~0));
  printf("  signed long  min=%1$20ld [%1$016lx]\n", -(long) ((unsigned long) ~0 >> 1) - 1);
  printf("  signed long  max=%1$20ld [%1$016lx]\n", (long) ((unsigned long) ~0 >> 1));
	printf("unsigned long  max=%1$20lu [%1$016lx]\n", ((unsigned long) ~0));
  putchar('\n');

  return 0;
}
