#include <iostream>

using namespace std;

template <class T> class Some
{
public:
	static int stat;

};

template <class T>
int Some<T>::stat = 10;

int main(void)
{
	Some<int>::stat = 5;
	cout << Some<int>::stat << "        ";

	cout << Some<char>::stat << "        ";
	cout << Some<float>::stat << "        ";
	cout << Some<long>::stat << endl;

}