#include <iostream>

using namespace std;

int elements[100];

int& getElement (int i)
{
	return elements[i];
}

int main()
{
	getElement(6) = 10;
	cout << typeof(elements[6]) << endl;
}