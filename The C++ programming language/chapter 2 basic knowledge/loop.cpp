#include <iostream>

using namespace std;

int main()
{
	int tries = 1;
	while (tries < 4)
	{
		cout << "Do you want to proceed (y or n)?\n";
		char answer = 0;
		cin >> answer;

		switch (answer)
		{
			case 'y':
				cout << "You entered 'y'.\n";
				return true;
			case 'n':
				cout << "You entered 'n'.\n";
				return false;
			default:
				cout << "Sorry, I don't understand that.\n";
				++tries;
		}
	}
	cout << "I'll take that for a no.\n";
	return false;
}