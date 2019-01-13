#include <iostream>
using namespace std;

//This function takes as input a pointer to the first element
//of a c-string and a pointer to the last element of a c-string 
//(including 0 byte) and outputs a new c-string that reverses 
//the order of characters in the original string

void* reverseString(char* first, char* last)
{
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
}

//This function takes as input a c-string containing a number and 
//the number of characters in the array (not including 0 byte)
//It outputs an integer representation of that number.
int convertStringToInt(char number[], int len)
{
    if(len==0)
        return -1;
    int value=0;
    for(int i=0;i<len;i++){
        value += value*10 + *(number+i);
    }
    return value;

}
