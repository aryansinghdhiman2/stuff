#include<iostream>
using namespace std;
   // demonstrating multiple catch and throw + default exception
void test(int x) {
    try {
        if (x > 0)
            throw x;   //int
        else if(x==0)
            throw 'x';   //char
         else
         throw 1.0;      //double
    } catch (int j) {
        cout << "Caught a  integer :" << x<<endl;
    } catch (char i) {
        cout << "Caught a character : " << i<<endl;
        throw i;
    } catch(...){
        cout<<"Default exception"<<endl;
    }
}
 int  main() {
    try{
    cout << "Testing multiple catches:\n";
    test(10);
    test(-1);
    test(0);
    }
    catch(char c)
    {
        cout<<"Caught Rethrown Exception\n";
    }
return 0;
}