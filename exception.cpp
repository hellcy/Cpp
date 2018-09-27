#include <iostream>

using namespace std;

// void func1();
// void func2();
// void func3();
// void func4();

void func4() {
	exception e("func4 ");
	throw 10;
}

void func3() {
	cout << "func3 ";
	func4();
}

void fun2()
{
	try {
		func3();
	}
	catch(const exception e) {
		cout << "10 ";
		throw 2;
	}
	catch(...) {
		cout << "5 ";
		throw exception("two ");
	}
}



int main()
{
	try {
		func1();
	}
	catch(int i) {
		cout << i;
	}
	catch (const exception e) {
		cout << e.what();
	}
}