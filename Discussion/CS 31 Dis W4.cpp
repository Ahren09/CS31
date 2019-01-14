#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

int findLastLength(string s){
    if(s=="")
        return 0;
    int i=s.size()-1;
    bool isWord;
    int size;
    while(!isalpha(s[i])&&i>=0)
        i--;
    while(i>=0){
        
        size=0;
        isWord=true;
        if(s[i]==' ' && isWord)
            return size;
        if(!isalpha(s[i]){
            
        }
        else{
            size++;
        }
           i--;
    }
    return 0;
    
}


int main(){
    
    
    
    
}
