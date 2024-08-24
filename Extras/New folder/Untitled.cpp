#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Employee
{
    protected:
    string name;
    int age;
    int salary;
    int year_of_service;
    public:
    Employee(string s,int a,int sal,int yos)
    :name{s},age{a},salary{sal},year_of_service{yos}{};
    virtual string get_name(){return name;}
    virtual int get_salary(){return salary;}
    virtual int get_age(){return age;}
    virtual int get_year_of_service(){return year_of_service;}
}; 

class Professor : virtual public Employee
{
    string subject;
    public:
    Professor(string s,int a,int sal,int yos,string sub)
    :Employee(s,a,sal,yos),subject{sub}{};
    virtual string get_subject(){return subject;};
};

class Attendant : virtual public Employee
{
    int lab;
    public:
    Attendant(string s,int a,int sal,int yos,int l)
    :Employee(s,a,sal,yos),lab{l}{};
    virtual int get_lab_no(){return lab;}
};
class Methods : public Professor, public Attendant
{
    public:
    Methods(string s,int a,int sal,int yos,string sub,int lab)
    :Employee(s,a,sal,yos),Professor(s,a,sal,yos,sub),Attendant(s,a,sal,yos,lab){}
    void display();
    void add_professor(vector<Professor> &vec);
    void add_attendant(vector<Attendant> &vec);
    void display_professor(vector<Professor> &vec);
    void display_attendant(vector<Attendant> &vec);
};

int main()
{
    Methods m{"name",23,2002,129,"sub",12};
    vector<Professor> professor_data;
    vector<Attendant> attendant_data;
    system("cls");
    m.display();
    char ch;
    bool invalid_input=false;
    for (;;)
    {
        invalid_input=false;
        cin >> ch;
        switch (ch)
        {
        case '0':
            m.display_professor(professor_data);
            break;
        case '1':
            m.display_attendant(attendant_data);
            break;
        case '2':
            m.add_professor(professor_data);
            break;
        case '3':
            m.add_attendant(attendant_data);
            break;
        case 'Q':
        case 'q':
            return 0;
            break;
        default:
            cout << "Invalid Input\n"
                 << "PLease Enter Again: ";
                 invalid_input=true;
            break;
        }
        if(!invalid_input)
            m.display();
    }
}

void Methods::display()
{
    cout<<setw(32)<<"Employee Management System"<<endl;
    cout<<"[0]View Professors"<<setw(22)<<"[1]View Attendants"<<endl;
    cout<<"[2]Add Professors"<<setw(22)<<"[3]Add Attendants"<<endl;
    cout<<setw(22)<<"[Q]Quit"<<endl;
    cout<<"Enter Character corresponding to input: ";
}

void Methods::add_professor(vector<Professor> &vec)
{
    string name,sub;
    int age,sal,yos;
    cout<<"Enter name for Professor: "<<endl;
    cin.ignore(500,'\n');
    getline(cin,name);
    cout<<"Enter Age: ";
    cin>>age;
    cout<<"Enter Salary: ";
    cin>>sal;
    cout<<"Enter Years of Service: ";
    cin>>yos;
    cin.ignore(500,'\n');
    cout<<"Enter Subject of professor: "<<endl;
    getline(cin,sub);

    Professor temp(name,age,sal,yos,sub);
    vec.push_back(temp);
    system("cls");
}

void Methods::add_attendant(vector<Attendant> &vec)
{
    string name;
    int age,sal,yos,lab;
    cout<<"Enter name for Attendant: "<<endl;
    cin.ignore(500,'\n');
    getline(cin,name);
    cout<<"Enter Age: ";
    cin>>age;
    cout<<"Enter Salary: ";
    cin>>sal;
    cout<<"Enter Years of Service: ";
    cin>>yos;
    cout<<"Enter Lab no. : ";
    cin>>lab;

    Attendant temp(name,age,sal,yos,lab);
    vec.push_back(temp);
    system("cls");
}

void Methods::display_professor(vector<Professor> &vec)
{
    system("cls");
    for(auto it=vec.begin();it!=vec.end();it++)
    {
        cout<<"Name: "<<it->get_name()<<endl;
        cout<<"Age: "<<it->get_age()<<endl;
        cout<<"Salary: "<<it->get_salary()<<endl;
        cout<<"Years of Service: "<<it->get_year_of_service()<<endl;
        cout<<"Subject: "<<it->get_subject()<<endl<<endl;
    }
    char ch;
    cout<<"Enter any character to go back: ";
    cin>>ch;
    system("cls");

}

void Methods::display_attendant(vector<Attendant> &vec)
{
    system("cls");
    for(auto it=vec.begin();it!=vec.end();it++)
    {
        cout<<"Name: "<<it->get_name()<<endl;
        cout<<"Age: "<<it->get_age()<<endl;
        cout<<"Salary: "<<it->get_salary()<<endl;
        cout<<"Years of Service: "<<it->get_year_of_service()<<endl;
        cout<<"Lab No.: "<<it->get_lab_no()<<endl<<endl;
    }
    char ch;
    cout<<"Enter any character to go back: ";
    cin>>ch;
    system("cls");
}