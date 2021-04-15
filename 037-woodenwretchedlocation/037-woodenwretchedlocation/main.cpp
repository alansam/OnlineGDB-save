#include <iostream>
#include <string> //  missing
// not used -> #include <cstdlib> // <- but should use C++ version

//using namespace std;  // this is a bad habit!

int main()
{
  std::string Items[6];
  for (int count = 1; count <= 5; count++) {
    std::cout << "Item " << count<<": ";
    std::cin >> Items[count];
  }
  std::cout << std::endl;

  double Qty[6];
  for (int count = 1; count <= 5; count++) {
    std::cout << "Quantity " << count << ": ";
    std::cin >> Qty[count];
  }
  std::cout << std::endl;

  float U_Price[6];
  for (int count = 1; count <= 5; count++) {
    std::cout << "Unit price " << count << ": ";
    std::cin >> U_Price[count];
  }
  std::cout << std::endl;

  double Costs[6];
  /* Let the computer calculate this:
  for (int count=1; count<=5; count++) {
    cout << "Cost " << count << ": ";
    cin >> Costs[count];
  }
  cout << endl;
  */
  for (size_t ic = 1; ic <=  5; ++ic) {
    Costs[ic] = Qty[ic] + U_Price[ic];
  }

  double Payment;
  std::cout << "Payment " << ": ";
  std::cin >> Payment;
  std::cout << "\n";
//  system("cls");  //  system specific
  std::cout << "                 Happy Mart" << std::endl;
  std::cout << "    518 T Pinpin Street 1000 & 092429836" << std::endl;
  std::cout << "\n";
  std::cout << "Items      ";
  std::cout << "Qty        ";
  std::cout << "U-price    ";
  std::cout << "Cost       " << '\n';
  std::cout << std::endl;

  for (int Numm = 1; Numm <= 5; Numm++) {
    std::cout << Numm << ". " << Items[Numm],
    std::cout << "        "   << Qty[Numm],
    std::cout << "        "   << U_Price[Numm],
    std::cout << "        "   << Costs[Numm] << std::endl;
  }

  //  Costs is an array
  //  you need to accumulate the costs into a scalar total.
  double tCost(0);
  for (auto cc : Costs) {
    tCost += cc;
  }
  
  //  endl cases a flush. Keep them to a minimum
  std::cout << "\n";
  std::cout << "Total                     " << tCost << '\n';
  std::cout << "Payment Recieved          " << Payment << '\n';
  std::cout << "Change                    " << Payment - tCost << '\n';
  std::cout << std::endl;

  return 0;
}
