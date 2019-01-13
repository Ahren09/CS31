#include <iostream>
#include <cstring>
#include <cassert>
#include <cmath>
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

void swapC(char c1[MAX_WORD_LENGTH+1], char c2[MAX_WORD_LENGTH+1]){ // Can remove size?
    char temp[MAX_WORD_LENGTH+1];
    strcpy(temp,c1);
    strcpy(c1,c2);
    strcpy(c2,temp);
}

int removePunc(const char document[],char alphaSpace[]);

void toArray(char alphaSpace[],char docCopy[][MAX_WORD_LENGTH +1]);




int main(){
    
    //makeProper()
    
    /*
     Remove:
     duplicates with the lower separation
     word that is empty
     word that contains non-alpha characters
     space
     when word1[a]=word2[b] and word2[a]=word1[b]
     
     */
    const int nPatterns1 = 8;
    char word1[][MAX_WORD_LENGTH+1] = {"UCLA","usc","","sunset","foot??ball","Bruins","NEGATIVE"," "};
    
    char word2[][MAX_WORD_LENGTH+1] = {"USC","uClA","empty","sunrise","basketball","trojan","VALUE","space"};
    
    int sepa1[]={3,1,2,4,3,2,-1,3};
    
    assert(makeProper(word1, word2, sepa1, nPatterns1)==3);
    
    assert(strcmp(word1[0],"usc")==0 && strcmp(word2[0],"ucla")==0);
    assert(strcmp(word1[2],"bruins")==0 && strcmp(word2[2],"trojan")==0);
    assert(sepa1[0]==1);
    
    
    //rate()
    
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
    
    
    /*
     Error Handle:
     Empty document
     size less than or equal to 0
     */
    assert(rate("",test1w1,test1w2, test1dist, TEST1_NRULES) == 0);
    assert(rate("The UCLA scientist Smallberg is MAD!",test1w1,test1w2, new const int(0), TEST1_NRULES) == 0);
    assert(rate("The UCLA scientist Smallberg is MAD!",test1w1,test1w2, new const int(-1), TEST1_NRULES) == 0);
    
    /*
     Cases:
     document contains a serie of continuous space
     Capital letters
     word pairs showing up for more than once
     similar words - "scientist" and "scientists"
     word pairs separated by punctuations: "deranged-robot"
     */
    
    assert(rate("The mad UCLA scientist unleashed a deranged evil giant robot.",
                test1w1, test1w2, test1dist, TEST1_NRULES) == 2);
    assert(rate("The mad UCLA scientist unleashed    a deranged robot.",
                test1w1, test1w2, test1dist, TEST1_NRULES) == 2);
    
    assert(rate("**** 2018 ****",
                test1w1, test1w2, test1dist, TEST1_NRULES) == 0);
    assert(rate("  That plot: NEFARIOUS!",
                test1w1, test1w2, test1dist, TEST1_NRULES) == 1);
    assert(rate("deranged deranged robot deranged robot robot",
                test1w1, test1w2, test1dist, TEST1_NRULES) == 1);
    assert(rate("That scientist said two mad scientists suffer from deranged-robot fever."
                ,test1w1, test1w2, test1dist, TEST1_NRULES) == 0);
    assert(rate("mad scientist mad scientists mad scientist"
                ,test1w1, test1w2, test1dist, TEST1_NRULES) == 1);
    
    
    //When there are multiple patterns sharing the same word
    const int TEST2_NRULES=4;
    char test2w1[][MAX_WORD_LENGTH+1]={"ucla","bruin","bruins","sunset"};
    char test2w2[][MAX_WORD_LENGTH+1]={"fight","fight","fight","village"};
    int test2dist[TEST2_NRULES] = {1,3,3,2};
    
    assert(rate("UCLA Bruins fight! bruin fight!"
                ,test2w1, test2w2, test2dist, TEST2_NRULES) == 3);
    
    
    
    /*
     Cases:
     When word1 and word2 are equal
     If document contains words that exceed limit
     */
    char test3w1[][MAX_WORD_LENGTH+1]={"same"};
    char test3w2[][MAX_WORD_LENGTH+1]={"same"};
    int test3dist[TEST2_NRULES] = {1};
    assert(rate("Same same SAME SaMe",test3w1, test3w2,test3dist,1)==1);
    
    assert(rate("same ThisStringIsTooLongThatItExceedsLimit same",test3w1, test3w2,test3dist,1)==1);
    
    
    
    cerr << "All tests succeeded" << endl;
    
}

/*
 

 
 */



