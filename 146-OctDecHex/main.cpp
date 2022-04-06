
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

int main() {
  int oval;
  std::cout << "data: ";
  std::cin >> std::oct >> oval;
  std::cout << std::endl;
  std::cout << std::oct << std::setw(8) << oval
            << std::dec << std::setw(8) << oval
            << std::hex << std::setw(8) << oval
            << std::endl; 

  oval = 0;

  std::string ostr;
  std::cout << "data: ";
  std::cin >> ostr;
  std::cout << std::endl;
  std::istringstream iss(ostr);
  iss >> std::oct >> oval;
  std::cout << std::oct << std::setw(8) << oval
            << std::dec << std::setw(8) << oval
            << std::hex << std::setw(8) << oval
            << std::endl;
}

