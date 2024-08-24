#include<iostream>
using namespace std;
class values              //base class
{
    int a;
    int b;
    public:
    values(int x,int y):a{x},b{y}{}
    int get_a(){
        return a;
    }
    int get_b(){
        return b;
    }
};
class add:public virtual values //single inheritance
{
    int c;
    public:
    add(int x,int y):values(x,y){}
    void addition()
    {
        c=get_a()+get_b();
    }
    void display_sum()
    {
        cout<<"Sum of Values: "<<c<<endl;
    }
    int get_c()
    {
        return c;
    }
};
class subtract:public virtual values,public add //multiple inheritance
{
    int d;
    public:
    subtract(int x,int y):values(x,y),add(x,y){}
    void subtraction()
    {
        d=get_a()-get_b()-get_c();
    }
    void display_diff()
    {
        cout<<"Difference of first value and its sum: "<<d<<endl;
    }
};
class larger: public values
{
    int e;
    public:
    larger (int x,int y):values(x,y)
    {
        if (get_a()>get_b())
            e= get_a();
        else
            e= get_b();
    }
    void display1()
    {
        cout<<"Larger number is: "<<e<<endl; 
    }
    int get_e()
    {
        return e;
    }
};
class smaller: public values
{
    int f;
    public:
    smaller(int x,int y):values(x,y)
    {
        if (get_a()<get_b())
            f=get_a();
        else
            f=get_b();
    }
    void display2()
    {
        cout<<"Smaller number is :"<<f<<endl;
    }
};
class multiply:public larger  //multilevel inheritance
{
    int g;
    public:
    multiply(int x,int y):larger(x,y)
    {
        g=get_a()*get_b();
    }
    void showmult()
    {
        cout<<"the Result of Multiplication of First Value and Second Value is: "<<g;
    }
};
int main()
{
    int x,y;
    cout<<"Enter two numbers: ";
    cin>>x>>y;
    add sum1(x,y);
    sum1.addition();
    sum1.display_sum();
    subtract diff1(x,y);
    diff1.addition();
    diff1.subtraction();
    diff1.display_diff();
    larger o1(x,y);
    o1.display1();
    smaller o2(x,y);
    o2.display2();
    multiply o3(x,y);
    o3.showmult();
}