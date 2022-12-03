#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

class Book
{
    string title;
    string author;
    string description;
    public:
    Book(string t,string a,string d):title{t},author{a},description{d}{};
    Book(fstream &input)
    {
        getline(input,title);
        getline(input,author);
        getline(input,description);
    }
    string get_title(){return title;}
    string get_author(){return author;}
    string get_description(){return description;}
};

void display_menu()
{
    cout<<setw(18)<<"Library"<<endl;
    cout<<"[0]View Books"<<setw(15)<<"[1]Add Book"<<endl;
    cout<<"[2]Edit Book"<<setw(19)<<"[3]Delete Book"<<endl;
    cout<<setw(18)<<"[Q]Quit"<<endl;
    cout<<"Enter character corresponding to action: ";
}

void view_books(vector<Book>& vec)
{
    int book_num;
    for(auto it=vec.begin();it!=vec.end();it++)
    {
        cout<<"Name: "<<it->get_title();
        cout<<"Author: "<<it->get_author();
        cout<<"Description: "<<it->get_description();
    }
    cout<<"Enter any character to go back: ";
    char ch;
    cin>>ch;

}

void add_book(vector<Book>& vec)
{
    string t,a,d;
    cout<<"Enter Title of Book:"<<endl;
    getline(cin,t);
    cout<<"Enter Author of Book:"<<endl;
    getline(cin,a);
    cout<<"Enter Desrciption for Book:"<<endl;
    getline(cin,d);

    Book temp(t,a,d);

    vec.push_back(temp);

}

void edit_book(vector<Book>& vec)
{
    int i,book_num;
    for(auto it=vec.begin();it!=vec.end();it++)
    {
        cout<<'['<<i<<']'<<it->get_title();
    }
    cout<<"Select Book: ";
    cin>>book_num;
    string t,a,d;
    cout<<"Enter Title of Book:"<<endl;
    cin.ignore(500,'\n');
    getline(cin,t);
    cout<<"Enter Author of Book:"<<endl;
    getline(cin,a);
    cout<<"Enter Desrciption for Book:"<<endl;
    getline(cin,d);

    vec.at(book_num)=Book(t,a,d);
}

void delete_book(vector<Book>& vec)
{
    int i,book_num;
    for(auto it=vec.begin();it!=vec.end();it++)
    {
        cout<<'['<<i<<']'<<it->get_title();
    }
    cout<<"Select Book: ";
    cin>>book_num;
    auto it=vec.begin()+book_num;
    vec.erase(it);
}

int main()
{

    vector<Book> book_holder;
    fstream f("lib.txt",ios::in|ios::app|ios::out);

    while(f)
    {
        Book temp(f);
        book_holder.push_back(temp);
    }
    display_menu();
    char ch;
    for(;;)
    {
        cin>>ch;
        switch (ch)
        {
        case '0':
            view_books(book_holder);
            break;
        case '1':
            add_book(book_holder);
            break;
        case '2':
            edit_book(book_holder);
            break;
        case '3':
            delete_book(book_holder);
            break;
        case 'q':
        case 'Q':
            return 0;
        }
        system("cls");
        display_menu();
    }
}

