#include <iostream>
#include <cstring>
#include <cassert>
#include <cctype>
using namespace std;
const int MAX_WORD_LENGTH = 20;
const int LONGEST_DOC = 250;


/*
 NOTE:
 in prope form
 rating
 
 */

int makeProper(char word1[][MAX_WORD_LENGTH+1],
               char word2[][MAX_WORD_LENGTH+1],
               int separation[],
               int nPatterns);

int rate(const char document[],
         const char word1[][MAX_WORD_LENGTH+1],
         const char word2[][MAX_WORD_LENGTH+1],
         const int separation[],
         int nPatterns);

void swapC(char c1[MAX_WORD_LENGTH+1], char c2[MAX_WORD_LENGTH+1]);

int main(){
    
    char w1[8][MAX_WORD_LENGTH+1]={"mad","deranged","NEFARIOUS","half-witted","robot","plot","have","NeFaRiOuS"};
    char w2[8][MAX_WORD_LENGTH+1]={"scientist","robot","PLOT","assistant",
        "deranged","Nefarious","mad","pLoT"};
    int separation[8] = {1,3,0,2,1,0,12,0};
    
    cout<<makeProper(w1,w2,separation,8)<<endl;
    for(int i=0;i<8;i++){
        for(int j=0;w1[i][j]!='\0';j++)
            cout<<w1[i][j];
        cout<<'\t';
        for(int j=0;w2[i][j]!='\0';j++)
            cout<<w2[i][j];
        cout<<'\t'<<separation[i];
        cout<<'\n';
        //cout<<w1[i]<<'\t'<<w2[i]<<'\t'<<separation[i]<<endl;
    }
    
}

/*PseudoCode
 for every pair of elements
    convert to lower case
    mark those to be deleted
 
 make copys of the three arrays(must be after converting to lower cases)
 remove those with signs
 
 remove those that are duplicates of another pair
 
 
 
 
 */

void swapC(char c1[MAX_WORD_LENGTH+1], char c2[MAX_WORD_LENGTH+1]){ // Can remove size?
    char temp[MAX_WORD_LENGTH+1];
    strcpy(temp,c1);
    strcpy(c1,c2);
    strcpy(c2,temp);
}

int makeProper(char word1[][MAX_WORD_LENGTH+1],
               char word2[][MAX_WORD_LENGTH+1],
               int separation[],
               int nPatterns){
    if(nPatterns<0){
        nPatterns=0;
        return 0;
    }
    //treat negative as 0
    const int n=nPatterns;
    bool toBeDeleted[n];
    int validNum=nPatterns;
    for(int i=0;i<nPatterns;i++){
        
        //examines each word
        for(int j=0;word1[i][j]!='\0';j++){ //NOTICE here is not j!='\0'
            // if contains signs, add this element to the delete array and skip to the next outer loop
            word1[i][j]=tolower(word1[i][j]);
            if(!isalpha(word1[i][j])){
                toBeDeleted[i]=true;
                validNum--;
                break;
            }
        }
        for(int j=0;word2[i][j]!='\0';j++){
            word2[i][j]=tolower(word2[i][j]);
            if(!isalpha(word2[i][j])){
                toBeDeleted[i]=true;
                validNum--;
                break;
            }
        }
        
        for(int k=i-1;k>=0;k--){
        if((strcmp(word1[i],word1[k])==0&&strcmp(word2[i],word2[k])==0)
           ||(strcmp(word1[i],word2[k])==0&&strcmp(word2[i],word1[k])==0)){
            validNum--;
            toBeDeleted[i]=true;
            break;
        }
         
    }
    
    }
    
    int p=0,q=nPatterns-1;
    while(p<q){
        while(toBeDeleted[p]==false&&p<q)
            p++;
        while(toBeDeleted[q]==true&&p<q)
            q--;
        swapC(word1[p],word1[q]);
        swapC(word2[p],word2[q]);
        swap(separation[p],separation[q]);
        p++;q--;
    }
    
    
    return validNum;
}
    
    //Search duplicates of word pairs
               


int rate(const char document[],
         const char word1[][MAX_WORD_LENGTH+1],
         const char word2[][MAX_WORD_LENGTH+1],
         const int separation[],
         int nPatterns){
    
    char docCopy[LONGEST_DOC+1];
    int index=0,i=0;
    while(document[i]!='\0'){
        if(isalpha(document[i]))
            docCopy[index++]=document[i];
        i++;
    }
    
    
}




