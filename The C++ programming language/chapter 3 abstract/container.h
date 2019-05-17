// Container.h

class Container
{
public:
	virtual double& operator[](int) = 0; // pure virtual function
	virtual int size() const = 0;
	virtual ~Container(){}
};
