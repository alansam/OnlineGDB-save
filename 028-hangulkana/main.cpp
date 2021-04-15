
#include <stdio.h>

//  @see: https://www.compart.com/en/unicode/
//  @see: http://www.getnamein.com/korean/Alan
//  @see: http://www.getnamein.com/japanese/Alan
//  @see: http://www.getnamein.com/china/Alan
//  @see: http://www.getnamein.com/taiwan/Alan

//  Hangul Syllable Ael [U+C568, UTF-8 0xEC 0x95 0xA8] Hangul Syllable Reon [U+B7F0, UTF-8 0xEB 0x9F 0xB0]
char const alan_hangul[]  = "Alan | aelleon | 앨런   | \uC568\uB7F0   | \xEC\x95\xA8\xEB\x9F\xB0";
// katakana Katakana Letter A [U+30A2, UTF-8 0xE3 0x82 0xA2] Katakana Letter Ra [U+30E9, UTF-8 0xE3 0x83 0xA9] Katakana Letter N [U+30F3 UTF-8 0xE3 0x83 0xB3]
char const alan_kana[]    = "Alan | aran    | アラン | \u30A2\u30E9\u30F3 | \xE3\x82\xA2\xE3\x83\xA9\xE3\x83\xB3";
//  CJK Unified Ideograph-827E [U+827E UTF-8 0xE8 0x89 0xBE] CJK Unified Ideograph-4F26 [U+4F26 UTF-8 0xE4 0xBC 0xA6]
char const alan_chinese[] = "Alan | Ài lún  | 艾伦   | \u827E\u4F26  | \xE8\x89\xBE\xE4\xBC\xA6";
//  CJK Unified Ideograph-827E [U+827E UTF-8 0xE8 0x89 0xBE] CJK Unified Ideograph-502B [U+502B UTF-8 0xE5 0x80 0xAB]
char const alan_taiwan[]  = "Alan | Ài lún  | 艾倫   | \u827E\u502B  | \xE8\x89\xBE\xE5\x80\xAB";


int main() {
  printf("Hello %s\n", alan_hangul);
  printf("Hello %s\n", alan_kana);
  printf("Hello %s\n", alan_chinese);
  printf("Hello %s\n", alan_chinese);

  return 0;
}
