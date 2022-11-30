/*
 *  Hello 
 *  I'm trying to work my search map algorithm 
 *  But it's doesn't give me true answer 
 *  Any can check 
 */

// /////////////////////////////////////////////////////////////////////// //
//                           my c++ map                                    //
//                     i'm trying to create my own map                     //
// /////////////////////////////////////////////////////////////////////// //      

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

#include "Village.hpp"

using namespace std::literals::string_literals;

void seek_find(std::vector<Village> const &,
               std::string const &);
void seek_copy(std::vector<Village> const &,
               std::string const &);
void seek_each(std::vector<Village> const &,
               std::string const &);
void seek_loop(std::vector<Village> const &,
               std::string const &);
void operator_logic(std::vector<Village> const &);

int main(int argc, char const * argv[]) {
  std::cout << "FarOnerlookedArchive"s
            << std::endl;

  auto villages = std::vector<Village> {
    { "C1"s, "P1"s, "D1"s, "S1"s, "L1"s, "V1"s, },
    { "C1"s, "P1"s, "D1"s, "S1"s, "L1"s, "V2"s, },
    { "C2"s, "P1"s, "D1"s, "S1"s, "L1"s, "V1"s, },
    { "C7"s, "P1"s, "D1"s, "S1"s, "L1"s, "V5"s, },
  };

  villages.push_back({ "C2"s, "P1"s, "D1"s, "S2"s, "L1"s, "V3"s, });

  {
    auto vt = Village("C1"s, "P1"s, "D3"s, "S1"s, "L1"s, "V1"s);
    std::clog << ".\n";
    villages.push_back(vt);
    vt.cell("L3"s);
    vt.village("V3"s);
    std::clog << ".\n"s;
    villages.push_back(vt);
    auto vu = Village();
    vt.village("V4"s);
    vu = vt;
    std::clog << ".\n"s;
    villages.push_back(vu);
  }
  std::cout.put('\n');

  {
    auto vt = std::move(Village("C6"s, "P5"s, "D4"s, "S3"s, "L2"s, "V1"s));
    villages.push_back(vt);
    vt = std::move(Village({ "C6"s, "P5"s, "D4"s, "S3"s, "L2"s, "V2"s, }));
    villages.push_back(vt);
    vt = std::move(Village("C6"s, "P5"s, "D4"s, "S3"s, "L2"s, "V3"s));
    villages.push_back(vt);
    vt.village("V4"s);
    auto vu = Village(std::move(vt));
    villages.push_back(vu);
  }
  std::cout.put('\n');

  auto show = [](auto const & villages) {
    for (auto vc { 0ul }; auto & ville : villages) {
      std::cout << "Village"s
                << std::setw(3)
                << ++vc << ": "s
                << ville
                << std::endl;
    }
  };

  std::cout.put('\n');
  std::cout.put('\n');

  std::cout << std::string(80, '=')
            << std::endl;
  show(villages);
  std::cout.put('\n');
  std::cout << std::string(80, '~')
            << std::endl;
  std::sort(villages.begin(), villages.end());
  show(villages);
  std::cout.put('\n');
  std::cout << std::string(80, '=')
            << std::endl;
  std::cout << std::endl;

  seek_find(villages, "V4"s);
  std::cout << std::endl;

  seek_copy(villages, "V3"s);
  std::cout << std::endl;

  seek_each(villages, "V1"s);
  std::cout << std::endl;

  seek_loop(villages, "V5"s);
  std::cout << std::endl;

  operator_logic(villages);
  std::cout << std::endl;

  return 0;
}

void seek_find(std::vector<Village> const & villages,
              std::string const & seek) {
  std::cout << "In "s << __func__
            << "(std::vector<Village> const &, std::string const &)\n"s;
  auto ville = [&seek](Village const & v_) {    
     return (v_.village() == seek);
  };

  auto fi = std::find_if(villages.cbegin(),
                         villages.cend(),
                         ville);

 std::cout << "village "s
            << std::quoted(seek)
            << " found in:\n"s;
   while (fi != villages.cend()) {
    std::cout << *fi << '\n';
    fi = std::find_if(std::next(fi),
                      villages.cend(),
                      ville);
  }
  std::cout << std::endl;  
}

