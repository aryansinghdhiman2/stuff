#include <iostream>

using namespace std;

class Integer
{
    int i;
    public:
    Integer(int x=0){i=x;};
    int operator+(){
        if(this->i<0)
            i=i*(-1);
        return i;
    };
    int get_data(){return i;}
};

int main()
{
    cout<<"Please Enter a negative number: ";
    int num;
    for(;;)
    {
        cin>>num;
        if(num>=0)
        {
            cout<<"Please Enter a Negative number: ";
        }
        else 
            break;
    }

    Integer a(num);
    cout<<"Value of a is "<<a.get_data()<<"\n";
    +a;
    cout<<"Value of a after using unary + operator : "<<a.get_data()<<"\n";
}