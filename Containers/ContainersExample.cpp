// Containers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <list>
#include <map>
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

	cout << "______________________" << endl;

	//pointer Arithmetic

	string chemicals[5] = { "Mercury", "Hydrochloric Acid","Chlorine","Bromine","Table Salt" };
	cout << chemicals[2] << endl;
	cout << chemicals << endl; //returns address of first element of the array
	cout << &chemicals[0] << endl; //returns address of first element of the array

	cout << "_____________________" << endl;
	cout << "_____________________" << endl;

	cout << chemicals << endl;

	int size = sizeof(chemicals) / sizeof(chemicals[0]);

	for (int i = 0;i< size; i++)
	{
		cout << chemicals[i] << endl;
	}
	cout << "_____________________" << endl;

	for (string chemical : chemicals)
	{
		cout << chemical << endl;
	}
	cout << "_____________________" << endl;

	string* p = chemicals;
	cout << p << endl;
	cout << ++p << endl;
	cout << ++p << endl;
	cout << --p << endl;
	cout << p + 2 << endl;
	cout << p - 3 << endl;

	cout << "_____________________" << endl;

	//containers
	list<string> cars = { "Hyundai", "Ferrari", "Mercedes", "Volvo" };

	cout << cars.front() << endl; //returns first element of the list
	cout << cars.back() << endl; //returns last element of the list

	cars.pop_back(); //removes last element of the list
	cout << cars.back() << endl; 

	cars.push_front("Tesla");//adds element at the front of the list
	cout << cars.front() << endl; 

	cout << "_____________________" << endl;

	map<string, int> pet = { {"Dogs",23},{"Chameleons",3},{"Turtle",43} };

	pet["Dogs"] = 50;
	cout << pet["Dogs"] << endl;

	pet["Spiders"] = 2;//adds new element to the map

	cout << pet.empty() << endl; //returns 0 if map is not empty


}
