#include <iostream>

using namespace std;

class A
{
    protected:
    int a;
    public:
    A(int x):a{x}{};
    virtual void display(){cout<<a<<endl;}
};

class B : virtual public A
{
    protected:
    int b;
    public:
    B(int x):A(x*2),b{x}{};
    void display(){cout<<b<<' '<<a<<endl;}
};

class C : virtual public A
{
    protected:
    int c;
    public:
    C(int x):A(x*5),c{x}{};
    void display(){cout<<c<<' '<<a<<endl;}
};

class D : public C,public B
{
    protected:
    int d;
    public:
    D(int x):A(1000*x),C(x*100),B(x*10),d{x}{};
    void display(){cout<<d<<' '<<c<<' '<<b<<' '<<a<<endl;}
};
int main()
{
    A a(1);
    B b(2);
    C c(3);
    D d(4);

    a.display();
    b.display();
    c.display();
    d.display();
}
