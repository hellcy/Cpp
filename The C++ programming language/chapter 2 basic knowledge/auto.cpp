#include <iostream>

using namespace std;

int sqrt(int y)
{
	return y * y;
}

void sizes()
{
	cout << "size of char: " << sizeof(char) << endl;
	cout << "size of bool: " << sizeof(bool) << endl;
	cout << "size of int: " << sizeof(int) << endl;
	cout << "size of double: " << sizeof(double) << endl;
	cout << "size of long: " << sizeof(long) << endl;
	cout << "size of long int: " << sizeof(long int) << endl;
	cout << "size of long long: " << sizeof(long long) << endl;

}

// keyword: auto, when define a variable, let the program decide its type.
int main()
{
	auto b = true; // b type is bool
	auto ch = 'x'; // ch type is char
	auto i = 123; // i type is int
	auto d = 1.2; // d type is double
	auto z = sqrt(i); // z type is the return type of the function sqrt

	sizes();
}