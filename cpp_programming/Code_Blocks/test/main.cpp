//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//
//int main()
//{
//    fstream f;
//    f.open("test.txt",ios::in);
//    string line;
//    int tell;
//
//    while(f)
//    {
//        getline(f,line);
//        cout<<line<<"\n";
//        if(f.tellg()!=(-1))
//        {
//            cout<<"\nLOGIC\n";
//        }
//        tell=f.tellg();
//        //cout<<tell<<"\n";
//    }
//
//    return 0;
//}
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    vector<int> temp;
    stringstream stream(str);
    int temp_num=0,temp_char;
    for(;stream;)
    {
        stream>>temp_num;
        temp.push_back(temp_num);
        if(!stream)
            break;
        stream>>temp_char;
    }
    return temp;

}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}
