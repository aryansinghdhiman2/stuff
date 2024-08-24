#include <iostream>

using namespace std;

union test
{
    int i;
    char c;
    float f;
}t;

int main()
{
   t.i=30;
   t.c=27;
   t.f=39.32;

   cout<<t.i<<"\t"<<t.c<<"\t"<<t.f;

    return 0;
}
