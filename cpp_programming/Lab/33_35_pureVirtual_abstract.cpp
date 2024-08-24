#include <iostream>
#include <iomanip>
using namespace std;

//Abstract Class for menus
class Menu
{
    public:
    virtual void display()=0;
};

class MainMenu : public Menu
{
    public:
    void display()
    {
        cout<<setw(20)<<setfill('*')<<'*'<<endl;
        cout<<"You are in Main Menu\n";
        cout<<setw(20)<<'*'<<endl;
    }
};

int main()
{
    MainMenu menu;
    cout<<"\n\n\n";
    menu.display();

}