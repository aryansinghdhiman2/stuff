#include <iostream>
using namespace std;
int main()
{
    int sparseMat[4][5] =
    {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
    };
    int size = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMat[i][j] != 0)
                size++;
    int compMat[3][size];
    int k = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMat[i][j] != 0)
            {
                compMat[0][k] = i;
                compMat[1][k] = j;
                compMat[2][k] = sparseMat[i][j];
                k++;
            }
    cout << "Row\tColumn\tValue" << endl;
    for (int i=0; i<size; i++)
    {
        cout << compMat[0][i] << "\t" << compMat[1][i] << "\t" << compMat[2][i];
        cout <<"\n";
    }
    return 0;
}