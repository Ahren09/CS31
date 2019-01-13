#include <iostream>
#include <cstring>
#include <cassert>
#include <cctype>
using namespace std;
const int MAX_WORD_LENGTH = 20;
const int LONGEST_DOC = 250;

int makeProper(char word1[][MAX_WORD_LENGTH+1],
               char word2[][MAX_WORD_LENGTH+1],
               int separation[],
               int nPatterns);

int rate(const char document[],
         const char word1[][MAX_WORD_LENGTH+1],
         const char word2[][MAX_WORD_LENGTH+1],
         const int separation[],
         int nPatterns);

int main(){
    
    char w1[8][MAX_WORD_LENGTH+1]={"mad","deranged","NEFARIOUS","half-witted","robot","plot","have","NeFaRiOuS"};
    char w2[8][MAX_WORD_LENGTH+1]={"scientist","robot","PLOT","assistant",
        "deranged","Nefarious","mad","pLoT"};
    int separation[8] = {1,3,1,2,1,0,12,0};
    
    cerr<<makeProper(w1,w2,separation,8)<<endl;
    for(int i=0;i<8;i++){
        for(int j=0;w1[i][j]!='\0';j++)
            cerr<<w1[i][j];
        cerr<<'\t';
        for(int j=0;w2[i][j]!='\0';j++)
            cerr<<w2[i][j];
        cerr<<'\t'<<separation[i];
        cerr<<'\n';
        //cout<<w1[i]<<'\t'<<w2[i]<<'\t'<<separation[i]<<endl;
    }
    
    
    const int TEST1_NRULES = 4;
    char test1w1[TEST1_NRULES][MAX_WORD_LENGTH+1] = {
        "mad",       "deranged", "nefarious", "have"
    };
    char test1w2[TEST1_NRULES][MAX_WORD_LENGTH+1] = {
        "scientist", "robot",    "plot",      "mad"
    };
    int test1dist[TEST1_NRULES] = {
        1,           3,          0,           12
    };
    char str1[]="The mad UCLA scientist unleashed a deranged evil giant robot."
    
    assert(rate(str1,
                test1w1, test1w2, test1dist, TEST1_NRULES) == 2);
    assert(rate("The mad UCLA scientist unleashed    a deranged robot.",
                test1w1, test1w2, test1dist, TEST1_NRULES) == 2);
    assert(rate("**** 2018 ****",
                test1w1, test1w2, test1dist, TEST1_NRULES) == 0);
    assert(rate("  That plot: NEFARIOUS!",
                test1w1, test1w2, test1dist, TEST1_NRULES) == 1);
    assert(rate("deranged deranged robot deranged robot robot",
                test1w1, test1w2, test1dist, TEST1_NRULES) == 1);
    assert(rate("That scientist said two mad scientists suffer from deranged-robot fever.",
                test1w1, test1w2, test1dist, TEST1_NRULES) == 0);
    cout << "All tests succeeded" << endl;
    /*
     
     
     
     char str1[]="  .";
     char str2[]="  a";
     char str3[]="..a..";
     char str2[]=" a. ";
     char str2[]=" a ";
     */
    
    
}

/*
 If document is an empty string
    return 0
 Repeatedly:
 find start of next word
    if no remaining word
        break
    copy each letter to the C string
 find end of word
 shift to the next char string
 add 1 to number of words
 
 */



/*PseudoCode
 for every pair of elements
 convert to lower case
 mark those to be deleted
 
 remove those with signs
 remove those that are duplicates of another pair
 
 
 
 
 */

