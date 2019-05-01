#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <cstdio>
#include <cctype>
#include <algorithm>

using namespace std;

int main() {
   ifstream f("input.txt"); //taking file as inputstream
   string str, strFull;
   if(f) {
      ostringstream ss;
      ss << f.rdbuf(); // reading data
      strFull = ss.str();
   }
   char upper, lower;
   bool flag = true;
   bool nextRound = false;

   for (char c = 'a'; c <= 'z'; c++)
   {
   		str = strFull;
		str.erase(std::remove(str.begin(), str.end(), c), str.end());
		c = toupper(c);
		cout << c << " ";
		str.erase(std::remove(str.begin(), str.end(), c), str.end());
		c = tolower(c);
	   while (flag)
	   {
		   for (int i = 0; i < str.length(); i++)
		   {
		   		 upper = toupper(str[i]);
		   		 lower = tolower(str[i]);
		   		if ((str[i] != str[i + 1] && upper == str[i+1]) || (str[i] != str[i + 1] && lower == str[i+1]))
		   		{
		   			str.erase(i, 2);
		   			i--;
		   			nextRound = true;
		   		}
		   }
		   if (nextRound) flag = true;
		   else flag = false;
		   nextRound = false;
	   }
	   flag = true;
	   cout << str.length() << "\n";
   }
}