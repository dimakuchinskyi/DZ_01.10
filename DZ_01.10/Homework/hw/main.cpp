#include <iostream>
using namespace std;


template <typename T1, typename T2>
class Base
{
protected:
    T1 _value1;
    T2 _value2;
public:
    Base()
    {
        _value1 = new T1();
        _value2 = new T2();
    }
    Base(T1 value1, T2 value2) : Base() 
    {
        _value1 = value1;
        _value2 = value2;
    }

    virtual void Print()
    {
        cout << "Value 1: " << _value1 << endl;
        cout << "Value 2: " << _value2 << endl;
    }

    virtual ~Base() {}
};

template <typename T1, typename T2, typename T3, typename T4>
class Child : public Base<T1, T2>
{
protected:
    T3 _value3;
    T4 _value4;
public:
    Child() : Base<T1, T2>()
    {
        _value3 = new T3();
        _value4 = new T4();
    }

    Child(T1 value1, T2 value2, T3 value3, T4 value4): Base<T1, T2>(value1, value2) 
    {
        _value3 = value3;
        _value4 = value4;
    }

    virtual void Print()
    {
        Base<T1, T2>::Print();
        cout << "Value 3: " << _value3 << endl;
        cout << "Value 4: " << _value4 << endl;
    }

    virtual ~Child() {}
};


template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Child2 : public Child<T1, T2, T3, T4>
{
protected:
    T5 _value5;
    T6 _value6;
public:
    Child2() : Child<T1, T2, T3, T4>()
    {
        _value5 = new T5();
        _value6 = new T6();
    }

    Child2(T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6) : Child<T1, T2, T3, T4>(value1, value2, value3, value4)
    {
        _value5 = value5;
        _value6 = value6;
    }

    void Print() override
    {
        Child<T1, T2, T3, T4>::Print();
        cout << "Value 5: " << _value5 << endl;
        cout << "Value 6: " << _value6 << endl;
    }

    virtual ~Child2() {}
};

int main()
{
    Base<int, double> base(10, 20.5);
    cout << "Base class:" << endl;
    base.Print();
    cout << endl;

    Child<int, double, string, bool> child(10, 20.5, "Hello", true);
    cout << "Child class:" << endl;
    child.Print();
    cout << endl;

    Child2<int, double, string, bool, char, float> child2(10, 20.5, "Hello", true, 'A', 3.14f);
    cout << "Child2 class:" << endl;
    child2.Print();

    return 0;
}
