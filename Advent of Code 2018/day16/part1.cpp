#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int like = 0, likeCount = 0;
vector<int> before, after, opcode;
string word = "";

void addr()
{
	if (after[opcode[3]] == (before[opcode[1]] + before[opcode[2]]))
	{
		like++;
		printf(" addr\n");
	}
}

void addi()
{
	if (after[opcode[3]] == (before[opcode[1]] + opcode[2]))
	{
		like++;
		printf(" addi\n");
	}
}

void mulr()
{
	if (after[opcode[3]] == (before[opcode[1]] * before[opcode[2]]))
	{
		like++;
		printf(" mulr\n");
	}
}

void muli()
{
	if (after[opcode[3]] == (before[opcode[1]] * opcode[2]))
	{
		like++;
		printf(" muli\n");
	}
}

void banr()
{
	if (after[opcode[3]] == (before[opcode[1]] & before[opcode[2]]))
	{
		like++;
		printf(" banr\n");
	}
}

void bani()
{
	if (after[opcode[3]] == (before[opcode[1]] & opcode[2]))
	{
		like++;
		printf(" bani\n");
	}
}

void borr()
{
	if (after[opcode[3]] == (before[opcode[1]] | before[opcode[2]]))
	{
		like++;
		printf(" borr\n");
	}
}

void bori()
{
	if (after[opcode[3]] == (before[opcode[1]] | opcode[2]))
	{
		like++;
		printf(" bori\n");
	}
}

void setr()
{
	if (after[opcode[3]] == before[opcode[1]])
	{
		like++;
		printf(" setr\n");
	}
}

void seti()
{
	if (after[opcode[3]] == opcode[1])
	{
		like++;
		printf(" seti\n");
	}
}

void gtir()
{
	if (after[opcode[3]] == (opcode[1] > before[opcode[2]]))
	{
		like++;
		printf(" gtir\n");
	}
}

void gtri()
{
	if (after[opcode[3]] == (before[opcode[1]] > opcode[2]))
	{
		like++;
		printf(" gtri\n");
	}
}

void gtrr()
{
	if (after[opcode[3]] == (before[opcode[1]] > before[opcode[2]]))
	{
		like++;
		printf(" gtrr\n");
	}
}

void eqir()
{
	if (after[opcode[3]] == (opcode[1] == before[opcode[2]]))
	{
		like++;
		printf(" eqir\n");
	}
}

void eqri()
{
	if (after[opcode[3]] == (before[opcode[1]] == opcode[2]))
	{
		like++;
		printf(" eqri\n");
	}
}

void eqrr()
{
	if (after[opcode[3]] == (before[opcode[1]] == before[opcode[2]]))
	{
		like++;
		printf(" eqrr\n");
	}
}

int main()
{
	ifstream f("test.txt"); //taking file as inputstream
	string line;
	while (getline(f, line))
	{
		printf("%s\n", line);
		if (line[0] == 'B')
		{
			before.push_back(line[9] - '0');
			before.push_back(line[12] - '0');
			before.push_back(line[15] - '0');
			before.push_back(line[18] - '0');
		}
		else if (line[0] == 'A')
		{
			after.push_back(line[9] - '0');
			after.push_back(line[12] - '0');
			after.push_back(line[15] - '0');
			after.push_back(line[18] - '0');
		}
		else
		{
		    for (auto x : line) 
		    { 
				if (x == ' ')
		        {
    				opcode.push_back(atoi(word));
		            word = "";
		            count++;
		        }
		        else
		        { 
		            word = word + x; 
		        } 
		    }
		}

		if (line.empty())
		{
			//for (int i = 0; i < before.size(); i++)
			//{
			//	printf("%d ", before[i]);
			//}
			//printf("\n");

			//for (int i = 0; i < before.size(); i++)
			//{
			//	printf("%d ", opcode[i]);
			//}		
			//printf("\n");
			//for (int i = 0; i < before.size(); i++)
			//{
			//	printf("%d ", after[i]);
			//}
			//printf("\n");

			addr();
			addi();
			mulr();
			muli();
			banr();
			bani();
			borr();
			bori();
			setr();
			seti();
			gtir();
			gtri();
			gtrr();
			eqir();
			eqri();
			eqrr();
			printf("%d\n", like);
			if (like >= 3) likeCount++;
			like = 0;
			before.clear();
			after.clear();
			opcode.clear();
			//printf("bitwise: %d\n", 5 | 9);
		}
	}
	printf("%d\n", likeCount);
	return 0;
}