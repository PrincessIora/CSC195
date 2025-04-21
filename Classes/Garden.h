//Database class
#pragma once
#include <vector>
#include "Plant.h"
#include "Tree.h"
#include "Flower.h"

class Garden {
    std::vector<Plant*> objects;

public:
    ~Garden();
    void Create(Plant::eType type);
    void DisplayAll();
    void Display(const std::string& name);
    void Display(Plant::eType type);
};