#include "movie.h"
#include <iostream>
//constructor
movie::movie(std::string str,enum rating rat,int num):name{str},movie_rating{rat},num_watch{num}{}
//copy constructor
movie::movie(const movie &src)
{
    this->name=src.name;
    this->movie_rating=src.movie_rating;
    this->num_watch=src.num_watch;
}
/*destructor would be default*/
//methods
//getters
std::string movie::get_name() const
{
    return this->name;
}
enum rating movie::get_rating() const
{
    return this->movie_rating;
}
int movie::get_num_watch() const
{
    return this->num_watch;
}
//setters
std::string movie::set_name(const std::string str)
{
    this->name=str;
    return this->name;
}
enum rating movie::set_rating(const enum rating source)
{
    this->movie_rating=source;
    return this->movie_rating;
}
int movie::inc_num_watch()
{
    this->num_watch++;
    return this->num_watch;
}
//display method
void movie::display()
{
    std::cout<<"Movie Name: "<<this->name<<" Rating: ";
    if(this->movie_rating==G)
        std::cout<<"G";
    else if(this->movie_rating==PG)
        std::cout<<"PG";
    else if(this->movie_rating==PG_13)
        std::cout<<"PG-13";
    else if(this->movie_rating==R)
        std::cout<<"PG";
    std::cout<<" Watch Frequency: "<<this->num_watch<<std::endl;

}