/*PseudoCode
 
 If document is an empty string
 return 0
 
 for every pair of elements
    convert to lower case
    mark unqualified CStrings(with char other than alpha and space)as "to be deleted"
    if the word pair already exist in previous word pairs, mark it as "to be deleted"
 
 * * * * *
 Detail of word comparison
 
 Repeatedly:
 find start of next word
 if no remaining word
 break
 copy each letter to the C string
 find end of word
 shift to the next char string
 add 1 to number of words
 
 
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
    
    //i is index of word1 and word2
    for(int i=0;i<nPatterns;i++){
        bool toBeDelete=false;
        
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
            
            //examine duplicates of word pairs, provided that the word pair satisfies all previous requirements
            //swap order of duplicates
            
            for(int k=i-1;k>=0;k--){
            if(strcmp(word1[i],word2[k])==0&&strcmp(word2[i],word1[k])==0)
            {
                swapC(word1[k],word2[k]);
            }
                
            //adopt the lowest separation
            if((strcmp(word1[i],word1[k])==0&&strcmp(word2[i],word2[k])==0)){
                separation[k]=min(separation[i],separation[k]);
                toBeDelete=true;
            }
            }
            
            
        }
        
        if(toBeDelete==false){
            if(strcmp(word1[validNum],word1[i])!=0)
                strcpy(word1[validNum],word1[i]);
            if(strcmp(word2[validNum],word2[i])!=0)
                strcpy(word2[validNum],word2[i]);
            separation[validNum]=separation[i];
            validNum++;
        }
        
    }
    
    
    return validNum;
}
               
/*
 PseudoCode
 
 Repeatedly:
    search each words of document in word1
    if no words remaining
        break
    if a word of document matches a word in word1
        search word2 within range of separation words, omit word1 itself
            if word2 found
                increase rate by 1
                mark the matching pair as found
 
 
 */
int rate(const char document[],
         const char word1[][MAX_WORD_LENGTH+1],
         const char word2[][MAX_WORD_LENGTH+1],
         const int separation[],
         int nPatterns){
    
    char alphaSpace[LONGEST_DOC+1];
    int wordCount=removePunc(document,alphaSpace);
    char docCopy[125][MAX_WORD_LENGTH+1];
    toArray(alphaSpace, docCopy);
    int rate=0;
    
    //store the search result of each word pair in word1[] and word2[]
    
    bool match[125];
    for(int i=0;i<125;i++)
        match[i]=false;
    
    //i is the indicator of docCopy - the words to be tested
    for(int i=0;i<wordCount;i++){
        if(strcmp(docCopy[i],"")==0)
            break;
        //j is the indicator of word1, word2 and separation
        for(int j=0;j<nPatterns;j++){
            
            //if contains word1
            if(strcmp(docCopy[i],word1[j])==0){
                
                //k specifies the scope of search
                int k;
                int upperBound=((i+separation[j]+1)<wordCount)?(i+separation[j]+1):(wordCount-1);
                int lowerBound=((i-separation[j]-1)>=0)?(i-separation[j]-1):0;
                
                //find word2 in document
                for(k=lowerBound;k<=upperBound;k++){
                    if(k==j)
                        k++;
                    if(strcmp(docCopy[k],word2[j])==0&&match[j]==false){
                        rate++;
                        match[j]=true;
                        break;
                    }
                }
            }
        }
    }
    return rate;
}

/*
 Purpose:
 Convert document into a 2D array of separated words
 
 repeatedly:
 find start of next word
 if no words remaining
 break
 */
void toArray(char alphaSpace[],char docCopy[][MAX_WORD_LENGTH +1]){
    int index=0;
    int m=0,n=0;
    while(true){
        if(isalpha(alphaSpace[index])){
            if(n==MAX_WORD_LENGTH){
                strcpy(docCopy[m],"NOT_FOUND");
            }
            else{
                docCopy[m][n]=alphaSpace[index];
                n++;
            }
        }
        else if(alphaSpace[index]==' '){
            docCopy[m][n]='\0';
            m++;
            n=0;
        }
        else if(alphaSpace[index]=='\0'){
            docCopy[m][n]='\0';
            m++;
            strcpy(docCopy[m],"");
            break;
        }
        index++;
    }
}

/*
 Purpose:
 Remove elements other than alpha and space, such as punctuations, in document
 count the number of words in document
 */

int removePunc(const char document[],char alphaSpace[]){
    
    if(document[0]=='\0')
        return 0;
    
    int index=0,i=0;
    int wordCount=0;
    while(true){
        
        //read an alpha
        if(isalpha(document[index])){
            alphaSpace[i]=tolower(document[index]);
            i++;
        }
        //read a space
        else if(document[index]==' '){
            if(i>0&&isalpha(alphaSpace[i-1])){ //if not the first character
                alphaSpace[i]=document[index];//copy the space, but at most copy one
                wordCount++;
                i++;
            }
        }
        else if(document[index]=='\0'){
            alphaSpace[i]='\0';
            if(i>0&&isalpha(alphaSpace[i-1])){
                wordCount++;
            }
            break;
        }
        index++;
    }
    return wordCount;
}
 


  

 






