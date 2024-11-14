#include <iostream>
using namespace std;

class Wheels
{
protected:
    string _type;
public:
    Wheels()
    {
       _type = "No type";
    }
    Wheels(string type) : Wheels()
    {
        _type = type;
    }

    virtual void Print() 
    {
        cout << "Type of wheels: " << _type << endl;
    }

    virtual ~Wheels() {}
};

class Engine
{
protected:
    double _horsepower;
public:
    Engine()
    {
        _horsepower = 0;
    }
    Engine(double horsepower) : Engine()
    {
        _horsepower = horsepower;
    }

    virtual void Print()
    {
        cout << "Horsepower of the engine: " << _horsepower << endl;
    }

    virtual ~Engine() {}
};

class Doors
{
protected:
    string _color;
public:
    Doors()
    {
        _color = "No color";
    }
    Doors(string color) : Doors()
    {
        _color = color;
    }

    virtual void Print()
    {
        cout << "Color of doors: " << _color << endl;
    }

    virtual ~Doors() {}
};

class Car : public Wheels, public Engine, public Doors
{
public:
    Car() : Wheels(), Engine(), Doors() {}

    Car(string type, double horsepower, string color) : Wheels(type), Engine(horsepower), Doors(color) {}

    void Print() override 
    {
        Wheels::Print();
        Engine::Print();
        Doors::Print();
    }
    virtual ~Car() {}
};

int main()
{
    Car* car = new Car("Carbon", 150, "green");

    car->Print();

    delete car;

    return 0;
}

