#ifndef FILE_H
#define FILE_H
#include<fstream>
#include<string>
#include<memory>

class file
{
private:
    std::fstream f;
public:
    file(std::string location);
    ~file();
    //methods
    void close();
    std::string get_line();
    long long find(std::string);
};

#endif // FILE_H
