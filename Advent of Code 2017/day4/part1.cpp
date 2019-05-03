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

	vector<string> words;

	string word;
	while (getline(f, line))
	{
	    for (auto x : str) 
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
	    		if (j == i)
	    	}
	    }
	}
	printf("%d\n", answer);

}