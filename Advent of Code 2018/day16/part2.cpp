#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

int like = 0;// , likeCount = 0;
vector<int> before, after, opcode;
vector<string> ops, finalOpsVector;
map<int, string> finalOps;
map<int, string>::iterator iter;
string word = "";

void addr()
{
	if (after[opcode[3]] == (before[opcode[1]] + before[opcode[2]]))
	{
		like++;
		ops.push_back("addr");
		//printf(" addr\n");
	}
}

void addi()
{
	if (after[opcode[3]] == (before[opcode[1]] + opcode[2]))
	{
		like++;
		ops.push_back("addi");
		//printf(" addi\n");
	}
}

void mulr()
{
	if (after[opcode[3]] == (before[opcode[1]] * before[opcode[2]]))
	{
		like++;
		ops.push_back("mulr");
		//printf(" mulr\n");
	}
}

void muli()
{
	if (after[opcode[3]] == (before[opcode[1]] * opcode[2]))
	{
		like++;
		ops.push_back("muli");
		//printf(" muli\n");
	}
}

void banr()
{
	if (after[opcode[3]] == (before[opcode[1]] & before[opcode[2]]))
	{
		like++;
		ops.push_back("banr");
		//printf(" banr\n");
	}
}

void bani()
{
	if (after[opcode[3]] == (before[opcode[1]] & opcode[2]))
	{
		like++;
		ops.push_back("bani");
		//printf(" bani\n");
	}
}

void borr()
{
	if (after[opcode[3]] == (before[opcode[1]] | before[opcode[2]]))
	{
		like++;
		ops.push_back("borr");
		//printf(" borr\n");
	}
}

void bori()
{
	if (after[opcode[3]] == (before[opcode[1]] | opcode[2]))
	{
		like++;
		ops.push_back("bori");
		//printf(" bori\n");
	}
}

void setr()
{
	if (after[opcode[3]] == before[opcode[1]])
	{
		like++;
		ops.push_back("setr");
		//printf(" setr\n");
	}
}

void seti()
{
	if (after[opcode[3]] == opcode[1])
	{
		like++;
		ops.push_back("seti");
		//printf(" seti\n");
	}
}

void gtir()
{
	if (after[opcode[3]] == (opcode[1] > before[opcode[2]]))
	{
		like++;
		ops.push_back("gtir");
		//printf(" gtir\n");
	}
}

void gtri()
{
	if (after[opcode[3]] == (before[opcode[1]] > opcode[2]))
	{
		like++;
		ops.push_back("gtri");
		//printf(" gtri\n");
	}
}

void gtrr()
{
	if (after[opcode[3]] == (before[opcode[1]] > before[opcode[2]]))
	{
		like++;
		ops.push_back("gtrr");
		//printf(" gtrr\n");
	}
}

void eqir()
{
	if (after[opcode[3]] == (opcode[1] == before[opcode[2]]))
	{
		like++;
		ops.push_back("eqir");
		//printf(" eqir\n");
	}
}

void eqri()
{
	if (after[opcode[3]] == (before[opcode[1]] == opcode[2]))
	{
		like++;
		ops.push_back("eqri");
		//printf(" eqri\n");
	}
}

void eqrr()
{
	if (after[opcode[3]] == (before[opcode[1]] == before[opcode[2]]))
	{
		like++;
		ops.push_back("eqrr");
		//printf(" eqrr\n");
	}
}

void run(string opName)
{
	if (opName == "addr") before[opcode[3]] = before[opcode[1]] + before[opcode[2]];
	if (opName == "addi") before[opcode[3]] = before[opcode[1]] + opcode[2];
	if (opName == "mulr") before[opcode[3]] = before[opcode[1]] * before[opcode[2]];
	if (opName == "muli") before[opcode[3]] = before[opcode[1]] * opcode[2];
	if (opName == "banr") before[opcode[3]] = before[opcode[1]] & before[opcode[2]];
	if (opName == "bani") before[opcode[3]] = before[opcode[1]] & opcode[2];
	if (opName == "borr") before[opcode[3]] = before[opcode[1]] | before[opcode[2]];
	if (opName == "bori") before[opcode[3]] = before[opcode[1]] | opcode[2];
	if (opName == "setr") before[opcode[3]] = before[opcode[1]];
	if (opName == "seti") before[opcode[3]] = opcode[1];
	if (opName == "gtir") before[opcode[3]] = opcode[1] > before[opcode[2]];
	if (opName == "gtri") before[opcode[3]] = before[opcode[1]] > opcode[2];
	if (opName == "gtrr") before[opcode[3]] = before[opcode[1]] > before[opcode[2]];
	if (opName == "eqir") before[opcode[3]] = opcode[1] == before[opcode[2]];
	if (opName == "eqri") before[opcode[3]] = before[opcode[1]] == opcode[2];
	if (opName == "eqrr") before[opcode[3]] = before[opcode[1]] == before[opcode[2]];

}

