#define _DBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <memory>
#include <iostream>

template<typename T>
class smart_ptr
{

public:

	smart_ptr(T* ptr = nullptr) : _ptr{ ptr }{} 
	smart_ptr(const smart_ptr&) = delete; //don't allow copy constructor
	smart_ptr& operator = (const smart_ptr&) = delete;  //don't allow copy assignment
	~smart_ptr() { if (_ptr) delete _ptr; }

	T& operator * () { return *_ptr; }
	T* operator & () { return  _ptr; }
	T* operator -> () { return  _ptr; }

	T* get() { return _ptr; }

private:
	T* _ptr{};
};

using namespace std;
int main()
{
	//int arr[] = { 2,4,6,8 };
	//int* p = arr;
	//p++;
	//p++;
	//p--;
	//p = p + 2;
	//cout << *p << endl;

	int* p = new int{ };
	cout << *p << endl;

	delete p;
	

	{
		smart_ptr<int> sp{ new int {25} };
		unique_ptr<int> up{ new int {20} };

		unique_ptr<int> upc{ up };
	}
	

	_CrtDumpMemoryLeaks();
}
