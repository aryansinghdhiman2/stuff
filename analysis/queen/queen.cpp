#include<iostream>
#include<vector>
using namespace std;
int count=0;

bool canPlace(int k,int i,vector<int>& result){
    for(int j=0;j<result.size();++j){
        if(result[j]==i or abs(result[j]-i)==abs(j-k)){
            return false;
        }
    }
    return true;
}

void printResult(vector<int> result){
    for(int i=0;i<result.size();i++){
        result.at(i)++;
        cout<<result.at(i)<<' ';
    }
    cout<<'\n';
    // cout>>result>>endl;
}

void queens(int k,int n,vector<int> result){
    for(int i=0;i<result.size();++i){
        if(canPlace(k,i,result)){
            result[k]=i;
            if(k==n-1){
                printResult(result);
                count++;
            }
            else{
                queens(k+1,n,result);
            }
        }
    }
}

int main(){
    int n;
    cout<<"Enter number of queens: ";
    cin>>n;
    int k=0;
    vector<int> result;
    result.reserve(n);
    for(int i=0;i<result.size();i++){
        result.at(i)=0;
    }
    queens(k,n,result);
    cout<<"\nNumber of solutions are: "<<count<<endl;
}