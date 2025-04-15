#pragma once

class Animal 
{
public:
	//Animal() {} //default constructor
	Animal() { //constructor w/out parameters
		m_limbs = 0;
		m_ptr = new int(25); //allocated memory on heap, 4 bytes, value of 25
	}
	Animal(int limbs) { //constructor with parameters
		m_limbs = limbs;
	}
	~Animal() { //destructor
		delete m_ptr; //deallocating memory
	}

	virtual void Travel();
	int GetLimbs() { return m_limbs; }
	void SetLimbs(int limbs) { m_limbs = limbs; };

protected:
	int m_limbs;

	int* m_ptr = nullptr;

};