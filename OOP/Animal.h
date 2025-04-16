#pragma once
#include <iostream>

class Animal 
{
public:
	//Animal() {} //default constructor
	Animal() { //constructor w/out parameters
		m_limbs = 0;
		m_ptr = new int(25); //allocated memory on heap, 4 bytes, value of 25
		std::cout << "Animal constructor" << std::endl;
	}
	Animal(int limbs) { //constructor with parameters
		m_limbs = limbs;
	}
	~Animal() { //destructor
		delete m_ptr; //deallocating memory
		std::cout << "Animal destructor" << std::endl;
	}

	virtual void Travel();
	virtual void Speak() = 0; //pure virtual function, no implementation in base class
	int GetLimbs() { return m_limbs; }
	void SetLimbs(int limbs) { m_limbs = limbs; };

protected:
	int m_limbs;

	int* m_ptr = nullptr;

};