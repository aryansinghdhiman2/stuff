#include<iostream>
using namespace std;
int foof(int x);
int fung(int x);

int main()
{
    int x=5,y=10,count;
    for(count=1;count<=2;count++)
    {
        y+=foof(x)+fung(x);
        cout<<y;
    }
}

int foof(int x)
{
    int y=fung(x);
    return y;
}



int fung(int x)
{
    static int y=10;
    y=y+1;
    return (y+x);
}