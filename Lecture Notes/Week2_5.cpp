

#include <iostream>
using namespace std;

int main(){
    int c;
    cin>>c;
    /*
    for(int i=0;i<c;i++){
        int j=i;
        for(j=i;j<=2*i;j++)
            cout<<j;
        for(int k=c;k>i+1;k--)
            cout<<".";
        cout<<endl;
    }
    */
    for(int i=0;i<c;i++){
        for(int j=0;j<c;j++)
        {
            if(j>i)
                cout<<". ";
            else
                cout<<i+j<<" ";
        }
        cout<<endl;
    }
    
}