int main()
{
	ifstream f("input1.txt"); //taking file as inputstream
	string line;
	while (getline(f, line))
	{
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
		else if (line.empty())
		{

			if (std::find(finalOpsVector.begin(), finalOpsVector.end(), "addr") == finalOpsVector.end()) addr();
			if (std::find(finalOpsVector.begin(), finalOpsVector.end(), "addi") == finalOpsVector.end()) addi();
			if (std::find(finalOpsVector.begin(), finalOpsVector.end(), "mulr") == finalOpsVector.end()) mulr();
			if (std::find(finalOpsVector.begin(), finalOpsVector.end(), "muli") == finalOpsVector.end()) muli();
			if (std::find(finalOpsVector.begin(), finalOpsVector.end(), "banr") == finalOpsVector.end()) banr();
			if (std::find(finalOpsVector.begin(), finalOpsVector.end(), "bani") == finalOpsVector.end()) bani();
			if (std::find(finalOpsVector.begin(), finalOpsVector.end(), "borr") == finalOpsVector.end()) borr();
			if (std::find(finalOpsVector.begin(), finalOpsVector.end(), "bori") == finalOpsVector.end()) bori();
			if (std::find(finalOpsVector.begin(), finalOpsVector.end(), "setr") == finalOpsVector.end()) setr();
			if (std::find(finalOpsVector.begin(), finalOpsVector.end(), "seti") == finalOpsVector.end()) seti();
			if (std::find(finalOpsVector.begin(), finalOpsVector.end(), "gtir") == finalOpsVector.end()) gtir();
			if (std::find(finalOpsVector.begin(), finalOpsVector.end(), "gtri") == finalOpsVector.end()) gtri();
			if (std::find(finalOpsVector.begin(), finalOpsVector.end(), "gtrr") == finalOpsVector.end()) gtrr();
			if (std::find(finalOpsVector.begin(), finalOpsVector.end(), "eqir") == finalOpsVector.end()) eqir();
			if (std::find(finalOpsVector.begin(), finalOpsVector.end(), "eqri") == finalOpsVector.end()) eqri();
			if (std::find(finalOpsVector.begin(), finalOpsVector.end(), "eqrr") == finalOpsVector.end()) eqrr();

			//if (like >= 3) likeCount++;
			if (like == 1)
			{
				printf("opcode: %d, op: %s\n", opcode[0], &ops[0][0]);
				finalOpsVector.push_back(ops[0]);
				finalOps.insert(pair<int, string>(opcode[0], ops[0]));
			}
			like = 0;
			ops.clear();
			before.clear();
			after.clear();
			opcode.clear();
		}
		else 
		{
		    for (auto x : line) 
		    { 
				if (x == ' ')
		        {
    				opcode.push_back(stoi(word));
		            word = "";
		        }
		        else
		        { 
		            word = word + x; 
		        } 
		    }
			opcode.push_back(stoi(word));
            word = "";
		}
		//printf("%s\n", &line[0]);

	}
	for (iter = finalOps.begin(); iter != finalOps.end(); ++iter) {
		printf("%d %s\n", iter->first, &iter->second[0]);
	}

	ifstream f2("input2.txt"); //taking file as inputstream
	string line2;
	before.clear();
	before.push_back(0);
	before.push_back(0);
	before.push_back(0);
	before.push_back(0);

	while (getline(f2, line2))
	{
		opcode.clear();
		for (auto x : line2)
		{
			if (x == ' ')
			{
				opcode.push_back(stoi(word));
				word = "";
			}
			else
			{
				word = word + x;
			}
		}
		opcode.push_back(stoi(word));
		word = "";

		for (iter = finalOps.begin(); iter != finalOps.end(); ++iter) {
			if (iter->first == opcode[0]) run(iter->second);
		}
	}
	printf("part2: %d\n", before[0]);
	return 0;
}