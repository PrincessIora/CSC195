#pragma once
#include "Plant.h"

class Flower : public Plant {
    std::string color;

public:
    void Read(std::ostream& ostream, std::istream& istream) override;
    void Write(std::ostream& ostream) override;
    Plant::eType getType() override { return Plant::eType::FLOWER; }
};