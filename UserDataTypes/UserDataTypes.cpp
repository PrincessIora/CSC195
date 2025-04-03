// UserDataTypes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Declarations.h"


int main()
{
	std::cout << "User Data Types\n";
	Sandwich pastrami;
	pastrami.meat = Pastrami;
	pastrami.heatSandwich();
	//pastrami.isHot = true; //error - isHot is private
	pastrami.weight = 1.0f;

	std::cout << sizeof(pastrami) << std::endl;
	std::cout << sizeof(std::string) << std::endl;
	std::cout << sizeof(float) << std::endl;
	std::cout << sizeof(bool) << std::endl; //effienct memory access > padding > bool is 1 byte but compiler will align it to 4 bytes


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
