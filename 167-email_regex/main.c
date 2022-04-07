//  MARK: - Reference.
//  @see: https://stackoverflow.com/questions/201323/how-can-i-validate-an-email-address-using-a-regular-expression
//  @see: http://www.ex-parrot.com/~pdw/Mail-RFC822-Address.html
//  @see: https://man7.org/linux/man-pages/man3/regcomp.3.html

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>
#include <stdint.h>

#define MANPAGE_

typedef struct rexp rexp;
struct rexp {
  char const * nickname;
  char const * pattern;
};

//  MARK: - Definitions
bool is_email01(char const * email, rexp const * rpatt);
#ifdef TODO_MANPAGE_
int manpage_sample(void);
#endif

//  MARK: - Implementation
/*
 *  MARK: main()
 */
int main() {
  char const * emails[] = {
    "bobby@billy.com",
    "bobby.billy@billy.co.uk",
    "bobby @ billy.com",
    "bobby@billy",
    "bobby@billy.",
    "bobby@.com",
    "bobby",
  };
  size_t const emails_l = sizeof(emails) / sizeof(*emails);


  {
    //  TODO: choose a pattern
#define TODO_SIMPLES_ASP_
#if defined(TODO_SIMPLES_SP_)
    //    SIMPLE1     ^\S+@\S+\.\S+$
    char const pname[] = "SIMPLEPOSIX";
    char const pattern[] = "^[^[:space:]]+@[^[:space:]]+\\.[^[:space:]]+$";
#elif defined(TODO_SIMPLES_ASP_)
    //    ASP.NET     ^\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$
    char const pname[] = "ASP.NETPOSX";
    char const pattern[] = "^[[:alnum:]]+([-+.'][[:alnum:]]+)*@[[:alnum:]]+([-.][[:alnum:]]+)*\\.[[:alnum:]]+([-.][[:alnum:]]+)*$";
#else
    char const pname[] = "SIMPLES";
    char const pattern[] = "^\\S+@\\S+\\.\\S+$";
#endif

    rexp psimp = {
      .nickname = pname,
      .pattern = pattern,
    };
    for (size_t e_ = 0; e_ < emails_l; ++e_) {
      char const * email = emails[e_];
      if (is_email01(email, &psimp)) {
        printf("%s is a valid email address\n", email);
      }
      else {
        printf("%s is not a valid email address\n", email);
      }
      putchar('\n');
    }

  }

#ifdef TODO_MANPAGE_
  manpage_sample();
#endif

  return 0;
}

/*
 *  MARK: is_email01()
 */
bool is_email01(char const * email, rexp const * rpatt) {
  printf("In function %s()\n", __func__);
  bool is_email = false;
  printf("email address: %s\n", email);
  printf("regular expression:\n  nickname: %s\n  pattern: %s\n", rpatt->nickname, rpatt->pattern);

  char const * es = email;
  regex_t     regex;

  if (regcomp(&regex, rpatt->pattern, REG_EXTENDED | REG_NOSUB)) {
    fprintf(stderr, "regexp pattern did not compiile: %s\n", rpatt->pattern);
    exit(EXIT_FAILURE);
  }

  int rexres = regexec(&regex, es, 0, NULL, 0);
  if (rexres != REG_NOMATCH) {
    is_email = true;
  }
  else {
    is_email = false;
  }

  regfree(&regex);

  putchar('\n');

  return is_email;
}

//  MARK: - Manpage sample

#ifdef TODO_MANPAGE_
#define ARRAY_SIZE(arr) (sizeof((arr)) / sizeof((arr)[0]))

static const char *const str = "1) John Driverhacker;\n2) John Doe;\n3) John Foo;\n";
static const char *const re = "John.*o";

/*
 *  MARK: manpage_sample()
 */
int manpage_sample(void) {
  printf("In function %s()\n", __func__);
  static const char *s = str;
  regex_t     regex;
  regmatch_t  pmatch[1];
  regoff_t    off, len;

  if (regcomp(&regex, re, REG_NEWLINE))
    exit(EXIT_FAILURE);

  printf("String = \"%s\"\n", str);
  printf("Matches:\n");

  for (int i = 0; ; i++) {
    if (regexec(&regex, s, ARRAY_SIZE(pmatch), pmatch, 0))
      break;

    off = pmatch[0].rm_so + (s - str);
    len = pmatch[0].rm_eo - pmatch[0].rm_so;
    printf("#%d:\n", i);
    printf("offset = %jd; length = %jd\n", (intmax_t) off, (intmax_t) len);
    printf("substring = \"%.*s\"\n", len, s + pmatch[0].rm_so);
  
    s += pmatch[0].rm_eo;
  }

   exit(EXIT_SUCCESS);
}
#endif

