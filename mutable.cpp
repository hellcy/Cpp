#include <iostream>

using namespace std;

class Cart {
	mutable bool bCountValid;
	mutable int fruitCount;

	static int apples;
	static int oranges;

public:
	Cart() : fruitCount(0), bCountValid(false) {}

	void addApples(int a) {apples += a; bCountValid = false;}
	void addOranges(int o) {oranges += o; bCountValid = false;}

	int getItemCount() const {
		if (!bCountValid) {fruitCount = apples + oranges; bCountValid = true;}
		return fruitCount;
	}
};

int Cart::apples = 0;
int Cart::oranges = 0;

int main(int argc, char **argv)
{
	Cart const checkOutPerson;
	Cart shoppers;

	shoppers.addApples(2);
	shoppers.addOranges(7);

	int total = checkOutPerson.getItemCount();

	cout << total << endl;
}

//mutable keyword: allowing the variable to be modified by a const function