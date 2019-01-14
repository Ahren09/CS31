#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include <cmath>
using namespace std;

const int MAX_WORD_LENGTH=6;
int countLength(const char a[][MAX_WORD_LENGTH+1],int n, int targetLength);

int main(){
    const int MAX_PETS=5;
    char pets[MAX_PETS][MAX_WORD_LENGTH+1]{ //notice that there's one more space for the zero byte
        "cats","mouse","eel","terret","horse"
    };
    
    cout<<countLength(pets,MAX_PETS,5);
 }

int countLength(const char a[][MAX_WORD_LENGTH+1],int n, int targetLength){
    
    int total=0;
    for(int k=0;k<n;k++){
        //for C++ string, a[k].size()
        if(strlen(a[k])==targetLength) //a[k] is treated as an array
            total++;
        
    }
    return total;
    
    
}


