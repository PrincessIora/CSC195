#pragma once
#include <string>
#include <iostream>

class Plant {
public:
	enum class eType { TREE, FLOWER };

protected:
	std::string name;
	int lifespan;

public:
	virtual ~Plant() = default;

	virtual void Read(std::ostream& ostream, std::istream& istream);
	virtual void Write(std::ostream& ostream);

	std::string GetName() const { return name; }

	virtual eType getType() = 0;

};