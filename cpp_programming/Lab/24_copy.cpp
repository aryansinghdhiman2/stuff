#include <iostream>

using namespace std;

class Integer
{
    int i;
    static int count;
    public:
    Integer(){
        count++;
        cout<<"\nDefault constructor called for: "<<count<<endl;
        }
    ~Integer(){
        cout<<"\nDefault destructor called for: "<<count;
        count--;
        }
    Integer(const Integer &I){
        this->i=I.get_data();
        count++;
        cout<<"\nCopy constructor called for : "<<count<<endl;
    }
    void set_data(int x){i=x;};
    int get_data() const {return i;};
    static int get_count()
    {
        return count;
    }
};

int Integer::count;

int main()
{
    int num;
    cout<<"Enter a number : ";
    cin>>num;
   
    Integer a;
    a.set_data(num);
    cout<<"Value of Object Initialized by Default Constructor is : "<<a.get_data()<<endl;
   
    Integer b{a};
    cout<<"Value of Object Intialized by Copy Constructor is : "<<b.get_data()<<endl;

}