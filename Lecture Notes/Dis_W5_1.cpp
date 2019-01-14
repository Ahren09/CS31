#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool equality(int a[], int size, int target){
    int count=0;
    for(int i=0;i<size;i++){
        count=count*10+a[i];
    }
    return target==count;
}

int main(){
    int a[]={1,2,3,4,5};
    int n =12345;
    cout<<(equality(a,5,n)?"true":"false")<<endl;
    return 0;
}
