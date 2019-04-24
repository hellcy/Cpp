#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	list<int> frequencies; // a list to store all frequencies
	list<int> inputs; // a list to store numbers from the file
	int current = 0; // current frequency
	ifstream file;
	file.open("E:\\C++\\Advert of Code\\day1\\input.txt");

	if (!file) 
	{
	    cerr << "Unable to open file datafile.txt";
	    exit(1);   // call system to stop
	}

	string line;
	while (getline(file, line))
	{
		inputs.push_back(stoi(line));
	}


	frequencies.push_back(0);
	while (true)
	{
		for (int i : inputs)
		{
			current += i;
			for (int j : frequencies)
			{
				if (current == j)
				{
					cout << current;
					return 0;
				}
			} 
			cout << current << " ";
			frequencies.push_back(current);
		}
	}
}