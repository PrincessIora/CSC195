#include <iostream>
#include "Fraction.h"

using namespace mathlib;

int main() {
    Fraction<> fraction1{ 15, 5 };
    std::cout << "Fraction 1: " << fraction1 << std::endl;

    Fraction<> fraction2{ 15, 6 };
    fraction2.Simplify();
    std::cout << "Fraction 2 (Simplified): " << fraction2 << std::endl;

    std::cout << fraction1 << " == " << fraction2 << " : " << (fraction1 == fraction2) << std::endl;
    std::cout << fraction1 << " > " << fraction2 << " : " << (fraction1 > fraction2) << std::endl;

    std::cout << fraction1 << " + " << fraction2 << " = " << (fraction1 + fraction2) << std::endl;
    std::cout << fraction1 << " * " << fraction2 << " = " << (fraction1 * fraction2) << std::endl;

    Fraction<> fraction3;
    std::cout << "Input fraction (format numerator/denominator): ";
    std::cin >> fraction3;
    if (!std::cin.fail()) {
        std::cout << "You entered: " << fraction3 << std::endl;
        std::cout << "Decimal value: " << fraction3.toDouble() << std::endl;
    }
    else {
        std::cout << "Invalid input format." << std::endl;
    }

    return 0;
}
