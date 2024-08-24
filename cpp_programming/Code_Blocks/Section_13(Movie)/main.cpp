#include <iostream>
#include "movie.h"
#include "movies.h"

using namespace std;

int main()
{
    cout << "Enter three Movies" << endl<<endl;
    movies m;

    string temp_1;
    enum rating temp_2;
    int temp_3;
    for(int i=0;i<3;i++)
    {
        cout<<"Enter name: ";
        cin>>temp_1;
        cout<<"Enter Rating: ";
        cin>>temp_3;
        temp_2=(rating)temp_3;
        cout<<"Enter Watch Frequency: ";
        cin>>temp_3;

        m.add_mov(temp_1,temp_2,temp_3);
        cout<<"*******************************************************************"<<endl;
    }
    m.inc_mov("Bat");
    m.display_all();
    return 0;
}
