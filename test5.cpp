#include<iostream>

using namespace std;
main() { 
   int i = 13, j = 60;
   
   i^=j;
   j^=i;
   i^=j;
   cout<<i<<" "<<j;
}