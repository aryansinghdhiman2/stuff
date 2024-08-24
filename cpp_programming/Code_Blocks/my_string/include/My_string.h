#ifndef MY_STRING_H
#define MY_STRING_H
#include <iostream>

class My_string
{
    friend std::ostream &operator<<(std::ostream &os,const My_string &rhs);
    friend std::istream &operator>>(std::istream &is,My_string &rhs);
    private:
        char* str;
    public:
        //constructors
        My_string();
        My_string(const char *src);
        //copy constructor
        My_string(const My_string &source);
        //move constructor
        My_string(My_string &&source) noexcept;
        //destructor
        ~My_string();
        //methods
        void display() const;
        int get_length() const;
        //operator overloading
        My_string &operator=(const My_string &rhs);
        My_string &operator=(My_string &&rhs);
        bool operator==(My_string &rhs) const;
        My_string operator+(const My_string &rhs) const;
        My_string operator-() const;//make lowercase
};

#endif // MY_STRING_H
