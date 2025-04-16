#pragma once
#include "Animal.h"

class Dog : public Animal
{
public:
	Dog() : Animal(4) {
		m_limbs = 4; // Dogs have 4 limbs
		is_friendly = true;
		std::cout << "Dog constructor" << std::endl;
	}
	~Dog() { //destructor
		std::cout << "Dog destructor" << std::endl;
	}
	void Travel() override;
	void Speak() override;

protected:
	bool is_friendly;

};