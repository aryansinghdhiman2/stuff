#include <iostream>
#include <file.h>
using namespace std;

int main()
{
    file test("test.txt");
    cout<<test.get_line();

    cout<<"\n";
    int num=test.find("find");
    cout<<"\"find\" was found at "<<num<<endl;
    test.close();
    cout<<"\ntest.txt has been closed\n";

    return 0;
}

