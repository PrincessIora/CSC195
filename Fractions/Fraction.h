#pragma once
#include <iostream>
#include <stdexcept>
#include <numeric>  // For std::gcd in C++17

namespace mathlib {

    template<typename T = int>
    class Fraction {
    private:
        T numerator;
        T denominator;

        void simplify() {
            T gcd = std::gcd(numerator, denominator);
            numerator /= gcd;
            denominator /= gcd;
            if (denominator < 0) { // Keep denominator positive
                numerator = -numerator;
                denominator = -denominator;
            }
        }

    public:
        // Default constructor: 0/1
        Fraction() : numerator(0), denominator(1) {}

        // Parameterized constructor
        Fraction(T num, T denom) : numerator(num), denominator(denom) {
            if (denom == 0) {
                throw std::invalid_argument("Denominator cannot be zero.");
            }
            simplify();
        }

        // Copy constructor, assignment operator, etc., are compiler-generated

        // Arithmetic Operators
        Fraction operator+(const Fraction& other) const {
            T num = numerator * other.denominator + other.numerator * denominator;
            T denom = denominator * other.denominator;
            return Fraction(num, denom);
        }

        Fraction operator-(const Fraction& other) const {
            T num = numerator * other.denominator - other.numerator * denominator;
            T denom = denominator * other.denominator;
            return Fraction(num, denom);
        }

        Fraction operator*(const Fraction& other) const {
            T num = numerator * other.numerator;
            T denom = denominator * other.denominator;
            return Fraction(num, denom);
        }

        Fraction operator/(const Fraction& other) const {
            if (other.numerator == 0) {
                throw std::invalid_argument("Cannot divide by zero.");
            }
            T num = numerator * other.denominator;
            T denom = denominator * other.numerator;
            return Fraction(num, denom);
        }

        // Comparison Operators
        bool operator==(const Fraction& other) const {
            return numerator == other.numerator && denominator == other.denominator;
        }

        bool operator!=(const Fraction& other) const {
            return !(*this == other);
        }

        bool operator<(const Fraction& other) const {
            return numerator * other.denominator < other.numerator * denominator;
        }

        bool operator>(const Fraction& other) const {
            return other < *this;
        }

        bool operator<=(const Fraction& other) const {
            return !(*this > other);
        }

        bool operator>=(const Fraction& other) const {
            return !(*this < other);
        }

        // Stream Operators
        friend std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
            os << frac.numerator << "/" << frac.denominator;
            return os;
        }

        friend std::istream& operator>>(std::istream& is, Fraction& frac) {
            T num, denom;
            char slash;
            is >> num >> slash >> denom;
            if (slash != '/' || denom == 0) {
                is.setstate(std::ios::failbit);
            }
            else {
                frac = Fraction(num, denom);
            }
            return is;
        }

        // Utility Methods
        void Simplify() {
            simplify();
        }

        double toDouble() const {
            return static_cast<double>(numerator) / static_cast<double>(denominator);
        }
    };

} // namespace mathlib
