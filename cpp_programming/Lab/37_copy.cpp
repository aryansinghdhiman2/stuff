#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream src("37_source.txt");
    ofstream dest("37_destination.txt");

    try
    {
        if (!src.is_open())
        {
            throw -1;
        }
        if (!dest.is_open())
        {
            throw '1';
        }
        cout << "Starting Copy operation\n";
        string temp_str;
        while (getline(src, temp_str))
        {
            dest << temp_str<<endl;
        }
        cout << "Copy operation finished\n";
    }
    catch (const int x)
    {
        cout << "Source file could not be opened\n";
    }
    catch (const char c)
    {
        cout << "Destination file could not be opened\n";
    }
}