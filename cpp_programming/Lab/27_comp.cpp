#include <iostream>

using namespace std;

class Complex
{
    int real;
    int imaginary;

    public:
    Complex(int a=0,int b=0):real(a),imaginary(b){};
    int get_real() const {return this->real;}
    int get_imaginary() const{return this->imaginary;}
    void display()
    {
        cout<<real<<" + "<<imaginary<<"i\n";
    }
    Complex& operator+(const Complex &x)
    {
        this->real+=x.get_real();
        this->imaginary+=x.get_imaginary();
        return *this;
    }
};

int main()
{
    int a,b;
    cout<<"Enter 1st Complex Number: ";
    cin>>a>>b;
    Complex first(a,b);
    cout<<"Enter 2nd Complex Number: ";
    cin>>a>>b;
    Complex second(a,b);
    first=first+second;
    cout<<"Sum of the two complex numbers is : ";
    first.display();
    cout<<"\n";
}