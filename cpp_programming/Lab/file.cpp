#include <iostream>
#include <array>

int main()
{
    std::array<int,10000> arr;
    static int a=0;
    a+=1;
    std::cout<<a<<std::endl;
    main();

    return 0;
}
