#include <iostream>

using namespace std;

typedef void testFunc(int a);

void myFunc(int b)
{
    cout<<b<<endl;
}

void secondFunc(testFunc* funPtr)
{
    funPtr(5);
}

int main()
{
    // testFunc* myFuncPtr;
    // myFuncPtr = myFunc;
    // myFuncPtr(5);
    secondFunc(&myFunc);
    return 0;
}