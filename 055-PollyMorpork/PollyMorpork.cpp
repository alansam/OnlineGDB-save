#include <iostream>

class person {
public:
  person() { std::cout << "constructor person \n\n"; }
  void greetings(){ std::cout << "Person says Hi \n"; }
  virtual void farewell(){ std::cout << "Person says Goodbye\n"; }
};

class employee : public person {
public:
  employee(): person() { std::cout << "constructor employee \n\n"; }
  void greetings(){ std::cout << "Employee says Hi \n"; }
  virtual void farewell(){ std::cout << "Employee says Goodbye\n"; }
};

int main() {
	employee e;
	std::cout << "...\n";
	person * p = &e;
	p->greetings();
	p->farewell();

	return 0;
}
