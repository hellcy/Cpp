#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std; 

int main()
{
	ifstream f("input.txt"); //taking file as inputstream

	int answer = 0;
	string line, word = "";
	vector<int> numbers;
	int temp = 0;
	while (getline(f, line))
	{
		vector<int> numbers;
	    for (auto x : line) 
	    { 
	        if (x == '\t') 
	        { 
	            temp = stoi(word);
	            printf("%d\n", temp);
	            numbers.push_back(temp);
	            word = ""; 
	        }
	        else
	        { 
	            word = word + x; 
	        } 
	    }
        temp = stoi(word);
        printf("%d\n", temp);
	    numbers.push_back(temp);
        word = ""; 
        for (int i : numbers)
        {
        	for (int j : numbers)
        	{
        		if (j % i == 0 && j != i)
        		{
        			printf("%d %d\n", j, i);
        			answer += (j/i);
        			break;
        			break;
        		}
        	}
        }
	}
	printf("%d\n", answer);

}