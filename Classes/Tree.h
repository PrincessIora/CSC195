#pragma once
#include "Plant.h"

class Tree : public Plant {
	int height;

public:
    void Read(std::ostream& ostream, std::istream& istream) override;
    void Write(std::ostream& ostream) override;
    Plant::eType getType() override { return Plant::eType::TREE; }

};