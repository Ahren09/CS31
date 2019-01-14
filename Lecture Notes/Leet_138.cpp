#include <iostream>
#include <string>
#include <cassert>
#include <vector>
using namespace std;


int findLength(vector<int>& A, vector<int>& B) {
    int row = A.size()+1, col = B.size()+1;
    int matrix[row][col];
    int maxValue=0;
    for(int j=0;j<col;j++)
        matrix[0][j]=0;
    for(int i=1;i<row;i++){
        matrix[i][0]=0;
        for(int j=1;j<col;j++){
            matrix[i][j]=(A[i-1]==B[j-1])?matrix[i-1][j-1]+1:0;
            maxValue=max(maxValue,matrix[i][j]);
            cout<<matrix[i][j]<<" ";
        }
    }
    cout<<"\n\n\n\n\n\n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            cout<<matrix[i][j]<<"  ";
        cout << endl;
    }
    
    return maxValue;
}

int main(){
    vector<int>A = {3,2,1,4,7};
    vector<int>B = {1,2,3,2,1};
    int i = findLength(A,B);
    cout<<i;
    return 0;
}
