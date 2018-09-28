#include <iostream>

class Animal
{
	private:
		int position;
	public:
		Animal() {position = 0;}
		void changePosition (int i)
		{
			position += i;
		}
};

class WalkingAnimal : virtual public Animal
{
public:
	void move() {changePosition(2);}

};

class SwimmingAnimal : virtual public Animal
{
public:
	void move() {changePosition(1);}

};

class Penguin : public SwimmingAnimal, public WalkingAnimal
{
public:
	void swim()
	{
		//SwimmingAnimal.move();
		//position += 2;
		//Animal::changePosition(2); //valid
		//move();

		//SwimmingAnimal::move(); //valid
	}

	void walk() {}
};

