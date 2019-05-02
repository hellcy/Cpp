#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iterator> 
#include <map> 
using namespace std; 

int serialNum = 9810;
vector<int> cells;
int sum[301][301];
//int serialNum = 42;

int calPowerLevel(int x, int y)
{
	int rackID = x + 10;
	int powerLevel = rackID * y;
	powerLevel = rackID * (powerLevel + serialNum);
	string powerStr = to_string(powerLevel);
	int hundred = powerStr[powerStr.length() - 3] - '0';
	return hundred - 5;
}

// part1 3 X 3 grid
int calGridPowerLevel(int x, int y)
{
	return calPowerLevel(x,y) + calPowerLevel(x+1,y) + calPowerLevel(x+2,y) + calPowerLevel(x,y+1) + calPowerLevel(x+1,y+1) +
	calPowerLevel(x+2,y+1) + calPowerLevel(x,y+2) + calPowerLevel(x+1,y+2) + calPowerLevel(x+2,y+2);
}

//part2 random size grid
int calRamdomGridPowerLevel(int x, int y, int size)
{
	int powerLevel = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			powerLevel += calPowerLevel(x + i, y + j);
			//powerLevel += cells[x + j + 300 * (y - 1 + i)];
		}
	}
	return powerLevel;
}

signed main()
{
	int finalX, finalY, finalZ, max = INT_MIN;
    int bx, by, bs, best = INT_MIN;

	for (int y = 1; y <= 300; y++)
	{
		for (int x = 1; x <= 300; x++)
		{
            int id = x + 10;
            int p = id * y + serialNum;
            p = (p * id) / 100 % 10 - 5;
            sum[y][x] = p + sum[y - 1][x] + sum[y][x - 1] - sum[y - 1][x - 1];
		}
	}

	for (int z = 1; z <= 300; z++)
	{
		for (int y = z; y <= 300; y++)
		{
			for (int x = z; x <= 300; x++)
			{
                int tempMax = sum[y][x] - sum[y - z][x] - sum[y][x - z] + sum[y - z][x - z];
                if(tempMax > max) {
                    max = tempMax;
                    finalX = x;
                    finalY = y;
                    finalZ = z;
                }
			}
		}
	}

	// now finalX and finalY are the coordinates at the right bottom corner, so substract the area size to get the top left cell.
	cout << finalX - finalZ + 1 << " " << finalY - finalZ + 1<<  " " << finalZ << endl;
	return 0;
}
