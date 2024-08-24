#include<iostream>
using namespace std;
class INTEGER;
class FLOAT
{   
    public:
    float x;
    friend float average(INTEGER, FLOAT);
    FLOAT(float x1)
    {
        x=x1;
    }
};
class INTEGER
{    
    public:
    float y;
    friend float average (INTEGER,FLOAT);
    INTEGER(int y1)
    {
        y=y1;
    }
};
float average (INTEGER a, FLOAT b)
{
    float avg= (float)(a.y+b.x)/2;
    return avg;
}
int main()
{
    int i;
    float f;
    cout<<"Enter an Integer: ";
    cin>>i;
    cout<<"Enter a Float: ";
    cin>>f;
    INTEGER r(i);
    FLOAT q(f);
    cout << "Average of the two is :"<<average(r,q);
}