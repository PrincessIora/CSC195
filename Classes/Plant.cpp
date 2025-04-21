#include "Plant.h"

void Plant::Read(std::ostream& ostream, std::istream& istream) {
    ostream << "Enter name: ";
    istream >> name;
    ostream << "Enter lifespan (in years): ";
    istream >> lifespan;
}

void Plant::Write(std::ostream& ostream) {
    ostream << "Name: " << name << "\nLifespan: " << lifespan << " years\n";
}

