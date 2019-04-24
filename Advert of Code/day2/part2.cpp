#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{

	int answer = 0;
	list<string> inputs;
	ifstream file;
	file.open("C:\\c++\\Cpp\\Advert of Code\\day2\\input.txt");

	if (!file) 
	{
	    cerr << "Unable to open file input.txt";
	    exit(1);   // call system to stop
	}

	string line1, line2;
	int count = 0;

	while (getline(file, line1))
	{
		inputs.push_back(line1);
		//cout << line1 << "\n";
	}
	for (string line1 : inputs)
	{
		for (string line2 : inputs)
		{
			for (int i = 0; i < line1.length(); i++)
			{
				if (line1[i] != line2[i]) count++;
			}

			//cout << line1 << " " << line2 << " " << count << "\n";
			if (count == 1) 
			{
				cout << line1 << " " << line2 << "\n";
			}
			count = 0;
		}
	}
}