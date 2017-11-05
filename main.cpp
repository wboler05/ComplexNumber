#include "ComplexMath.h"
#include <iostream>

int main () {
  Complex c1(5, 1);
  Complex c2(5, -1);

  std::cout << "C1: " << c1.toString() << std::endl;
  std::cout << "C2: " << c2.toString() << std::endl;
  std::cout << "C1 Phasor: " << c1.toStringPhasorRad() << std::endl;

  Complex c3 = c1 + c2;
  std::cout << "C1 + C2 = " << c3.toString() << std::endl;

  Complex c4 = c1 - c2;
  std::cout << "C1 - C2 = " << c4.toString() << std::endl;

  Complex c5 = c1 * c2;
  std::cout << "C1 * C2 = " << c5.toString() << std::endl;

  Complex c6 = c1 / c2;
  std::cout << "C1 / C2 = " << c6.toString() << std::endl;

  return 0;
}
