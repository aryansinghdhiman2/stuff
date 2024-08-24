#include <iostream>

using namespace std;

class Integer
{
    int i,k,l;
    public:
    Integer(int x):i{x}{};
    Integer(int x,int y):i{x},k{y}{};
    Integer(int x,int y,int z):i{x},k{y},l{z}{};
    void display()
    {
        cout<<i<<' '<<k<<' '<<l<<' ';
    }

};

int main()
{
    cout<<"Please enter three numbers: ";
    int num1,num2,num3;
    cin>>num1>>num2>>num3;

    Integer a(num1);
    Integer b(num1,num2);
    Integer c(num1,num2,num3);

    cout<<"Value of first object is: ";
    a.display();
    cout<<'\n';

    cout<<"Value of second object is: ";
    b.display();
    cout<<'\n';

    cout<<"Value of third object is: ";
    c.display();
    cout<<'\n';
}