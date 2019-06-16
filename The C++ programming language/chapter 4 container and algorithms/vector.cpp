#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct entry
{
	string name;
	int number;
};

vector<entry> phone_book = {
		{"David Hume", 123456},
		{"Karl Popper", 234567},
		{"Bertrand Arthur William Russell", 345678}
};

void print_book(const vector<entry>& book)
{
	for (const auto& x : book) // for "auto" see §2.2.2
		cout << x.name << " " << x.number << '\n';
}

void input()
{
	cout << "please enter an entry: \n";
	for (entry e; cin >> e.name;)
		phone_book.push_back(e);
		print_book(phone_book);
}

int main()
{
	print_book(phone_book);
	input();
	return 0;
}