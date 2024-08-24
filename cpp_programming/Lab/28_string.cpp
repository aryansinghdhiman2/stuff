#include <iostream>
#include <cstring>
#include <iomanip>
#include <string>
using namespace std;

class String
{
    char* str;
public:
    String(char* temp)
    {
        if(temp==nullptr)
        {
            str=new char[1];
            *str='\0';
        }
        else
        {
            str=new char[strlen(temp)+1];
            strcpy(str,temp);
        }
    }

    char* get_string() const {return str;};

    String& operator+(const String& S)
    {
        strcat(this->str,S.get_string());
        return *this;
    }

    bool operator<(const String& S)
    {
        if(strcmp(this->str,S.get_string())<0)
        {
            return true;
        }
        else 
            return false;
    }
    bool operator>(const String& S)
    {
         if(strcmp(this->str,S.get_string())>0)
        {
            return true;
        }
        else 
            return false;
    }
    bool operator==(const String& S)
    {
        if(strcmp(this->str,S.get_string())==0)
            return true;
        else 
            return false;
    }
    friend ostream& operator<<(ostream &os,String str);
};

ostream& operator<<(ostream &os,const String str)
{
    os<<str.get_string();
    return os;
}

int main()
{
    char* str_1=new char[70];
    char* str_2=new char[70];

    cout<<"Enter first string"<<endl;
    cin.getline(str_1,69);
    cout<<"Enter the second string"<<endl;
    cin.getline(str_2,69);

    String first(str_1);
    String second(str_2);

    delete [] str_1;
    delete [] str_2;

    cout<<"Concatenating the strings :"<<(first+second)<<endl;
    cout<<boolalpha;
    cout<<"Is first string greater than second string :"<<(first>second)<<endl;
    cout<<"Is first string smaller than second string :"<<(first<second)<<endl;
    cout<<"Is first string equal to second string :"<<(first==second)<<endl;
}