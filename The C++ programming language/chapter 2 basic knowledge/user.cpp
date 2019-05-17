// user.cpp

#include "Vector.h"
#include <cmath>
#include <stdio.h>

using namespace std;

double sqrt_sum(Vector& v)
{
	double sum = 0;
	for (int i = 0; i!=v.size(); ++i)
	{
		printf("%f\n", v[i]);
		sum += sqrt(v[i]);
	}
	printf("%f\n", sum);
	return sum;
}

int main()
{
	Vector v(5);
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = i;
	}
	sqrt_sum(v);

	Vector v2 = {1,2,3,4,5};
	sqrt_sum(v2);
}