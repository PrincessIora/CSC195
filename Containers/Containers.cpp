// Containers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string fruits[5] = { "Banana","Kiwi","Mango","Chikoo","Strawberry" }; // example of array with assigned values
	
	vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(3);
	numbers.push_back(5);
	numbers.push_back(7);
	numbers.push_back(25);

	numbers.pop_back();
	numbers.pop_back();

	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << endl;
	}

}
