
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cctype>

using namespace std::literals::string_literals;

int main() {
  auto const playlist = std::vector {
    "addicted"s,  "battery"s, "cold"s,  "demons"s,    "epic"s,  "everlong"s,
    "fuel"s,      "given"s,   "halo"s,  "immortals"s, "jaded"s, "jars"s,
  };

  auto ans { 'N' };

  std::cout << "Playlist:\n";
  std::for_each(playlist.cbegin(), playlist.cend(), [](auto pl) {
    std::cout << pl << ' ';
  });
  std::cout << '\n' << "playlist size: " << playlist.size() << '\n';

  auto songTitle { ""s };

  do {
    std::cout << "Enter a song title: \n";
    std::getline(std::cin, songTitle);
    std::cout << std::endl;
    std::cout << "Searching for: "<< std::quoted(songTitle) << '\n' << std::endl;
    auto const find_it = std::find(playlist.cbegin(), playlist.cend(), songTitle);

    if (find_it != playlist.end()) {
      auto const element = std::distance(playlist.cbegin(), find_it);
      std::cout << "Song " << std::quoted(songTitle) << " found. Element #: "
                << element + 1 << std::endl;
    }
    else {
      std::cout << "Song " << std::quoted(songTitle) << " not found." << std::endl;
    }

    std::cout << "Would you like to search again? \n";
    std::cin >> ans;
    std::cin.ignore();
  } while (std::toupper(ans) == 'Y');

  return 0;
}
