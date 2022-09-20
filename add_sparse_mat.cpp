#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
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

d_vector add_sp_matr(d_vector& sp_1,d_vector& sp_2)
{
    d_vector result=sp_1;
    for(auto itr_1=result.begin();itr_1!=result.end();itr_1++)
    {
        for(auto itr_2=sp_2.begin();itr_2!=sp_2.end();itr_2++)
        {
            if(itr_1->at(0)==itr_2->at(0) && itr_1->at(1)==itr_2->at(1))
            {
                itr_1->at(2)+=itr_2->at(2);
                itr_2->clear();
            }
        }
    }
    for(int i=0;i<(int)sp_2.size();i++)
    {
        result.push_back(sp_2.at(i));
    }
    auto comp=[](vector<int> a,vector<int> b){
        if(a.at(0)<b.at(0))
            return true;
        if(a.at(0)==b.at(0) && a.at(1)<b.at(1))
            return true;
        else 
            return false;
    };
    sort(result.begin(),result.end(),comp);
    
    return result;
}
int main()
{
    d_vector matrix_1;
    input_matrix(matrix_1);
    d_vector sp_matrix_1;
    convert_normal_to_sparse(matrix_1,sp_matrix_1);
    
    d_vector matrix_2;
    input_matrix(matrix_2);
    d_vector sp_matrix_2;
    convert_normal_to_sparse(matrix_2,sp_matrix_2);

    d_vector result=add_sp_matr(sp_matrix_1,sp_matrix_2);
    display_sparse_mat(result);

}