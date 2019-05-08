#include <iostream>

// keyword: auto, when define a variable, let the program decide its type.
int main()
{
	auto b = true; // b type is bool
	auto ch = 'x'; // ch type is char
	auto i = 123; // i type is int
	auto d = 1.2; // d type is double
	auto z = sqrt(y); // z type is the return type of the function sqrt
}

int sqrt(int y)
{
	return y * y;
}
