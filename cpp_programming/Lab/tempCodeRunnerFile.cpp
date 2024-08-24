#include <iostream>

using namespace std;

template <typename T>
class Vector
{
	T* data;
	int position;
	public:
	Vector(void)
	{
		data=new T[1];
		position=0;
	}
	~Vector()
	{
		delete [] data;
	}
	T push_back(T val)
	{
		T *temp=new T[position+1];
        for(int i=0;i<position;i++)
        {
            temp[i]=data[i];
        }
        temp[position]=val;
        position++;
        
        delete [] data;
        data=new T[position];
        for(int i=0;i<position;i++)
        {
            data[i]=temp[i];
        }
        delete [] temp;
        return val;
	}
	T modify(int x,T val)//to modify value
	{
		try
		{
			if(x>position || x<0)
			{
				throw -1;
			}
			else
			{
				data[x]=val;
				return data[x];
			}
		}
		catch(const int num)
		{
			cout<<"Out of Bounds Error\n";
			throw -1;
		}
	}
	void display()
	{
		for(int i=0;i<position;i++)
		{
			cout<<data[i]<<' ';
		}
		cout<<endl;
	}
	void multiply(T x)
	{
		for(int i=0;i<position;i++)
		{
			data[i]*=x;
		}
	}
};

int main()
{
	Vector<int> vec;
	vec.push_back(12);
	vec.push_back(3);
	vec.push_back(5);
	
	vec.modify(1,13);
	
	vec.display();
}