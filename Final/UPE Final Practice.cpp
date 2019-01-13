#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

char* strcat(char* destination, const char* source){
    
    if(*source==0)
        return destination;
    
    int i=0,j=0;
    while(*(destination+i))
        i++;
    while(*(source+j)){ //Here do not use "... != 0"
        *(destination + i)=*(source + j);
        i++;j++;
    }
    *(destination+i)='\0';
    return destination;
}

int main(){
    char c1[]="Hello";
    char c2[]="World";
    char* c3=strcat(c1,c2);
    cout<<*c3;
    
    
}
