#include "Flower.h"

void Flower::Read(std::ostream& ostream, std::istream& istream) {
    Plant::Read(ostream, istream);
    ostream << "Enter color: ";
    istream >> color;
}

void Flower::Write(std::ostream& ostream) {
    Plant::Write(ostream);
    ostream << "Color: " << color << "\n";
}