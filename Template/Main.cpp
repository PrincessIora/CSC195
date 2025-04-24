#include <iostream>
#include "TemplateClass.h"

using namespace std;

namespace xia 
{
	template<typename T , typename U>
	T max(T i1, U i2)
	{
		return (i1 > i2) ? i1 : i2; // ternary operation
	}
}

int main()
{
	cout << xia::max(6.5f, 6) << endl; // call max function

	TemplateClass<int> tp1;
	TemplateClass<float> tp2;

	TemplateClass<> tp3;

	Array<string, 5> strAr;

	strAr[2] = "Banana";


}