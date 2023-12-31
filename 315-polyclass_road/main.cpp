#define VECTORIZE_

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <limits>
#ifdef VECTORIZE_
#include <vector>
#include <memory>

class Road;
typedef std::shared_ptr<Road> PRoad;
#endif

using namespace std::literals::string_literals;

enum class Currency : size_t { USD, GBP, Euro, };
enum class Speed : size_t { MPH, KPH, };

std::string const currency[] { "\u0024"s, "\u00a3"s, "\u20ac"s, };
int const currency_prec[] { 2, 2, 2, };
std::string const speed[] { "MPH"s, "km/h"s, };
int const speed_max[] { 100, 160, };

auto const CURRENCY { currency[static_cast<size_t>(Currency::Euro)] };
auto const CURRENCY_PREC { currency_prec[static_cast<size_t>(Currency::Euro)] };
auto const SPEED { speed[static_cast<size_t>(Speed::KPH)] };
auto const SPEED_MAX { speed_max[static_cast<size_t>(Speed::KPH)] };

// This is the Base class - Road
class Road {
private:
  std::string name;
  int numLanes;
  int speedLimit;

public:

  // This is the Constructor
  Road(std::string name = ""s, int numLanes = 0, int speedLimit = 0)
  : name { name }, numLanes { numLanes }, speedLimit { speedLimit } {
    // setName(name); // this is the Setname using setter function
    // setNumLanes(numLanes); // This will Set number of lanes using setter function
    // setSpeedLimit(speedLimit); // This will Set Speed limit using setter function
  }
  Road(Road const & that) = default;
  Road(Road && that) = default;
  virtual
  ~Road() = default;
  Road & operator=(Road const & that) = default;
  Road & operator=(Road && that) = default;

  // These are the Accessors and Mutators (Gets and Sets)

  void setName(std::string name) {
    this->name = name; // This will Set the name of the road
  }

  std::string getName() const {
    return name;    // This will Get the name of the road
  }

  // This will set the NUmber of lanes
  void setNumLanes(int numLanes) {

    // This is used for the Input Validation: number of lanes should be greater than 0
    if (numLanes > 0) {
      this->numLanes = numLanes;      // This will Set the number of lanes of the road
    }
    else {
      std::cout << "Error: Number of lanes must be greater than 0\n"s; // This will Display error message for invalid input
    }
  }

  int getNumLanes() const {
    return numLanes; // This will Get the number of lanes of the road
  }

  // This is used for the Speed Limit
  void setSpeedLimit(int speedLimit) {
  
    // This is used for the input validation: speed limit should be between 0 to 100
    if (speedLimit >= 0 && speedLimit <= SPEED_MAX) {
      this->speedLimit = speedLimit; // this will set the speed limit of the road
    }
    else {
      std::cout << "Error: Speed Limit should be between 0 to "s << SPEED_MAX << '\n'; // Display error message for invalid input
    }
  }

  int getSpeedLimit() const {
    return speedLimit; // This will Get the speed limit of the road
  }

  // This is the Display function
  virtual
  void display() const {
    // std::cout << getName() << " is a standard road with "
    //           << getNumLanes() << " lanes and a max permissible speed of "
    //           << getSpeedLimit() << ' ' << SPEED
    //           << ".\n"; // Display the roads name, number of lanes, and speed limit
    std::cout << toString() << '\n';
  }

  virtual
  std::string toString() const {
    std::ostringstream out;
    out << getName() << " is a standard road with "s
        << getNumLanes() << " lanes and a max permissible speed of "s
        << getSpeedLimit() << ' ' << SPEED
        << "."s;
    return out.str();
  }

  friend
  std::ostream & operator<<(std::ostream & os, Road const & that) {
    os << that.toString();
    return os;
  }
};

// This is used for the Derived class - TollRoad
class TollRoad : public Road {
private:
  double toll;

public:

  // This is used for the constructor
  TollRoad(std::string name = ""s, int numLanes = 0, int speedLimit = 0, double toll = 0.0)
  : Road(name, numLanes, speedLimit), toll { toll } {
    // setToll(toll); // This will Set toll using setter function
  }
  TollRoad(TollRoad const & that) = default;
  TollRoad(TollRoad && that) = default;
  virtual
  ~TollRoad() = default;
  TollRoad & operator=(TollRoad const & that) = default;
  TollRoad & operator=(TollRoad && that) = default;

