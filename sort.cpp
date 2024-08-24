#include <iostream>
#include <vector>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void display(const vector<int> &v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<i<<'|'<<setw(v.at(i)+1)<<setfill('-')<<v.at(i)<<'\n';
    }
    cout<<" |__________\n";
}

void display(const vector<int> &v,int color_code,int pos)
{
    for(int i=0;i<v.size();i++)
    {
        if(i==pos)
            SetConsoleTextAttribute(hConsole,color_code);
        cout<<i<<'|'<<setw(v.at(i)+1)<<setfill('-')<<v.at(i)<<'\n';
        if(i==pos)
            SetConsoleTextAttribute(hConsole,15);
    }
    cout<<" |__________\n";
}

void display(const vector<int> &v,int color_code_1,int pos_1,int color_code_2,int pos_2)
{
    for(int i=0;i<v.size();i++)
    {
        if(i==pos_1)
            SetConsoleTextAttribute(hConsole,color_code_1);
        if(i==pos_2)
            SetConsoleTextAttribute(hConsole,color_code_2);
        cout<<i<<'|'<<setw(v.at(i)+1)<<setfill('-')<<v.at(i)<<'\n';
        if(i==pos_1 || i==pos_2)
            SetConsoleTextAttribute(hConsole,15);
    }
    cout<<" |______________________________________________________________________________\n";
}


int main()
{
    vector<int> vec;

    cout<<"Enter size of array: ";
    int size;
    cin>>size;
    cout<<"Enter the elements\n";
    for(int j=0;j<size;j++)
    {
        int temp;
        cin>>temp;
        vec.push_back(temp);
    }

    int checker=0,l=0;

    system("cls");
    display(vec,15,-1);
    this_thread::sleep_for(std::chrono::seconds {2});
    
    for(;;)
    {
        for(l=0,checker=0;l<(vec.size()-1);l++)
        {
            system("cls");
            display(vec,9,l,9,l+1);
            this_thread::sleep_for(std::chrono::seconds {2});

            if(vec.at(l)>vec.at(l+1))
            {
                system("cls");
                display(vec,12,l,12,l+1);
                this_thread::sleep_for(std::chrono::seconds {2});

                int temp=vec.at(l);
                vec.at(l)=vec.at(l+1);
                vec.at(l+1)=temp;

                system("cls");
                display(vec,12,l,12,l+1);
                this_thread::sleep_for(std::chrono::seconds {2});
            }
            else 
                checker++;

            system("cls");
            display(vec);
        }
        if(checker==vec.size()-1)
            break;
    }
}