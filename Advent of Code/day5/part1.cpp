#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <cstdio>
#include <cctype>
using namespace std;

int main() {
   ifstream f("input.txt"); //taking file as inputstream
   string str;
   if(f) {
      ostringstream ss;
      ss << f.rdbuf(); // reading data
      str = ss.str();
   }
   //cout<<str;
   char upper, lower;
   bool flag = true;
   bool nextRound = false;
   while (flag)
   {
	   for (int i = 0; i < str.length(); i++)
	   {
	   		 //cout << str[i];
	   		 upper = toupper(str[i]);
	   		 lower = tolower(str[i]);
	   		 //cout << upper;
	   		 //cout << lower;
	   		 //cout << str[i + 1];
	   		if ((str[i] != str[i + 1] && upper == str[i+1]) || (str[i] != str[i + 1] && lower == str[i+1]))
	   		{
	   			cout << str[i] << "\n";
	   			str.erase(i, 2);
	   			i--;
	   			nextRound = true;
	   		}
	   		//cout << str << "\n";
	   }
	   if (nextRound) flag = true;
	   else flag = false;
	   nextRound = false;
   }

   cout << str.length() << "\n";
}