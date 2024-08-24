#include <iostream>

using namespace std;

template <class T>
class MyVector
{
    T* arr;
    int position;
    public:
    MyVector(void)
    {
        arr=new T[1];
        position=0;
    };
    ~MyVector()
    {
        delete [] arr;
    }
    void push_back(T input)
    {
        T *temp=new T[position+1];
        for(int i=0;i<position;i++)
        {
            temp[i]=arr[i];
        }
        temp[position]=input;
        position++;
        
        delete [] arr;
        arr=new T[position];
        for(int i=0;i<position;i++)
        {
            arr[i]=temp[i];
        }
        delete [] temp;

    }
    void pop_back()
    {
        T *temp=new T[position-1];
        for(int i=0;i<(position-1);i++)
        {
            temp[i]=arr[i];
        }
        delete [] arr;
        position--;

        arr=new T[position];
        for(int i=0;i<position;i++)
        {
            arr[i]=temp[i];
        }
    }
    T at(int x)
    {
        try
        {
            if(x<0)
            {
                throw -1;
            }
            else if(x>=position)
            {
                throw '1';
            }
            else
            {
                return arr[x];
            }
        }
        catch(const int x)
        {
            std::cout<<"Out of bounds(underflow)" << '\n';
            throw -1;
        }
        catch(const char c)
        {
            std::cout<<"Out of bounds(overflow)"<<'\n';
            throw '1';
        }
        return 0;
    }
};

int main()
{
    MyVector<int> vec;
    cout<<"Pushing 10 and 12 to the first vector: \n";
    vec.push_back(10);
    vec.push_back(12);

    cout<<vec.at(0)<<" "<<vec.at(1)<<endl;

    cout<<"Removing 12 and adding 15 to the first vector: \n";
    vec.pop_back();
    vec.push_back(15);
    cout<<vec.at(0)<<" "<<vec.at(1)<<endl;

    cout<<"Pushing a and b to the second vector: \n";
    MyVector<char> vec_2;
    vec_2.push_back('a');
    vec_2.push_back('b');

    cout<<vec_2.at(0)<<" "<<vec_2.at(1)<<endl;

    cout<<"Removing b and adding v to the first vector: \n";
    vec_2.pop_back();
    vec_2.push_back('v');
    cout<<vec_2.at(0)<<" "<<vec_2.at(1)<<endl;

}