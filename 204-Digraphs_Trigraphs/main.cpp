//  @see: https://en.cppreference.com/w/cpp/language/operator_alternative
// g++ compiler flags: -Wall -trigraphs -Wno-trigraphs

%:include <iostream>

int main() <%
  std::cout << "Hello World.??/n";
  putchar(0x0a);

  printf("Hi%c", 0x0a);
  putchar(0x0a);

  std::cout << std::endl;

  return 0;
%>
