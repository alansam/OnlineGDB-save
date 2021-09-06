
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
  char nums[32] = { '\0', };
  size_t const nums_sz = sizeof(nums) / sizeof(*nums);
  int value = 0;
  size_t pos = 0;
  printf("? ");
  fflush(stdout);

  int ic;
  while ((ic = getchar()) != '\n' && pos < nums_sz) {
    if (pos == 0 && (ic == '+' || ic == '-')) {
      nums[pos++] = ic;
    }
    else if (isdigit(ic)) {
      nums[pos++] = ic;
    }
    else if (pos == 0 && isblank(ic)) {
      continue;
    }
    else {
      break;
    }
  }

  if (strlen(nums) > 0) {
    sscanf(nums, "%d", &value);
  }

  printf("  input string size: %zu\n  input string: \"%s\"\n  integer value: %d [%#010x]\n", strlen(nums), nums, value, value);

  return 0;
}
