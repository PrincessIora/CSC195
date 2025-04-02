// DataTypes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Data Types Program\n";
	std::cout << "Size of int: " << sizeof(int) << std::endl;
	std::cout << "Size of bool: " << sizeof(bool) << std::endl;

	//data type conversion

	//implicit conversion - target type has the capacity to store the original value
	int i = 5;
	float iflt = i;
	double idbl = iflt;


	//explicit conversion - explicitly inform complier that you want to convert the data type
	double jdbl = 32.357929383;
	float jflt = (float)jdbl; //traditional C++ style conversion

	jflt = static_cast<float>(jdbl); //modern C++ style conversion




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
