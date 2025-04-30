#include "Sanctuary.h"
#include <fstream>
#include <iostream>

Sanctuary::Sanctuary() {}

Sanctuary::~Sanctuary() {
    Clear();
}

void Sanctuary::AddPony(std::shared_ptr<Pony> pony) {
    ponies.push_back(pony);
}

void Sanctuary::DisplayAll() const {
    for (const auto& pony : ponies) {
        std::cout << *pony << "\n";
    }
}

void Sanctuary::DisplayByName(const std::string& name) const {
    for (const auto& pony : ponies) {
        if (pony->GetName() == name) {
            std::cout << *pony << "\n";
        }
    }
}

void Sanctuary::DisplayByType(PonyType type) const {
    for (const auto& pony : ponies) {
        switch (type) {
        case UNICORN:
            if (dynamic_cast<Unicorn*>(pony.get()))
                std::cout << *pony << "\n";
            break;
        case PEGASUS:
            if (dynamic_cast<Pegasus*>(pony.get()))
                std::cout << *pony << "\n";
            break;
        case ALICORN:
            if (dynamic_cast<Alicorn*>(pony.get()))
                std::cout << *pony << "\n";
            break;
        case BASE_PONY:
            if (typeid(*pony) == typeid(Pony))
                std::cout << *pony << "\n";
            break;
        }
    }
}

void Sanctuary::Clear() {
    ponies.clear();  // smart pointers handle memory
}

void Sanctuary::Load(const std::string& filename) {
    Clear();
    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cerr << "Could not open file for loading.\n";
        return;
    }

    while (!in.eof()) {
        int typeInt;
        in >> typeInt;
        if (in.fail()) break;
        in.ignore(); // clear newline

        std::shared_ptr<Pony> pony;

        switch (typeInt) {
        case UNICORN:
            pony = std::make_shared<Unicorn>();
            break;
        case PEGASUS:
            pony = std::make_shared<Pegasus>();
            break;
        case ALICORN:
            pony = std::make_shared<Alicorn>();
            break;
        case BASE_PONY:
        default:
            pony = std::make_shared<Pony>();
            break;
        }

        if (pony) {
            in >> *pony;
            ponies.push_back(pony);
        }
    }

    in.close();
}

void Sanctuary::Save(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out.is_open()) {
        std::cerr << "Could not open file for saving.\n";
        return;
    }

    for (const auto& pony : ponies) {
        if (dynamic_cast<Unicorn*>(pony.get()))
            out << UNICORN << "\n";
        else if (dynamic_cast<Pegasus*>(pony.get()))
            out << PEGASUS << "\n";
        else if (dynamic_cast<Alicorn*>(pony.get()))
            out << ALICORN << "\n";
        else
            out << BASE_PONY << "\n";

        out << *pony;
    }

    out.close();
}
