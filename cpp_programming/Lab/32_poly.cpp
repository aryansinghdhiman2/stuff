#include <iostream>

using namespace std;

class A
{
    public:
    virtual void display()
    {
        cout<<"This is A\n";
    }
};

class B: public A
{
    public:
    void display()
    {
        cout<<"This is B\n";
    }
};

int main()
{
    A a;
    cout<<"Accessing display method of A using dot operator\n";
    a.display();
    B b;
    cout<<"Accessing display method of B using dot operator\n";
    b.display();

    A *ptrToObject=new B; 
    cout<<"Accessing display method of B using a pointer of type A\n";
    ptrToObject->display();

}