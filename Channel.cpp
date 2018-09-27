#include <iostream>

using namespace std;

class Channel {
	public:
	static int connections;
};

int Channel::connections = 0;

class PriChannel : public Channel {

};

class NorChannel : public Channel {

};


int main(void) {
	Channel ch;
	NorChannel ch1;
	PriChannel ch2;

	PriChannel &cref = ch2;

	return 0;
}
