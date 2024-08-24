#include<iostream>

using namespace std;

class cls
{
    static int count;
public:
    static void put_count();
    cls();
    ~cls();

};


int cls::count;

cls::cls()
{
    count++;
}

cls::~cls()
{
    count--;
}

void cls::put_count()
{
    std::cout<<"Number of instantiated objects of cls is : "<<count<<std::endl;
}

int main()
{
    cls first;
    first.put_count();
    cls second;
    second.put_count();
    {
        cls third;
        third.put_count();
        {
            cls fourth;
            fourth.put_count();
        }
        third.put_count();
    }
    first.put_count();
}