#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

char* reverseString(char* first, char* last)
{
    char* start=last;
    if(*first!='\0' && last!=first+1){
        last--;
        while(first<last){
            char temp=*first;
            *first = *last;
            *last = temp;
            first++;
            last--;
        }
    }
    return start;
    
}

int main(){
    char c[11] = "HelloWorld";
    reverseString(c, c+10);
    cout<<c;
    
    
}

