#include <iostream>
#include <string>
using namespace std;

int main()
{
    string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
    string cypher{"qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"};

    cout<<"Enter text to be encrypted: ";
    string input;
    getline(cin,input);

    string encrypt;
    size_t a;
    for(const char c: input)
    {
        a=alphabet.find(c);
        if(a!=string::npos)
        {
            encrypt.push_back(cypher.at(a));
        }
        else
        {
            encrypt.push_back(c);
        }
    }
    cout<<endl<<"Encrypted text is: "<<encrypt<<endl;

    string decrypt;
    cout<<endl<<"Decrypted text is : ";
    a=0;
    for(const auto j:encrypt)
    {
        a=cypher.find(j);
        if(a!=string::npos)
        {
            decrypt.push_back(alphabet.at(a));
        }
        else
        {
            decrypt.push_back(j);
        }
    }
    cout<<decrypt<<endl;
    if(decrypt==input)
    {
        cout<<endl<<"Decryption was successful"<<endl;
    }


    return 0;
}
