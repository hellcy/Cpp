#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
	int twos = 0;
	int threes = 0;
	int answer = 0;
	bool twoFlag = false;
	bool threeFlag = false;
	ifstream file;
	file.open("C:\\c++\\Cpp\\Advert of Code\\day2\\input.txt");

	if (!file) 
	{
	    cerr << "Unable to open file input.txt";
	    exit(1);   // call system to stop
	}

	string line;
	int count = 0;
	while (getline(file, line))
	{
		for(char& i : line) {
			for(char& j : line) {
				if (i == j) count++;
			}
			//line.erase(remove(line.begin(), line.end(), i), line.end());
			if (count == 3)
			{
				threeFlag = true;
			}
			else if (count == 2) twoFlag = true;
			count = 0;
		}
		if (threeFlag) threes++;
		if (twoFlag) twos++;

		threeFlag = false;
		twoFlag = false;
	}
	answer = twos * threes;
	cout << answer << " " << threes << " " << twos;
}