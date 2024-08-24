#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int character=0,line=0,words=0;
    ifstream input_file("38_file.txt");

    try
    {
        if(!input_file.is_open())
        {
            throw -1;
        }
        else
        {
            string temp_string;
            while(getline(input_file,temp_string))
            {
                line++;
                for(unsigned int i=0;i<temp_string.size();i++)
                {
                    if(temp_string.at(i)==' ' || (i==(temp_string.size()-1)))
                    {
                        words++;
                    }
                    if(temp_string.at(i)!=' ')
                    {
                        character++;
                    }
                }
            }
            cout<<"Number of Lines are : "<<line<<"\nNumber of words are : "<<words<<"\nNumber of characters are: "<<character<<endl;
        }
    }
    catch(const int x)
    {
        std::cout << "Could not open file" << '\n';
    }
    

}