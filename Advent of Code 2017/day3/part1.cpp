#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std; 

int main()
{
	ifstream f("input.txt"); //taking file as inputstream
	string str;
	if(f) {
		ostringstream ss;
		ss << f.rdbuf(); // reading data
		str = ss.str();
	}
	int input = stoi(str);
	printf("%d\n", input);
	int closestRoot = int(sqrt(input));
	printf("%d\n", closestRoot);
	int bottomRightNum = closestRoot * closestRoot;
	printf("%d\n", bottomRightNum);
	int diff = input - bottomRightNum;
	printf("%d\n", diff);
	int answer = diff - (closestRoot + 1);
	printf("%d\n", answer);
	return 0;
}