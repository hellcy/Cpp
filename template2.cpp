#include <iostream>

using namespace std;

template <class T>
void stripConst(T arg)
{
	typename remove_const<T>::type new_arg;

	if (is_const <decltype(new_arg)>::value)
		cout << "Type of  new_arg is const" << endl;
	else
		cout << "Type of new_arg is not const" << endl;
}

int main()
{
	stripConst("BLinkin");
	stripConst(676);
	stripConst(3.14);
}