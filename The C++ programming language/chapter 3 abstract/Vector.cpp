// Vector.cpp

#include "Vector.h"
#include <stdio.h>
#include <initializer_list>
#include <memory>

// constructor, only take one integer argument as its size
Vector::Vector(int s)
	:elem{new double[s]},sz{s}
{
	printf("Vector created.\n");
}

// another constructor, take an initializer list
Vector::Vector(std::initializer_list<double> ist)
	:elem{new double[ist.size()]},sz{int(ist.size())}
{
	std::copy(ist.begin(), ist.end(), elem);
	printf("Vector created.\n");
}

// destructor, free the space allocated by new, called when Vector lifetime is finished, user don't need to worry or use it manually
Vector::~Vector() {delete[] elem; printf("Vector deleted.\n");}

double& Vector::operator[](int i)
{
	return elem[i];
}

int Vector::size()
{
	return sz;
}