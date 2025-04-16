#pragma once
#include "Animal.h"

class Snake : public Animal
{
public:
	Snake() {
	} //default constructor
	Snake(bool venom, int limbs) : Animal(limbs) {
		//m_limbs = 0; // Snakes have 0 limbs
		is_venomous = venom;
		std::cout << "Snake constructor" << std::endl;
	}
	~Snake() { //destructor
		std::cout << "Snake destructor" << std::endl;
	}

	void Travel() override;
	void Speak() override;
	
protected:
	bool is_venomous;
};