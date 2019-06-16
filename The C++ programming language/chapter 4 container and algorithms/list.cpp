#include <iostream>
#include <string>
#include <list>
#include <iterator>
using namespace std;

struct entry
{
	string name;
	int number;
};

list<entry> phone_book = {
		{"David Hume", 123456},
		{"Karl Popper", 234567},
		{"Bertrand Arthur William Russell", 345678}
};

void print_book(const list<entry>& book)
{
	for (const auto& x : book) // for "auto" see §2.2.2
		cout << x.name << " " << x.number << '\n';
}

int get_number(const string& s)
{
	for (auto p = phone_book.begin(); p!=phone_book.end(); ++p)
		if (p->name==s)
			return p->number;
	return 0; // use 0 to represent "number not found"
}

int main()
{
	print_book(phone_book);
	int phoneNumber = get_number("David Hume");
	cout << phoneNumber;
	return 0;
}