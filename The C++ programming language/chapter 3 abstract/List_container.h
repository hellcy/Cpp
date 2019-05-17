#include <stdio.h>
#include <initializer_list>

class List_container : public Container{
	std::list<double> ld;
public:
	List_container(){};
	List_container(initializer_list<double> il):ld{il}{}
	~List_container(){};

	double& operator[](int i);
	int size() const {return ld.size();}
};

double& List_container::operator[](int i)
{
	for(auto& x :ld)
	{
		if (i == 0) return x;
		--i;
	}
	throw out_of_range("List Container");
}