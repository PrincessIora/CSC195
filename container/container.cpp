// container.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <array>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <iostream>

using namespace std;

void useArray() {
	array<string, 7> days = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };
	
	cout <<  days.size() << endl;
	for (int i = 0; i < days.size(); i++)//loops through the array 
	{
		cout << days[i] << endl;
	}

}
	void useVector() {

		vector<int> numbers = { 11, 42, 23, 94, 65 };

		numbers.push_back(100);
		numbers.push_back(2);
		numbers.pop_back();

		for (int i = 0; i < numbers.size(); i++)//loops through the vector
		
		{
			cout << numbers[i] << endl;
		}
	}
	void useList() {

		list<string> fruits = { "Banana", "Pineapple", "Pear" };
		fruits.push_back("Peach");
		fruits.push_front("Apple");

		fruits.remove("Pineapple");

		for (string fruit : fruits)//loops through the list
		{
			cout << fruit << endl;
		}
	}
	void useMap() {
		
		map<string, int> stock;
		stock["Banana"] = 12;
		stock["Apple"] = 7;
		stock["Orange"] = 3;

		stock["Banana"] += 5; 

		for (const auto& item : stock)//loops through the map
		{
			cout << item.first << ": " << item.second << endl;
		}
	}
	int main()
	{
		useArray();
		useVector();
		useList();
		useMap();

	}