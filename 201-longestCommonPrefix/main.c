
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char * longestCommonPrefix(char ** strs, int strsSize);
char const * longestCommonPrefix_ModernC(size_t const strsSize, char const * strs[strsSize]);

/*
 *  MARK: drive_sample()
 */
static
inline
void drive_sample(size_t sz, char const * smp[sz]) {
  printf("%zu: ", sz);
  for (size_t s_ = 0; s_ < sz; ++s_) {
    if (smp[s_] == NULL) {
      continue;
    }
    printf("'%s' ", smp[s_]);
  }
  putchar('\n');

  printf("longestCommonPrefix:         \"%s\"\n", longestCommonPrefix((char **) smp, sz));
  printf("longestCommonPrefix_ModernC: \"%s\"\n", longestCommonPrefix_ModernC(sz, smp));
  putchar('\n');
}

static
bool debug = false;

/*
 * Program entry point.
 */
int main(int argc, char const * argv[]) {
  char const * spl[] = {
    "ab",
    "a",
  };
  size_t const spl_sz = sizeof(spl) / sizeof(*spl);

  char const * aas[] = {
    [3] = "aardvark",
    [5] = "aaron",
    [1] = "aachen",
    [2] = "aalborg",
    [4] = "aarhus",
    [0] = "aaa",
  };
  size_t const aas_sz = sizeof(aas) / sizeof(*aas);

  char const * als[] = {
    [7] = "always",
    [4] = "almost",
    [1] = "allow",
    [0] = "align",
    [3] = "aloft",
    [2] = "allsorts",
    [6] = "aluminium",
    [5] = "altitude",
    [8] = "attitude",
    [9] = "ant",
  };
  size_t const als_sz = sizeof(als) / sizeof(*als);

  drive_sample(spl_sz, spl);
  drive_sample(aas_sz, aas);
  debug = true;
  drive_sample(als_sz, als);

  return 0;
}

/*
 *  MARK: longestCommonPrefix_ModernC()
 */
char const * longestCommonPrefix_ModernC(size_t const strsSize, char const * strs[strsSize]) {
  if (strsSize == 1) {
    return strs[0];
  }
  else {
    size_t check = 1; 
    for (size_t i = 1; i < strsSize; i++) {
      if (strs[0][0] == strs[i][0]) {
        check++;
      }
    }
    if (debug) {
      printf("%zu, %zu\n", strsSize, check);
    }

    if (check == strsSize) {
      static char retStr[100] = { '\0', };
      size_t sameStrPos = 0;

      for (size_t i = 1; i < strsSize; i++) {
        size_t strsElemSize = strlen(strs[i]);
        for (size_t j = 0; j < strsElemSize; j++) {
          if (strs[0][j] != strs[i][j] || j == strsElemSize - 1) {
            if (j == 0) {
              sameStrPos = j + 1;
              break;
            }
            else {
              sameStrPos = j;
              break;
            }
          }
        }
      }

      if (sameStrPos != 0) {
        for (size_t i = 0; i < sameStrPos; i++) {
          retStr[i] = strs[0][i];
        }
        return retStr;
      }
      else {
        return "";  
      }
    }
    else if (check != strsSize) {
      return "";
    }
  }

  return "";
}

/*
 *  MARK: longestCommonPrefix()
 */
char *longestCommonPrefix(char **strs, int strsSize) {
    if (strsSize == 1) {
        return strs[0];
    }
    else {
        unsigned int check = 1; 
        for (int i = 0; i < strsSize - 1; i++) {
            if (strs[0][0] == strs[i + 1][0]) {
                check++;
            }
        }
        if (check == strsSize) {
            static char retStr[100] = {'\0'};
            int sameStrPos = 0;
            for (int i = 0; i < strsSize - 1; i++) {
                int strsElemSize = strlen(strs[i + 1]);
                for (int j = 0; j < strsElemSize; j++) {
                    if (strs[0][j] != strs[i + 1][j] || j == strsElemSize - 1) {
                        if (j == 0) {
                            sameStrPos = j + 1;
                            break;
                        }
                        else {
                            sameStrPos = j;
                            break;
                        }
                    }
                }
            }
            if (sameStrPos != 0) {
                for (int i = 0; i < sameStrPos; i++) {
                    retStr[i] = strs[0][i];
                }
                return retStr;
            }
            else {
                return "";  
            }
        }
        else if (check != strsSize) {
            return "";
        }
    }
    return "";
}
