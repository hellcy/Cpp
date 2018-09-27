#include <iostream>

using namespace std;

class Person {
	char *namePtr;

public: 
	Person() {namePtr = new char;}
	void setName(char *s) {*namePtr = s;}
	char getName() {return *namePtr;}
};

int main()
{
	Person president;
	Person chairman;

	president.setName('T');

	chairman = president; // Tom is promoted to chairman

	president.setName('J'); // Janet is new president

	cout << chairman.getName << endl;
	cout << president.getName << endl;
}

