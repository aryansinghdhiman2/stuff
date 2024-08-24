#include "My_string.h"
#include <cstring>
#include <iostream>
#include <cctype>
//constructor
My_string::My_string():str{new char[1]{'\0'}}{}
My_string::My_string(const char* src):str{nullptr}
{
    if(src==nullptr)
    {
        str=new char[1]{'\0'};
    }
    str=new char[strlen(src)+1];
    strcpy(str,src);
}
//copy constructor
My_string::My_string(const My_string &source):My_string(source.str){}
//move constructor
My_string::My_string(My_string &&source) noexcept
{
    str=source.str;
    source.str=nullptr;
}
//destructor
My_string::~My_string() {
    delete [] str;
}
//methods
void My_string::display() const
{
    std::cout<<str<<std::endl;
}
int My_string::get_length() const
{
    return(strlen(str));
}
//operator overloading
My_string &My_string::operator=(const My_string &rhs)
{
    if(this==&rhs)
        return *this;
    delete [] str;
    str=new char[strlen(rhs.str)+1];
    strcpy(str,rhs.str);
    return *this;
}
My_string &My_string::operator=(My_string &&rhs)
{
    if(this == &rhs)
        return *this;
    delete [] str;
    str=rhs.str;
    rhs.str=nullptr;
    return *this;
}
bool My_string::operator==(My_string &rhs) const
{
    if(strcmp(this->str,rhs.str)==0)
        return true;
    else
        return false;
}
My_string My_string::operator+(const My_string &rhs) const
{
    int len=strlen(this->str)+strlen(rhs.str)+1;
    char *buffer=new char[len];
    strcpy(buffer,this->str);
    strcat(buffer,rhs.str);
    My_string temp {buffer};
    delete [] buffer;
    return temp;
}
My_string My_string::operator-() const//make lowercase
{
    char *buffer=new char[strlen(this->str)+1];
    strcpy(buffer,this->str);
    for(int i=0;buffer[i]!='\0';i++)
    {
        buffer[i]=tolower(buffer[i]);
    }
    My_string temp {buffer};
    delete [] buffer;
    return temp;
}
std::ostream &operator<<(std::ostream &os,const My_string &rhs)
{
    os<<rhs.str;
    return os;
}
std::istream &operator>>(std::istream &is,My_string &rhs)
{
    char *buffer=new char[1000];
    is>>buffer;
    rhs=My_string(buffer);
    delete [] buffer;
    return is;
}
