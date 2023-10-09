#include "./pointMatrix.hpp"
#include <iostream>

using namespace std;

int main()
{
    myMatrix<2,3> m({{1,2,2},
                     {4,2,3}});

    myMatrix<3,2> a({{1,2},
                     {2,3},
                     {4,5}});

    myMatrix<2,2> c = m*a;
    // m*a;
}
