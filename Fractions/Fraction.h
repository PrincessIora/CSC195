#pragma once
#include <iostream>
#include <stdexcept>
#include <numeric>

namespace mathlib {
    template<typename T = int>
    class Fraction {
    private:
        T numerator;
        T denominator;

        void normalize() {
            if (denominator == 0) {
                throw std::invalid_argument("Denominator cannot be zero");
            }
            if (denominator < 0) {
                numerator = -numerator;
                denominator = -denominator;
            }
            Simplify();
        }

    public:
        Fraction(T num = 0, T den = 1) : numerator(num), denominator(den) {
            normalize();
        }

        void Simplify() {
            T gcd_value = std::gcd(numerator, denominator);
            numerator /= gcd_value;
            denominator /= gcd_value;
        }

        double toDouble() const {
            return static_cast<double>(numerator) / static_cast<double>(denominator);
        }

        Fraction operator+(const Fraction& other) const {
            return Fraction(
                numerator * other.denominator + other.numerator * denominator,
                denominator * other.denominator
            );
        }

        Fraction operator-(const Fraction& other) const {
            return Fraction(
                numerator * other.denominator - other.numerator * denominator,
                denominator * other.denominator
            );
        }

        Fraction operator*(const Fraction& other) const {
            return Fraction(
                numerator * other.numerator,
                denominator * other.denominator
            );
        }

        Fraction operator/(const Fraction& other) const {
            if (other.numerator == 0) {
                throw std::invalid_argument("Cannot divide by zero fraction.");
            }
            return Fraction(
                numerator * other.denominator,
                denominator * other.numerator
            );
        }

        // Comparison operators
        bool operator==(const Fraction& other) const {
            return numerator * other.denominator == denominator * other.numerator;
        }

        bool operator!=(const Fraction& other) const {
            return !(*this == other);
        }

        bool operator<(const Fraction& other) const {
            return numerator * other.denominator < denominator * other.numerator;
        }

        bool operator<=(const Fraction& other) const {
            return *this < other || *this == other;
        }

        bool operator>(const Fraction& other) const {
            return !(*this <= other);
        }

        bool operator>=(const Fraction& other) const {
            return !(*this < other);
        }

        // Stream operators
        friend std::ostream& operator<<(std::ostream& out, const Fraction<T>& frac) {
            out << frac.numerator << '/' << frac.denominator;
            return out;
        }

        friend std::istream& operator>>(std::istream& in, Fraction<T>& frac) {
            T num, den;
            char slash;
            in >> num >> slash >> den;
            if (slash != '/') {
                in.setstate(std::ios::failbit);
                return in;
            }
            frac = Fraction(num, den);
            return in;
        }
    };
}
