// Database.cpp
#include "Garden.h"

Garden::~Garden() {
    for (Plant* obj : objects) {
        delete obj;
    }
}

void Garden::Create(Plant::eType type) {
    Plant* obj = nullptr;
    switch (type) {
    case Plant::eType::TREE:
        obj = new Tree();
        break;
    case Plant::eType::FLOWER:
        obj = new Flower();
        break;
    }
    obj->Read(std::cout, std::cin);
    objects.push_back(obj);
}

void Garden::DisplayAll() {
    for (Plant* obj : objects) {
        obj->Write(std::cout);
        std::cout << "------------------------\n";
    }
}

void Garden::Display(const std::string& name) {
    for (Plant* obj : objects) {
        if (obj->GetName() == name) {
            obj->Write(std::cout);
        }
    }
}

void Garden::Display(Plant::eType type) {
    for (Plant* obj : objects) {
        if (obj->getType() == type) {
            obj->Write(std::cout);
        }
    }
}
