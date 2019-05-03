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

   vector<int> numbers;
   for (char x : str)
   {
   		numbers.push_back(x - '0');
   }

   int sum = 0;

   for (int i = 1; i < numbers.size(); i++)
   {
   		if (numbers[i] == numbers[i - 1])
   		{
   			sum += numbers[i];
   		}
   }
   if (numbers[0] == numbers[numbers.size() - 1]) sum += numbers[0];

   printf("%d\n", sum);
}