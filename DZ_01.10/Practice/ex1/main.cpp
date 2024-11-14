#include <iostream>
using namespace std;

class Circle 
{
protected:
	double _radius;
public:
	Circle()
	{
		_radius = 0;
	}
	Circle(double radius) : Circle()
	{
		_radius = radius;
	}

	virtual void Print() 
	{
		cout << "Radius: " << _radius << endl;
	}
};

class Square
{
protected:
	double _side;
public:
	Square()
	{
		_side = 0;
	}
	Square(double side) : Square()
	{
		_side = side;
	}

	virtual void Print()
	{
		cout << "Side: " << _side << endl;
	}
};

class Child : public Circle, public Square
{
public:
	Child(double side) : Square(side), Circle(side / 2) {}

	void Print() override 
	{
		Circle::Print();
		Square::Print();
	}
};

int main() {

	Child * obj = new Child(4);
	obj->Print();

	return 0;
}