// OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include "Dog.h"
#include "Snake.h"
using namespace std;

int main()
{
	//comments are due to making the animal class pure virtual
	//Animal animal(5);		//allocated memory on stack, no 'new' keyword
	//animal.Travel();

	//Dog dog;
	//dog.Travel();

	//Animal* ptrAnimal = new Animal; //allocated memory on heap

	//(*ptrAnimal).Travel();
	//ptrAnimal->Travel(); //this does the same as the line above

	//Animal* ptrDog = new Dog;// instance of polymorphism
	//ptrDog->Travel();

	//cout << animal.GetLimbs() << endl;
	//{
	//	Animal* ptrAnim = new Animal(); //allocated memory on heap

	//}
	//ptrAnim->Travel(); // this doesn't work because ptrAnim is out of scope

	Snake python(true,0);
	python.Travel();
	python.Speak();

	cout << "------------------------" << endl;
	Dog dog;
	dog.Travel();
	dog.Speak();
	cout << "------------------------" << endl;

	//containers to store class instances
	vector<Animal*> animals;
	animals.push_back(new Dog());
	animals.push_back(new Dog());
	animals.push_back(new Snake());

	//iterate to implement methods
	for (Animal* ani : animals) {
		ani->Travel();
		ani->Speak();
	}
	for (Animal* ani : animals) {
		delete ani; //deallocating heap memory for each instance
	}
	animals.clear(); //eliminating pointers from vector that point to nothing
	cout << "------------------------" << endl;

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
