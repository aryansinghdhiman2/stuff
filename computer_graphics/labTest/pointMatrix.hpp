#include <cassert>
#include <array>

template<unsigned int n,unsigned int m>
class pointMatrix
{
    public:
    std::array<std::array<double,m>,n> matrix;
    pointMatrix(std::initializer_list<std::array<double,m>> list)
    {
        assert((list.size()==this->matrix.size()));
        std::copy(list.begin(),list.end(),matrix.begin());
    }
    pointMatrix(){};

    std::array<double,m> at(unsigned i)
    {
        return this->matrix.at(i);
    }

    template<unsigned int a,unsigned int b>
    pointMatrix<n,b> operator*(const pointMatrix<a,b>& other)
    {
        assert(m==a);
        
        pointMatrix<n,b> result;

        for(unsigned i=0;i<n;i++)
        {
            for(unsigned j=0;j<b;j++)
            {
                double sum = 0;
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