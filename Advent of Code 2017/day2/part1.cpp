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
	while (getline(f, line))
	{
		int max = 0, min = 10000, temp = 0;
	    for (auto x : line) 
	    { 
	        if (x == '\t') 
	        { 
	            temp = stoi(word);
	            printf("%d\n", temp);
	            if (temp > max)
	            {
	            	max = temp;
	            }
	            if (temp < min)
	            {
	            	min = temp;
	            }
	            word = ""; 
	        }
	        else
	        { 
	            word = word + x; 
	        } 
	    }
        temp = stoi(word);
        printf("%d\n", temp);
        if (temp > max)
        {
        	max = temp;
        }
        if (temp < min)
        {
        	min = temp;
        }
        word = ""; 
	    printf("\n%d %d\n", max, min);
	    answer += max - min;
	}
	printf("%d\n", answer);

}