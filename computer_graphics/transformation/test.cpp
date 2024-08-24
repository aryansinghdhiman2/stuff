#include "./pointMatrix.hpp"
#include <iostream>

using namespace std;

int main()
{
    pointMatrix<2,3> m({{1,2,2},
                     {4,2,3}});

    pointMatrix<3,2> a({{1,2},
                     {2,3},
                     {4,5}});

    auto c = m*a;
}
