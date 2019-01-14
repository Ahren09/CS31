#include<iostream>
using namespace std;


int main()
    {
        int* a=new int[10];
        int i=0;
        while(i<10){
            a[i]=1+(++i);
            
        }
        i=0;
        cout<<a[i+1]<<endl;
        while(i<10){
            cout<<a[i++]<<" ";
        }
        
        return 0;
}
