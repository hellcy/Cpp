#include<iostream>

using namespace std;
void f() {
	static int i = 3;
   
	cout<<i;
	if(--i) f();
}
main() {
	f();
}