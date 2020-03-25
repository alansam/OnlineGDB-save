
#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char const * argv[]) {

  // This:
  std::string thing("Things: ");
  thing += std::to_string(5) + " - " + std::to_string(2.5) + '.';
  std::cout << thing << std::endl;
  // Or:  
  std::ostringstream os("Just this: ");
  os << os.str() << "adding things - " << 55 << " - " << 555.5 << '.';
  std::cout << os.str() << std::endl;

  return 0;
}
