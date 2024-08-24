#include "file.h"
#include<iostream>
file::file(std::string location)
{
    this->f.open(location,std::ios::in | std::ios::out | std::ios::binary);
}


file::~file()
{
    this->f.close();
}


std::string file::get_line()
{
    std::string input,temp;
    while(std::getline(this->f,temp))
    {
        input=input+"\n"+temp;
    }
    return input;
}

void file::close()
{
    this->f.close();
}

long long file::find(std::string to_be_found)
{
    std::string temp;
    long long location=0;
    char store;

    f.clear();
    f.seekg(0);
    while((this->f))
    {
        while(this->f.get(store))
        {
            if((store!='\r'))
            {
                if(store!='\n')
                {
                    temp=temp+store;
                }
            }
            else if((store=='\r'))
            {
                if(store=='\n')
                    break;
                break;
            }
        }
        if(temp==to_be_found)
        {
            location=this->f.tellg();
            break;
        }
        temp.clear();

    }
    return location;
}
