#include <iostream>

using namespace std;

void swap_int(int &a,int &b);
void swap_char(char &c,char &b);

int main()
{
    int num_1,num_2;
    char char_1,char_2;

    cout<<"Please enter two integers"<<endl;
    cin>>num_1>>num_2;
    cout<<"Before Swapping: First Integer is: "<<num_1<<" ,Second Integer is: "<<num_2<<endl;

    swap_int(num_1,num_2);

    cout<<"After Swapping: First Integer is: "<<num_1<<" ,Second Integer is: "<<num_2<<"\n"<<endl;

    cout<<"Please enter two characters"<<endl;
    cin>>char_1>>char_2;
    cout<<"Before Swapping: First Character is: "<<char_1<<" ,Second Character is: "<<char_2<<endl;

    swap_char(char_1,char_2);

    cout<<"After Swapping: First Character is: "<<char_1<<" ,Second Character is: "<<char_2<<endl;
    return 0;
}

void swap_int(int &num_1,int &num_2)
{
    int temp{num_1};
    num_1=num_2;
    num_2=temp;
}

void swap_char(char &char_1,char &char_2)
{
    char temp{char_1};
    char_1=char_2;
    char_2=temp;
}
