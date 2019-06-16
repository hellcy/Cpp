#include <iostream>
#include <string>

using namespace std;

void f()
{
	cout << "please enter your name: \n";
	string name;
	cin >> name;
	cout << "your name is: " + name + "\n";
}

int main()
{
	f();
	return 0;
}