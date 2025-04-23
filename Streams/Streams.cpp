// Streams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
#include <string> 
#include <fstream> 
#include <vector>
using namespace std;

// reasons to pass by reference
//for classes like ostream, istream, cannot create copies, so pass by reference
//Ensure manipulation of variables inside the main method
//for performance, avoid copying large objects
// rule of thumb: use pass by reference whenever possible | Exception: Cannot point to nothing, so if parameter can be null, use pointer


void Write(const string& text, ostream& ostream) 
{ 
	//text = "Ha"; // -- avoid manipulation of the passed parameter by using const
	ostream << text << endl;
}

void Write(const vector<int>& numbers, ofstream& ostream)
{ 
	for (int n : numbers)
	{ 
		ostream << n << endl;
	}

}

void Read(string& text, ifstream& istream)
{
	istream >> text; // read from file
}

void Read(vector<int>& numbers, ifstream& istream)
{
	while (!istream.eof())
	{
		int n;
		istream >> n;

		numbers.push_back(n);
	}
}

int main()
{
	string text = "Hello World!\n";
	cout << text; // Output to console

    //cin >> text; // Input from console / can only read one word
	getline(cin, text); // Input from console / can read multiple words

	//cout << text << endl;
	Write(text, cout);

	//output to file
	ofstream output("data.txt"); //create and open a file to stream
	//output << text; 
	Write(text, output); 
	int i = 5;
	output << i << endl; 
	output.close(); //always close the file when done using it

	text = ""; //clear the text after writing to file
	//input from file
	ifstream input("data.txt"); //create and open a file to stream
	getline(input, text);
	//Read(text, input);
	input >> i;
	//input >> text;
	input.close();

	cout << "Reading from file:" << endl;
	cout << text << endl; 
	cout << i << endl;

	vector<int> numbers = { 7,12,35,79 };
	//store vector in file

	output.open("numbas.txt");
	Write(numbers, output);

	numbers.clear(); //clear the vector after writing to file
	output.close();
	input.open("numbas.txt");
	Read(numbers, input);

	input.close();

	for (int n : numbers)
	{
		cout << n << endl;
	}


}