void seek_copy(std::vector<Village> const & villages,
               std::string const & seek) {
  std::cout << "In "s << __func__
            << "(std::vector<Village> const &, std::string const &)\n"s;
  auto ville = [&seek](Village const & v_) {    
     return (v_.village() == seek);
  };

  auto cpy = std::vector<Village>();
  std::copy_if(villages.cbegin(),
               villages.cend(),
               std::back_inserter(cpy),
               ville);

  std::cout << "village "s
            << std::quoted(seek)
            << " found in:\n"s;
  std::for_each(cpy.cbegin(),
                cpy.cend(),
                [](auto const & v_) {
    std::cout << v_ << '\n';
  });
  std::cout << std::endl;  
}

void seek_each(std::vector<Village> const & villages,
               std::string const & seek) {
  std::cout << "In "s << __func__
            << "(std::vector<Village> const &, std::string const &)\n"s;

  std::cout << "village "s
            << std::quoted(seek)
            << " found in:\n"s;
  std::for_each(villages.cbegin(),
                villages.cend(),
                [&seek](auto const & v_) {
    if (v_.village() == seek) {
      std::cout << v_ << '\n';
    }
  });
  std::cout << std::endl;
}

void seek_loop(std::vector<Village> const & villages,
               std::string const & seek) {
  std::cout << "In "s << __func__
            << "(std::vector<Village> const &, std::string const &)\n"s;

  std::cout << "village "s
            << std::quoted(seek)
            << " found in:\n"s;
  for (auto const & v_ : villages) {
    if (v_.village() == seek) {
      std::cout << v_ << '\n';
    }
  }
  std::cout << std::endl;
}

void operator_logic(std::vector<Village> const & villages) {
  std::cout << "In "s << __func__
            << "(std::vector<Village> const &)\n"s;

  std::cout << std::string(80, '.')
            << std::endl;
  std::cout << std::boolalpha;
  std::clog << "?\n"s;
  std::cout << "[0]: "s << villages[0] << '\n'
            << "[1]: "s << villages[1] << '\n';
  std::clog << "?\n"s;
  std::cout << "[0] == [1]: "s
            << (villages[0] == villages[1]) << '\n';
  std::clog << "?\n"s;
  std::cout << "[1] == [0]: "s
            << (villages[1] == villages[0]) << '\n';
  std::clog << "?\n"s;
  std::cout << "[0] == [0]: "s
            << (villages[0] == villages[0]) << '\n';
  std::cout.put('\n');
  std::clog << "?\n"s;
  std::cout << "[0] != [1]: "s
            << (villages[0] != villages[1]) << '\n';
  std::clog << "?\n"s;
  std::cout << "[1] != [0]: "s
            << (villages[1] != villages[0]) << '\n';
  std::clog << "?\n"s;
  std::cout << "[0] != [0]: "s
            << (villages[0] != villages[0]) << '\n';
  std::cout.put('\n');
  std::clog << "?\n"s;
  std::cout << "[0] <  [1]: "s
            << (villages[0] <  villages[1]) << '\n';
  std::clog << "?\n"s;
  std::cout << "[1] <  [0]: "s
            << (villages[1] <  villages[0]) << '\n';
  std::clog << "?\n"s;
  std::cout << "[0] <  [0]: "s
            << (villages[0] <  villages[0]) << '\n';
  std::cout.put('\n');
  std::clog << "?\n"s;
  std::cout << "[0] >  [1]: "s
            << (villages[0] >  villages[1]) << '\n';
  std::clog << "?\n"s;
  std::cout << "[1] >  [0]: "s
            << (villages[1] >  villages[0]) << '\n';
  std::clog << "?\n"s;
  std::cout << "[0] >  [0]: "s
            << (villages[0] >  villages[0]) << '\n';
  std::cout.put('\n');
  std::clog << "?\n"s;
  std::cout << "[0] <= [1]: "s
            << (villages[0] <= villages[1]) << '\n';
  std::clog << "?\n"s;
  std::cout << "[1] <= [0]: "s
            << (villages[1] <= villages[0]) << '\n';
  std::clog << "?\n"s;
  std::cout << "[0] <= [0]: "s
            << (villages[0] <= villages[0]) << '\n';
  std::cout.put('\n');
  std::clog << "?\n"s;
  std::cout << "[0] >= [1]: "s
            << (villages[0] >= villages[1]) << '\n';
  std::clog << "?\n"s;
  std::cout << "[1] >= [0]: "s
            << (villages[1] >= villages[0]) << '\n';
  std::clog << "?\n"s;
  std::cout << "[0] >= [0]: "s
            << (villages[0] >= villages[0]) << '\n';
  std::cout << std::string(80, '.')
            << std::endl;
  std::cout.put('\n');
}
