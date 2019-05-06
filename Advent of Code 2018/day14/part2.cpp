#include <iostream>
#include <vector>
#include <string>
using namespace std;

int input = 846021;
vector<int> recipes;

void addToList(int A, int B)
{
	int newRecipe = recipes[A] + recipes[B];
	if (newRecipe > 9)
	{
		recipes.push_back(newRecipe / 10);
		recipes.push_back(newRecipe % 10);
	}
	else
	{
		recipes.push_back(newRecipe);
	}

}

int main()
{
	printf("%d\n", input);
	recipes.push_back(3);
	recipes.push_back(7);

	int currentA = 0;
	int currentB = 1;


	for (int i = 0; i < input*100; i++)
	{
		addToList(currentA, currentB);
		// test
		// if (i > 4 && recipes[i - 4] == 5 && recipes[i - 3] == 9 && recipes[i - 2] == 4 && recipes[i - 1] == 1 && recipes[i] == 4) printf("part2: %d\n", i - 4);
		if (i > 5 && recipes[i - 5] == 8 && recipes[i - 4] == 4 && recipes[i - 3] == 6 && recipes[i - 2] == 0 && recipes[i - 1] == 2 && recipes[i] == 1)
		{
			printf("part2: %d\n", i - 5);
			break;
		}
		currentA = (currentA + recipes[currentA] + 1) % recipes.size();
		currentB = (currentB + recipes[currentB] + 1) % recipes.size();
	}

	printf("part1: ");

	for (int i = input; i < input + 10; i++)
	{
		printf("%d", recipes[i]);
	}

	return 0;
}