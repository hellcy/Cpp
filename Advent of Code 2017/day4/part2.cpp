#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std; 

bool rearrage(string string1, string string2)
{
	bool equal = false;
	string temp = string1;
	int tempLength = temp.length();
	for (int i = 0; i < string1.length(); i++)
	{
		for (int j = 0; j < string2.length(); j++)
		{
			if (string1[i] == string2[j])
			{
				string2.erase(j,1);
				tempLength--;
				if (string2.length() == 0 && tempLength == 0) equal = true;
				break;
			}
		}
	}
	return equal;
}

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
				if (rearrage(&i[0], &j[0]))
				{
					printf("%d %s %s %d\n", count, &i[0], &j[0], flagCount);
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