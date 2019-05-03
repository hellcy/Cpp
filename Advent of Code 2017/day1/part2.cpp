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

   for (int i = 0; i < numbers.size(); i++)
   {
      if (i < numbers.size()/2)
      {
         if (numbers[i] == numbers[numbers.size()/2 + i])
         {
            sum += numbers[i];
         }
      }
      else
      {
         if (numbers[i] == numbers[i - numbers.size()/2])
         {
            sum += numbers[i];
         }
      }
   }

   printf("%d\n", sum);
}