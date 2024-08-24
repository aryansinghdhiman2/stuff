#include <iostream>
using namespace std;

int main()
{
    int var=20;
    int* ip;
    ip=&var;

    cout<<"Address stored in var variable: "<<&var<<'\n';
    cout<<"Address stored in ip variable: "<<ip<<'\n';
    cout<<"Value of *ip variable: "<<(*ip)<<endl;

    return 0;
}