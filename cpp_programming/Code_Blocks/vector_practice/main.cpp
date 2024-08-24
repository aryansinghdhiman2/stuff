#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vector_1{};
    vector<int> vector_2{};

    vector_1.push_back(10);
    vector_1.push_back(20);

    vector_2.push_back(100);
    vector_2.push_back(200);

    cout<<"Elements in vector 1 are:"<<endl;
    cout<<vector_1.at(0)<<endl;
    cout<<vector_1.at(1)<<endl;
    cout<<"Size of vector 1 is: "<<vector_1.size()<<endl<<endl;

    cout<<"Elements in vector 2 are:"<<endl;
    cout<<vector_2.at(0)<<endl;
    cout<<vector_2.at(1)<<endl;
    cout<<"Size of vector 2 is: "<<vector_2.size()<<endl<<endl;

    vector<vector<int>>vector_2D{};
    vector_2D.push_back(vector_1);
    vector_2D.push_back(vector_2);

    cout<<"Elements in 2D vector are:"<<endl;
    cout<<vector_2D.at(0).at(0)<<" ";
    cout<<vector_2D.at(0).at(1)<<endl;
    cout<<vector_2D.at(1).at(0)<<" "<<vector_2D.at(1).at(1)<<endl;

    vector_1.at(0)=1000;

    cout<<"\nElements in 2D vector are:"<<endl;
    cout<<vector_2D.at(0).at(0)<<" ";
    cout<<vector_2D.at(0).at(1)<<endl;
    cout<<vector_2D.at(1).at(0)<<" "<<vector_2D.at(1).at(1)<<endl;

    cout<<"\nElements in vector 1 are:"<<endl;
    cout<<vector_1.at(0)<<endl;
    cout<<vector_1.at(1)<<endl;
    cout<<"Size of vector 1 is: "<<vector_1.size()<<endl<<endl;
    return 0;
}
