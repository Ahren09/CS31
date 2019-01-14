#include <string>
#include <iostream>
#include <cstring>

using namespace std;

typedef int* IntPtr;
void foo(IntPtr p){
    *p=2;
}

void reverse(char* arr){
    if(*arr=='\0')
        return;
    int i;
    for(i=0;*(arr+i)!='\0';i++);
    int j=0;
    while(i>j){
        char ch=*(arr+i);
        *(arr+i)=*(arr+j);
        *(arr+j)=ch;
        i--;j++;
    }
    
    
}
/*
void descSort(int* nums, int len){
    int i=0,j=0;
    for(i=0;i<len;i++){
        int max=*(nums+i);
        int max_index=i;
        for(j=i;j<len;j++){
            
            if(*(nums+i))
            
        }
        
    }
    
}
 */

int main(){
    char a[10]="Hello";
    reverse(a);
    cout<<a[0]<<endl;
    int num=1;
    IntPtr ptr=&num;
    foo(ptr);
    cout<<*ptr<<endl;
}

