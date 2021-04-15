
#include <iostream>
#include <string>

void                f0()                      { std::cout << "void" << std::endl; return; }
bool                f1(bool r)                { std::cout << r << std::endl; return r; }
int                 f2(int r)                 { std::cout << r << std::endl; return r; }
float               f3(float r)               { std::cout << r << std::endl; return r; }
char const *        f4(char const * r)        { std::cout << (r != NULL ? r : "NULL") << std::endl; return r; }
std::string const & f5(std::string const & r) { std::cout << r << std::endl; return r; }
int const &         f6(int const & r)         { std::cout << r << std::endl; return r; }
void *              f7(void * r)              { std::cout << r << std::endl; return r; }

void report(char const * s) { std::cout << s << std::endl; return; }

int main() {

//  if (f0())                 { report("f0() - true"); }             else { report("f0() - false"); }
  if (f1(true))             { report("f1(true) - true"); }         else { report("f1(true) - false"); }
  if (f1(false))            { report("f1(false) - true"); }        else { report("f1(false) - false"); }
  if (f2(1))                { report("f2(1) - true"); }            else { report("f2(1) - false"); }
  if (f2(0))                { report("f2(0) - true"); }            else { report("f2(0) - false"); }
  if (f3(1.0f))             { report("f3(1.0f) - true"); }         else { report("f3(1.0f) - false"); }
  if (f3(0.0f))             { report("f3(0.0f) - true"); }         else { report("f3(0.0f) - false"); }
  if (f4("hello"))          { report("f4(\"hello\") - true"); }    else { report("f4(\"hello\") - false"); }
  if (f4(NULL))             { report("f4(NULL) - true"); }         else { report("f4(NULL) - false"); }
  if (f5("hello").length()) { report("f5(\"hello\") - true"); }    else { report("f5(\"hello\") - false"); }
  if (f5("").length())      { report("f5(\"\") - true"); }         else { report("f5(\"\") - false"); }
  if (f6(1))                { report("f6(1) - true"); }            else { report("f6(1) - false"); }
  if (f6(0))                { report("f6(0) - true"); }            else { report("f6(0) - false"); }
  if (f7((void *) &f7))     { report("f7((void *) &f7) - true"); } else { report("f7(&f7) - false"); }
  if (f7(NULL))             { report("f7(NULL) - true"); }         else { report("f7(NULL) - false"); }

  return 0;
}

