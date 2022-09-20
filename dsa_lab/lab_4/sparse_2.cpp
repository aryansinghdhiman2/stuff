#include <iostream>
using namespace std;
int main()
{
    int sparseMat1[4][5] =
    {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
    };
    int sparseMat2[4][5] =
    {
        {0 , 0 , 4 , 0 , 3 },
        {0 , 0 , 1 , -1 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 6 , 2 , 0 , 0 }
    };
    int size1 = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMat1[i][j] != 0)
                size1++;
    int compMat1[3][size1];
    int k = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMat1[i][j] != 0)
            {
                compMat1[0][k] = i;
                compMat1[1][k] = j;
                compMat1[2][k] = sparseMat1[i][j];
                k++;
            }
    cout << "1st Sparse Matrix:" << endl;
    cout << "Row\tColumn\tValue" << endl;
    for (int i=0; i<size1; i++)
    {
        cout << compMat1[0][i] << "\t" << compMat1[1][i] << "\t" << compMat1[2][i];
        cout <<"\n";
    }
    int size2 = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMat2[i][j] != 0)
                size2++;
    int compMat2[3][size2];
    int l = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMat2[i][j] != 0)
            {
                compMat2[0][l] = i;
                compMat2[1][l] = j;
                compMat2[2][l] = sparseMat2[i][j];
                l++;
            }
    cout << "2nd Sparse Matrix:" << endl;
    cout << "Row\tColumn\tValue" << endl;
    for (int i=0; i<size2; i++)
    {
        cout << compMat2[0][i] << "\t" << compMat2[1][i] << "\t" << compMat2[2][i];
        cout <<"\n";
    }
    int size3=0, m=0;
    if(size1 == size2)
        size3 = size1;
    else if(size1 > size2)
        size3 = size1;
    else if(size1 > size2)
        size3 = size2;
    int compMat3[3][size3];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            if (sparseMat1[i][j] != 0 || sparseMat2[i][j] != 0)
            {
                compMat3[0][m] = i;
                compMat3[1][m] = j;
                compMat3[2][m] = sparseMat1[i][j] + sparseMat2[i][j];
                m++;
            }
    cout << "Addition of Sparse Matrix:" << endl;
    cout << "Row\tColumn\tValue" << endl;
    for (int i=0; i<size3; i++)
    {
        cout << compMat3[0][i] << "\t" << compMat3[1][i] << "\t" << compMat3[2][i];
        cout <<"\n";
    }
    return 0;
}