  // This is used for the Accessors and Mutators (Gets and Sets)
  // Toll
  void setToll(double toll) {

    // This is used for the input validation toll should be greater than 0
    if (toll > 0) {
      this->toll = toll; // This will set the toll of the toll road
    }
    else {
      std::cout << "Error: Toll must be greater than 0\n"s; // Display error message for invalid input
    }
  }

  double getToll() const {
    return toll; // This will Get the toll of the toll road
  }

  // This is used for the Overridden display function
  // void display() const {
  //   std::cout << getName() << " is a toll road with "
  //             << getNumLanes() << " lanes, and a max permissible speed of "
  //             << getSpeedLimit() << ' ' << SPEED
  //             << ". The current toll to use "
  //             << getName() << " is " << CURRENCY
  //             << getToll() << ".\n";
  // }

  std::string toString() const {
    std::ostringstream out;
    out << std::fixed << std::setprecision(CURRENCY_PREC);
    out << getName() << " is a toll road with "s
        << getNumLanes() << " lanes and a max permissible speed of "s
        << getSpeedLimit() << ' ' << SPEED
        << ". The current toll to use "s
        << getName() << " is "s << CURRENCY
        << getToll()
        << "."s;
    return out.str();
  }
};

//  MARK: main()
int main(int argc, char const * argv[]) {

  // Initializing roads array
#ifdef VECTORIZE_
  std::vector<PRoad> roads;
#else
  Road * roads[10];
  auto index { 0ul };
#endif

  int menuOption;
  do {
    // Display Main Menu
    std::cout << "Main Menu\n"s;
    std::cout<<  "  1) Add a new Road\n"s;
    std::cout << "  2) View current Roads\n"s;
    std::cout << "  3) Exit Program\n"s;
    std::cout << ">> "s;
    std::cin >> menuOption;
    std::cout << menuOption << '\n' << std::endl;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (menuOption)
    {
      // Add a new Road
      case 1: {
        std::cout << "Registering a new road...\n"s;

        std::string name;
        int numLanes;
        int speedLimit;
        char isTollRoad;
        double toll;

        std::cout << "Enter the road's name: "s;
        // cin >> name;
        std::getline(std::cin, name);
        std::cout << " > "s << name << '\n';

        std::cout << "How many lanes does "s << name << " have? "s;
        std::cin >> numLanes;
        std::cout << " > "s << numLanes << '\n';

        std::cout << "What is the maximum speed limit (in "s << SPEED << ") for "s
                  << name << "? "s;
        std::cin >> speedLimit;
        std::cout << " > "s << speedLimit << '\n';

        std::cout << "Is "s << name << " a toll road? (Y/N) "s;
        std::cin >> isTollRoad;
        std::cout << " > "s << isTollRoad << '\n';

        // If road is toll road
        if (isTollRoad == 'Y' || isTollRoad == 'y') {
          std::cout << "enter the standard toll for use of "s << name << ": "s;
          std::cin >> toll;
          std::cout << " > "s << toll << '\n';
#ifdef VECTORIZE_
          roads.emplace_back(std::make_shared<TollRoad>(name, numLanes, speedLimit, toll));
#else
          roads[index++] = new TollRoad(name, numLanes, speedLimit, toll);
#endif
        }
        else {
#ifdef VECTORIZE_
          roads.emplace_back(std::make_shared<Road>(name, numLanes, speedLimit));
#else
          roads[index++] = new Road(name, numLanes, speedLimit);
#endif
        }
        std::cout << name << " has been successfully added.\n\n"s;
        break;
      }

      // View current Roads
      case 2: {
        std::cout << "Listing current roads...\n"s;
#ifdef VECTORIZE_
        for (auto const & road : roads) {
          // road.display();
          std::cout << *road << '\n';
        }
#else
        for (auto i_ = 0ul; i_ < index; i_++) {
          std::cout << roads[i_]->toString() << '\n';
        }
#endif
        std::cout << std::endl;
        break;
      }

      // Exit Program
      case 3: {
        std::cout << "Exiting Program...\n"s;
        break;
      }

      default: {
        std::cout << "Invalid input. Please enter a valid option from the menu.\n"s;
        break;
      }
    }
  } while (menuOption != 3);

  std::cout << std::endl;

#ifndef VECTORIZE_
  for (auto d_ { 0ul }; d_ < index; ++d_) {
    delete roads[d_];
  }
#endif

  return 0;
}

/*
Compiler options:
-Wall -Wpedantic -std=gnu++2b -fsanitize=address

Sample input:
1
New Road
2
40
N
1
New Parkway
8
80
Y
2.56
1
New Motorway
6
70
n
2
3
*/
