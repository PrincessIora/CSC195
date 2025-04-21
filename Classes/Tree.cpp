#include "Tree.h"

void Tree::Read(std::ostream& ostream, std::istream& istream) {
    Plant::Read(ostream, istream);
    ostream << "Enter height (in meters): ";
    istream >> height;
}

void Tree::Write(std::ostream& ostream) {
    Plant::Write(ostream);
    ostream << "Height: " << height << " meters\n";
}