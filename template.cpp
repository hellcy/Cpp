#include <iostream>

using namespace std;

template <typename T, int duration>
double power(double amplitude, int frequency = 1000) {}

int main()
{
	//double output = power<int, 100>(3.0, 'a'); //correct
	double output = power<int, 100>(3.0, 100); //correct
	//double output = power<500>(3.0);
	//double output = power<int, char>(3.0);
	//double output = power<int>(3.0, 100);

	//cout << output << endl;
}