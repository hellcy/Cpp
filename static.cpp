#include <iostream>

class Someclass {
public:
	static int data;
};

Someclass::data = 0;

Someclass objSome;

int main()
{
	//objSome::data;
	//objSome->data;
	//Someclass::data; //valid
	//Someclass::objSome.data;

Someclass<static int>.data;
}