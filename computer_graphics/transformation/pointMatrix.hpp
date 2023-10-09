#include <cassert>
#include <array>

template<unsigned int n,unsigned int m>
class myMatrix
{
    public:
    std::array<std::array<int,m>,n> matrix;
    myMatrix(std::initializer_list<std::array<int,m>> list)
    {
        assert((list.size()==this->matrix.size()));
        std::copy(list.begin(),list.end(),matrix.begin());
    }
    myMatrix(){};

    template<unsigned int a,unsigned int b>
    myMatrix<n,b> operator*(const myMatrix<a,b>& other)
    {
        assert(m==a);
        
        myMatrix<n,b> result;

        for(unsigned i=0;i<n;i++)
        {
            for(unsigned j=0;j<b;j++)
            {
                int sum = 0;
                for(unsigned k=0;k<m;k++)
                {
                    sum+=this->matrix.at(i).at(k) * other.matrix.at(k).at(j);
                }
                result.matrix.at(i).at(j) = sum;
            }
        }

        return result;
    }
};