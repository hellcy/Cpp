// user.cpp

#include "container.h"
#include <iostream>
#include "Vector_container.h"
#include "List_container.h"

using namespace std;

void use(Container& c)
{
	const int sz = c.size();

	for (int i = 0; i != sz; i++)
	{
		cout << c[i] << "\n";
	}
}

int main()
{
	List_container lc {10,9,8,7,6,5,4,3,2,1,0};
	use(lc);
}