#include<iostream>
using namespace std;

int main(){
    int SparseMatrix[5][5]={{0,0,3,5,0},{0,4,0,6,0},{3,0,0,7,0},{0,6,9,0,0},{2,0,3,0,0}};
    int NonZero_Count=0;
    cout<<"THE SPARSE MATRIX IS ::: "<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<SparseMatrix[i][j]<<" ";
            if(SparseMatrix[i][j]!=0){
                NonZero_Count++;
            }
        }
        cout<<endl;
    }
    int CompactMatrix[3][NonZero_Count];
    int idx=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(SparseMatrix[i][j]!=0){
                CompactMatrix[0][idx]=i;
                CompactMatrix[1][idx]=j;
                CompactMatrix[2][idx]=SparseMatrix[i][j];
                idx++;
            }
        }
    }
    cout<<endl;
    cout<<"THE REAL MATRIX IS ::: "<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<idx;j++){
            if(i==0  && j==0){  cout<<"ROW  ---> ";  }
            if(i==1  && j==0){  cout<<"COL  ---> ";  }
            if(i==2  && j==0){  cout<<"VALUE --> ";  }
            cout<<CompactMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}