#include <iostream>

using namespace std;

int main()
{
	char i = 'a';
	char* p;
	char& r = i;

	cout << "r: " << r << "\n";

	p = &i;
	cout << "*p: " << *p << "\n";

}