#include <iostream>

using namespace std;

struct Dog{
	void bark() {cout << "arf" << endl;}
	void sit() { cout << "ah" << endl;}

};

int main(void)
{
	Dog rex;
	int z = 7, a = 1;

	switch(z)
	{
		default:
			break;

		z = 9;

		case 9:
			a = 2;
			cout << "case 9" << endl;
			break;

		break;

		case 8:
			rex.bark();
			cout << "case 8" << endl;
			break;

		case 7:
			cout << "case 7" << endl;
		case 0:
			rex.sit();
			cout << "case 0" << endl;
			break;
	}
}

// switch statement with dangling statements