#include <iostream>

using namespace std;

class default_behaviour
{
    public:
        int number;
        default_behaviour(){
            number=0;
            cout<<"Default Constructor Called\n";
        }
        ~default_behaviour()
        {
            cout<<"Default Destructor Called\n";
        }
};

int main()
{
    {
    default_behaviour d;
    cout<<"Value of number in default_behaviour class has been initialized to 0 by default constructor\n";
    cout<<"Value of number is : "<<d.number<<"\n";
    }
    
    return 0;

}