#include <iostream>

using namespace std;

class Repository
{
public:
	virtual int getVolume() {return 0;}
	char getType() {return 'R';}
};

class Vault : public Repository
{
	virtual int getVolume() {return 150;}
	char getType() {return 'V';}
};

class Safe : public Repository
{
	virtual int getVolume() {return 50;}
	char getType() {return 'S';}
};

void showInfo(Repository* repos)
{
	cout << repos->getType() << repos->getVolume() << endl;
}

int main()
{
	Repository repos;
	Vault v;
	Safe s;


	showInfo(&repos);
	showInfo(&v);
	showInfo(&s);
}