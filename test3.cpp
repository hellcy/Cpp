#include<iostream>

using namespace std;
int x = 5;

int &f() {
	return x;
}
main() {
	f() = 10;
   cout<<x;
}