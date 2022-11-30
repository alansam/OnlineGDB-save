#include <iostream>
#include <string>

class Vigenere {
private:
  std::string key;

public:
  Vigenere() = delete;
  Vigenere(Vigenere const &) = delete;
  Vigenere(Vigenere &&) = delete;
  Vigenere(std::string key) {
    for (size_t i = 0; i < key.size(); ++i) {
      if (key[i] >= 'A' && key[i] <= 'Z') {
        this->key += key[i];
      }
      else if (key[i] >= 'a' && key[i] <= 'z') {
        this->key += key[i] + 'A' - 'a';
      }
    }
  }
  Vigenere & operator=(Vigenere const &) = delete;
  Vigenere & operator=(Vigenere &&) = delete;

  std::string encrypt(std::string text) {
    std::string out;

    for (size_t i = 0, j = 0; i < text.length(); ++i) {
      char c = text[i];
      
      if (c >= 'a' && c <= 'z') {
        c += 'A' - 'a';
      }
      else if (c < 'A' || c > 'Z') {
        continue;
      }

      out += (c + key[j] - 2 * 'A') % 26 + 'A'; 
      j = (j + 1) % key.length();
    }

    return out;
  }

  std::string decrypt(std::string text) {
    std::string out;

    for (size_t i = 0, j = 0; i < text.length(); ++i) {
      char c = text[i];
      
      if (c >= 'a' && c <= 'z') {
        c += 'A' - 'a';
      }
      else if (c < 'A' || c > 'Z') {
        continue;
      }

      out += (c - key[j] + 26) % 26 + 'A'; 
      j = (j + 1) % key.length();
    }

    return out;
  }
};

int main(int argc, char const * argv[]) {
  Vigenere cipher("VIGENERECIPHER");

  std::string original  = "Beware the Jabberwock, my son! The jaws that bite, the claws that catch!";
  std::string encrypted = cipher.encrypt(original);
  std::string decrypted = cipher.decrypt(encrypted);

  std::cout << original << std::endl;
  std::cout << "Encrypted: " << encrypted << std::endl;
  std::cout << "Decrypted: " << decrypted << std::endl;
}
