#include <iostream>

using namespace std;


void tower(const int disk,const int from,const int aux,const int to)
{
    if(disk < 1)
    {
        return;
    }

    tower(disk-1,from,to,aux);
    cout<<from<<" to "<<to<<endl;
    tower(disk-1,aux,from,to);
}

int main()
{
    tower(3,1,2,3);
}