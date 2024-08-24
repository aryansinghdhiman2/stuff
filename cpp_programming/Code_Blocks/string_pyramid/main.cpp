#include <iostream>

using namespace std;

int main()
{
    string input{};
    cin>>input;
    int whitespace=(input.length())-1;
    for(const char c:input)
    {
        for(int t=whitespace;t>0;t--)
        {
            cout<<" ";
        }
        whitespace--;
        int a=1,i=0;
        size_t k=0;
        while(i>=0)
        {
            if(k==input.find(c))
            {
                a=-1;
            }
            cout<<input.at(i);
            i=i+a;
            k++;
        }
        cout<<endl;
    }


    return 0;
}
