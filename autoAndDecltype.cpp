#include <iostream>

using namespace std;

int someFunc() {return 10;}

int main()
{
	auto a1 = 5;  // int
	auto a2 = someFunc(); // int

	decltype(a2) d4; // data type of d4 is the same as a2 and both are int
	decltype(someFunc()) d5 = 5; // d5 will have the data type int, but its value is initilized here

	double a3 = 4.0;
	auto &a6 = a3;

	cout << a2 << endl;
	cout << d4 << endl;
	cout << d5 << endl;
	cout << a6 << endl;
	cout << &a6 << endl;
}