int makeProper(char word1[][MAX_WORD_LENGTH+1],
               char word2[][MAX_WORD_LENGTH+1],
               int separation[],
               int nPatterns){
    
    //treat negative as 0
    if(nPatterns<0){
        nPatterns=0;
        return 0;
    }
    
    
    int validNum=0;
    
    
    
    for(int i=0;i<nPatterns;i++){
        bool toBeDelete=false;
        //问题：validNum会多减 如果两个word都不合要求
        
        //Examine empty string and negative separation
        if(strcmp(word1[i],"")==0||strcmp(word2[i],"")==0||separation[i]<0)
        {
            toBeDelete=true;
        }
        
        
        //examines each letter of word1 and word2
        else{
            
            for(int j=0;word1[i][j]!='\0';j++){ //NOTICE here is not j!='\0'
                // if contains signs, add this element to the delete array and skip to the next outer loop
                word1[i][j]=tolower(word1[i][j]);
                if(!isalpha(word1[i][j])){
                    toBeDelete=true;
                    break;
                }
            }
            for(int j=0;word2[i][j]!='\0';j++){
                word2[i][j]=tolower(word2[i][j]);
                if(!isalpha(word2[i][j])){
                    toBeDelete=true;
                    break;
                }
            }
            
            //examine duplicates of word pairs,provided that the word satisfies all previous requirements
            //turn separation to the lowest
            
            for(int k=i-1;k>=0;k--){
            if((strcmp(word1[i],word1[k])==0&&strcmp(word2[i],word2[k])==0)
               ||(strcmp(word1[i],word2[k])==0&&strcmp(word2[i],word1[k])==0)){
                separation[k]=min(separation[i],separation[k]);
                toBeDelete=true;
            }
            }
            
            
        }
        
        if(toBeDelete==false){
            
            strcpy(word1[validNum],word1[i]);
            strcpy(word2[validNum],word2[i]);
            separation[validNum]=separation[i];
            validNum++;
        }
        
    }
    
    
    return validNum;
}
    
    //Search duplicates of word pairs
               
/*PseudoCode
 Remove punctuations in document
 count the number of words in document
 Convert sentence into a 2D array of separated words
 
 repeatedly:
    find start of next word
    if no words remaining
        break
 
 Repeatedly:
    search each words of document in word1
 
    if word matches
        search word2 within range of separation words
            if search reaches the end of program
                word pair not found
    else repeat
 
    if no words remaining
        break
    else continue moving forward
 endif
 
 */



int rate(const char document[],
         const char word1[][MAX_WORD_LENGTH+1],
         const char word2[][MAX_WORD_LENGTH+1],
         const int separation[],
         int nPatterns){
    
    //TRY
    if(document[0]=='\0')
        return 0;
    
    char alphaSpace[LONGEST_DOC+1];
    int index=0,i=0;
    int wordCount=0;
    
    
    while(true){
        
        //read an alpha
        //TRY
        if(isalpha(document[index])){
            alphaSpace[i]=document[index];
            i++;
        }
        //read a space
        else if(document[index]==' '||document[index]=='\0'){
            if(i>0&&isalpha(alphaSpace[i-1])){ //if not the first character
                alphaSpace[i]=document[index];//copy the space, but at most copy one
                wordCount++;
            }
            
            if(document[index]=='\0')
                break;
            i++;
        }
        index++;
    }
    wordCount=static_cast<const int>(wordCount);
    char docCopy[wordCount][MAX_WORD_LENGTH +1];
    index=0;
    int m=0,n=0;
    while(m<wordCount){
        while(isalpha(alphaSpace[index])){
            docCopy[m][n]=alphaSpace[index];
            index++;
            n++;
        }
        m++;
    }
    
    //int PatternNum = makeProper(word1, word2, separation, nPatterns);
    int rate=0;
    
    for(int i=0;i<wordCount;i++){
        for(int j=0;j<nPatterns;j++){
            if(strcmp(docCopy[i],word1[j])==0){
                int k;
                int upperBound=((i+separation[j]+1<nPatterns)?(i+separation[j]+1):nPatterns-1);
                int lowerBound=(i-separation[j]-1>=0?(i-separation[i]-1):0);
                for(k=lowerBound;k<=upperBound;k++){
                    if(strcmp(docCopy[k],word2[j])==0){
                        rate++;
                    }
                }
                
            }
        }
        
    }
    return rate;
    
    
    
}
 


  

 






