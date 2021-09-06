// Greeking: Γρεεκινγ
//  A B C D  E F G H  I J K L  M N O P  Q R S T  U V W X  Y Z
//  Α Β Ψ Δ  Ε Φ Γ Η  Ι Ξ Κ Λ  Μ Ν Ο Π  : Ρ Σ Τ  Θ Ω ΅ Χ  Υ Ζ
//  α β ψ δ  ε φ γ η  ι ξ κ λ  μ ν ο π  ; ρ σ τ  θ ω ς χ  υ ζ
//
//  Greek alphabet
//  Ελληνικο αλφαβητο
//  Α Β Γ Δ  Ε Ζ Η Θ  Ι Κ Λ Μ  Ν Ξ Ο Π  Ρ Σ Τ Υ  Φ Χ Ψ Ω
//  α β γ δ  ε ζ η θ  ι κ λ μ  ν ξ ο π  ρ σ τ υ  φ χ ψ ω
//  . . . .  . . . .  . . . .  . . . .  . ς . .  . . . .
//

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

//  Λ - IsPrime - ΙσΠριμε - λ
auto IsPrime = [](unsigned int number) -> bool {
  if (number <= 3 && number > 1) {
    return true;            // as 2 and 3 are prime
  }
  else if (number % 2 == 0 || number % 3 == 0) {
    return false;     // check if number is divisible by 2 or 3
  }
  else {
    unsigned int i;
    for (i = 5; i * i <= number; i += 6) {
      if (number % i == 0 || number % (i + 2) == 0) {
        return false;
      }
    }
    return true;
  }
};

//  Λ - is_even - ισ_εωεν - λ
auto is_even = [](auto val) {
  auto bv = val % 2 == 0;
  // std::cout << val << ' ' << std::boolalpha << bv<< '\n';
  return bv;
};

/*
 *  MARK: main()
 */
int main() {
  auto vals = std::vector {
    266U, 33U, 12U, 67U, 42U, 666U, 0U, 42U, 616U,
  };

  auto beastie { 616 };
  auto bestie { 633 };

  auto tif0a = std::find(vals.cbegin(), vals.cend(), beastie);
  auto tif0b = std::find(vals.cbegin(), vals.cend(), bestie);
  auto tif1a = std::find_if(vals.cbegin(), vals.cend(), IsPrime);
  auto tif2a = std::find_if_not(vals.cbegin(), vals.cend(), is_even);

  if (tif0a != vals.cend()) { std::cout << "found " << *tif0a << '\n'; }
  else { std::cout << beastie << " not found\n"; }

  if (tif0b != vals.cend()) { std::cout << "found " << *tif0b << '\n'; }
  else { std::cout << bestie << " not found\n"; }

  if (tif1a != vals.cend()) { std::cout << *tif1a << " is prime\n"; }
  else { std::cout << "no prime numbers\n"; }

  if (tif2a != vals.cend()) { std::cout << "found odd number " << *tif2a << '\n'; }
  else { std::cout << "no odd numbers\n"; }

  return 0;
}

//: Α α alpha, Β β beta,    Γ γ gamma,   Δ δ delta, Ε ε epsilon, Ζ ζ zeta,
//: Η η eta,   Θ θ theta,   Ι ι iota,    Κ κ kappa, Λ λ lambda,  Μ μ mu,
//: Ν ν nu,    Ξ ξ xi,      Ο ο omicron, Π π pi,    Ρ ρ rho,     Σ σ/ς sigma/final sigma,
//: Τ τ tau,   Υ υ upsilon, Φ φ phi,     Χ χ chi,   Ψ ψ psi,     Ω ω omega.

//  Greek keyboard
//  ` 1 2 3  4 5 6 7  8 9 0 -  =
//  ; ς ε ρ  τ υ θ ι  ο π [ ]  \
//  α σ δ φ  γ η ξ κ  λ ΄'
//  ζ χ ψ ω  β ν μ ,  . /

//  Shift
//  ~ ! @ #  $ % ^ &  * ( ) _  +
//  : ΅ Ε Ρ  Τ Υ Θ Ι  Ο Π { }  |
//  Α Σ Δ Φ  Γ Η Ξ Κ  Λ ¨ "
//  Ζ Χ Ψ Ω  Β Ν Μ <  > ?

//  Opt
//  ` ¹ ² ³  £ § ¶ °  • “ ° ±  ½
//  · ― € ®  ™ ¥ ­ †  œ ≈ « »  ¦
//  … ß ÷ ≠  © ½ ≤ ≥  ¬ ΅ '
//  §  ç ±    ‘ ’ «  » /

//  Opt-Shift
//  Μ έ ί ή  ό Ώ ^    Ρ Κ ύ _  +
//  ― Β Έ Δ      Ξ Ν  Τ   { }  ζ
//  ά ρ   Π  Ϊ ≠ § °  · : "
//      Χ Ά      Ό Ύ    ώ ?
