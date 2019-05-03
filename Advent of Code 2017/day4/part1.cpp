#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std; 

int main()
{
	ifstream f("input.txt"); //taking file as inputstream
	int count = 0;
	bool flag = false;
	string line, word = "";
	while (getline(f, line))
	{
		flag = false;
		vector<string> words;
	    for (auto x : line) 
	    { 
	        if (x == ' ') 
	        { 
	            printf("%d\n", word);
	            words.push_back(word);
	            word = ""; 
	        }
	        else
	        { 
	            word = word + x; 
	        } 
	    }

	    for (string i : words)
	    {
	    	for (string j : words)
	    	{
	    		if (j == i) flag = true;
	    	}
	    }
	    if (flag == true) count++;
	}

	printf("%d\n", count);

}