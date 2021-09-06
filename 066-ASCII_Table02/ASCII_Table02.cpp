// Naeson_GS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Microsoft Visual Studio Community 2019 version 16.9.4
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <locale>
#include <codecvt>
#include <cctype>

//using namespace std;

//  Hendle control and escape characters
auto ascii = [](char chr) {
  std::ostringstream subst;
  if (iscntrl(chr)) {
    switch(chr) {
      case 0x09:
        subst << "\\t";
        break;
      case 0x0a:
        subst << "\\n";
        break;
      case 0x0b:
        subst << "\\v";
        break;
      case 0x0c:
        subst << "\\f";
        break;
      case 0x0d:
        subst << "\\r";
        break;
      default:
        subst << "0x" << std::setfill('0') << std::setw(2) << std::hex << static_cast<int>(chr) << std::dec << std::setfill(' ');
        break;
    }
  }
  else {
    subst << chr;
  }

  return subst.str();
};

int main() {
  // http://www.asciitable.com/
  // Simple program does not filter out non-viewable characters
  // Does not attempt to display as shown in ASCII table
  //The line feed character causes a break to a new line
  //The backspace also really backspaces
  //Expect to hear the bell character to sound something on you computer
  // esc character is doing something....
  // Also this code will not work for a GUI as GUI uses unicode

  std::cout << "Program to print ASCII characters.\n";
  for (uint8_t iCharValue = 0, lb = 0; iCharValue < 128; iCharValue++) {
    // to convert to a character, cast "(char)" to convert
    // to convert character to a number use toascii();
    std::cout << " Value: " << std::setw(3) << static_cast<int>(iCharValue)
              << ", 0x" << std::setw(2) << std::setfill('0') << std::hex << static_cast<uint16_t>(iCharValue) << std::dec << std::setfill(' ') << ' '
              << std::setw(4) << ascii(iCharValue)
              << (++lb % 3 == 0 ? "\n" : "");
  }

  //
  std::cout << "\n\nExtended ASCII\n";
  for (uint8_t iCharValue = 0x80, lb = 0; iCharValue <= 0xff; iCharValue++) {
    std::cout << " Value: " << std::setw(3) << static_cast<int>(iCharValue)
              << ", 0x" << std::setw(2) << std::setfill('0') << std::hex << static_cast<uint16_t>(iCharValue) << std::dec << std::setfill(' ') << ' '
              << std::setw(4) << iCharValue
              << (++lb % 3 == 0 ? "\n" : "");
    if (iCharValue == 0xff) break;
  }
  std::cout << std::endl;

  //  @see: https://stackoverflow.com/questions/20419605/how-to-convert-unicode-code-points-to-utf-8-in-c
  std::cout << "\n\nUnicode, Code points U+0080 to U+00FF\n";
  std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> converter;
  for (int16_t u = 0x80, lb = 0; u <= 0xff; ++u) {
    std::string u8str = '\'' + converter.to_bytes(u) + '\'';
    std::cout << " Value: " << std::setw(3) << u
              << ", 0x" << std::setw(2) << std::setfill('0') << std::hex << u << std::dec << std::setfill(' ') << ' '
              << std::setw(4) << u8str  << ' '
              << (++lb % 3 == 0 ? "\n" : "");
  }
  std::cout << std::endl;
}
