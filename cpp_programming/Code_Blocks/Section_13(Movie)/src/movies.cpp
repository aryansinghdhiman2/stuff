#include "movies.h"
#include<iostream>
bool movies::add_mov(std::string n,enum rating r,int w)
{
    for(size_t i=0;i<list.size();i++)
    {
        if(list.at(i).get_name()==n)
        {
            std::cout<<"Movie already exists"<<std::endl;
            return 0;
        }
    }
    list.push_back(movie {n,r,w});
    return 1;
}
int movies::inc_mov(std::string str)
{
    for(size_t i=0;i<list.size();i++)
    {
        std::string temp=list.at(i).get_name();
        if(str==temp)
        {
            list.at(i).inc_num_watch();
            return list.at(i).get_num_watch();
        }
        else if(list.size()==i+1)
        {
            std::cout<<"Cannot find given movie"<<std::endl;
            return 0;
        }
    }
    return 0;
}
void movies::display_all()
{
    for(size_t i=0;i<list.size();++i)
    {
        list.at(i).display();
    }
}
