#include <iostream>

using namespace std;
//typecast
int main()
{
    
    float a,b;
    int c{0},d{0};
    
    cout<<"Enter two Floating Point Numbers: ";
    cin>>a>>b;
    cout<<"Numbers after Typecasting are: \n";

    c=(int)a;//explicit
    d=(b);//impiicit
    cout<<"Explicit typecast: "<<c<<'\n';
    cout<<"Implicit typecast: "<<d<<'\n';

    return 0;
}