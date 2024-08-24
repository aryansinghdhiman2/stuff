#include <iostream>

using namespace std;

class Centimeter;

class Meter
{
    float meter;
    public:
    Meter(float x):meter{x}{};//data type to class
    float get_meter()
    {
        return meter;
    }
};

class Centimeter
{
    float centimeter;
    public:
    Centimeter(float y):centimeter{y}{};//data type to class
    Centimeter(Meter o)//class to class
    {
        centimeter=(o.get_meter())*100;
    }
    operator float()//class to data type
    {
        return centimeter;
    }
    float get_centimeter()
    {
        return centimeter;
    }
};

int main()
{
    float input;
    cout<<"Enter Length in Meters: ";
    cin>>input;

    Meter m=input;
    Centimeter cm=m;

    float result=cm;

    cout<<"Length in centimeters is: "<<result<<endl;;
}

