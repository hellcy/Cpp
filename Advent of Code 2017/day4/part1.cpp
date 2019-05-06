#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std; 

int main()
{
	ifstream f("input.txt"); //taking file as inputstream
	int count = 0, notValid = 0;
	int flagCount = 0;
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
	            //printf("%s\n", &word[0]);
	            words.push_back(word);
	            word = ""; 
	        }
	        else
	        { 
	            word = word + x; 
	        } 
	    }
		words.push_back(word);
		word = "";

	    for (string i : words)
	    {
			flagCount = 0;
	    	for (string j : words)
	    	{
				if (j == i)
				{
					printf("%d %s %s %d\n", count, &j[0], &i[0], flagCount);
					flagCount++;
				}
	    	}
			if (flagCount >= 2)
			{
				flag = true;
				break;
			}
	    }
	    if (flag == true) notValid++;
		count++;
	}
	int valid = count - notValid;
	printf("%d\n", valid);

}