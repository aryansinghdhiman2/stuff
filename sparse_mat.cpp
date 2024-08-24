#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

typedef vector<vector<int>> d_vector;

void convert_normal_to_sparse(const d_vector& matrix,d_vector& sp_matrix)
{
    for (int i=0,k=0;i<matrix.size();i++)
    {
        for (int j=0;j<matrix.at(i).size();j++)
        {
            if (matrix[i][j]!=0)
            {
                sp_matrix.push_back({i,j,matrix.at(i).at(j)});
                k++;
            }
        }
    }
}

void display_sparse_mat(const d_vector& sp_matrix)
{
    cout<<"Outputting Sparse Matrix:\n";
    cout<<setw(3)<<"Row"<<setw(7)<<"Column"<<setw(6)<<"Value"<<endl;
    for(auto itr=sp_matrix.begin();itr!=sp_matrix.end();itr++)
    {
        cout<<setw(3)<<itr->at(0)<<setw(7)<<itr->at(1)<<setw(6)<<itr->at(2)<<'\n';
    }
}

void input_matrix(d_vector& matrix)
{
    int row,column;
    cout<<"Enter number of rows of matrix: ";
    cin>>row;
    cout<<"Enter number of columns of matrix: ";
    cin>>column;
    cout<<"Enter Values: \n";
    for(int i=0;i<row;i++)
    {
        vector<int> row_mat;
        for(int j=0;j<column;j++)
        {
            int input;
            cin>>input;
            row_mat.push_back(input);
        }
        matrix.push_back(row_mat);
        row_mat.clear();
    }
}
int main()
{
    
    d_vector matrix;
    input_matrix(matrix);
    d_vector sp_matrix;
    convert_normal_to_sparse(matrix,sp_matrix);
    display_sparse_mat(sp_matrix);

    


}