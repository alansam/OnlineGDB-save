
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>

void old_style(void);
void new_style_vector(void);
void new_style_vector_simpler(void);
void new_style_chars(void);
void new_style_string(void);

int main() {
  
  old_style();
  new_style_vector();
  new_style_string();
  new_style_vector_simpler();
  new_style_chars();

  return 0;
}

void old_style(void) {
#define BUF_SZ 24
  char buffer[BUF_SZ] = { '\0', };
  char ic;
  size_t cc = 0;
  printf("Wut?\n");
  while (((ic = getchar()) != '\n') && cc < BUF_SZ - 1) {
    buffer[cc++] = ic;
  }
  printf("%s\n", buffer);
}

void new_style_vector(void) {
  char xx;
  while ((xx = ::getchar()) != '\n');
  size_t constexpr buff_sz(24);
  std::vector<char> buffer(buff_sz);
  std::cout << "Wut?\n";
  size_t cc(0);
  bool eol(false);
  std::transform(buffer.begin(), buffer.end(), buffer.begin(), [&](auto n_) {
    char ic;
    if (!eol) {
      std::cin.get(ic);
      if (cc++ > buff_sz - 1 || ic == '\n') {
        eol = true;
        ic = '\0';
      }
    }
    return ic;
  });
  buffer[buff_sz - 1] = '\0';
  std::cout << buffer.size() << '\n' << buffer.data() << '\0' << std::endl;
  while ((xx = ::getchar()) != '\n');
}

void new_style_vector_simpler(void) {
  char xx;
  while ((xx = ::getchar()) != '\n');
  size_t constexpr buff_sz(24);
  std::vector<char> buffer(buff_sz);
  std::cout << "Wut?\n";
  size_t cc(0);
  bool eol(false);
  do {
    char ic;
    std::cin.get(ic);

    if (ic == '\n') {
      eol = true;
      continue;
    }

    buffer[cc++] = ic;

    if (cc == buff_sz) {
      eol = true;
      continue;
    }
  } while (!eol);
  buffer[buff_sz - 1] = '\0';
  std::cout << buffer.size() << '\n' << buffer.data() << '\0' << std::endl;
  while ((xx = ::getchar()) != '\n');
  
}


void new_style_string(void) {
  char xx;
  while ((xx = ::getchar()) != '\n');
  size_t constexpr buff_sz(24);
  std::string buffer("", buff_sz);
  std::cout << "Wut?\n";
  size_t cc(0);
  bool eol(false);
  std::transform(buffer.begin(), buffer.end(), buffer.begin(), [&](auto n_) {
    char ic;
    if (!eol) {
      std::cin.get(ic);
      if (cc++ > buff_sz - 1 || ic == '\n') {
        eol = true;
        ic = '\0';
      }
    }
    return ic;
  });
  std::cout << buffer.size() << '\n' << buffer << std::endl;
  while ((xx = ::getchar()) != '\n');
}

void new_style_chars(void) {
  char xx;
  while ((xx = ::getchar()) != '\n');
  size_t constexpr buff_sz(24);
  char buffer[buff_sz];
  std::cout << "Wut?\n";
  std::cin.get(buffer, buff_sz);
  std::cout << std::strlen(buffer) << '\n' << buffer << std::endl;
  while ((xx = ::getchar()) != '\n');
}
