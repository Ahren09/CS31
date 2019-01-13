#include <iostream>
#include <cstring>
#include <cassert>
#include <cctype>
using namespace std;
const int MAX_WORD_LENGTH = 20;
const int LONGEST_DOC = 250;

/*Test Case

 char str1[]="  .";
 char str2[]="  a";
 char str3[]="..a..";
 char str4[]=" a. ";
 char str5[]=" a ";
 char str6="abcdefghijklmnopqrstuvwxyz"
 */
 

/*TEST CODE
 
 
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

 const char str1[]="The mad UCLA scientist unleashed a deranged evil giant robot.";
 char str2[LONGEST_DOC+1];
 char docCopy[10][21];
 int wordCount=removePunc(str1,str2);
 
 cout<<wordCount<<endl;
 toArray(str2,docCopy,wordCount);
 for(int i=0;i<wordCount;i++){
 cout<<docCopy[i]<<endl;
 }
 cout<<"分割线"<<endl;
 for (int i=0;i<10;i++){
 for(int j=0;docCopy[i][j]!='\0';j++)
 cout<<docCopy[i][j];
 cout<<endl;
 }
 
 const char str3[]="That plot: NEFARIOUS!";
 char str4[LONGEST_DOC+1];
 char docCopy2[10][21];
 int wordCount2=removePunc(str3,str4);
 
 cout<<wordCount2<<endl;
 toArray(str4,docCopy2,wordCount2);
 for(int i=0;i<wordCount2;i++){
 cout<<docCopy2[i]<<endl;
 }


*/

int toArray(const char document[],char docCopy[][LONGEST_DOC+1]){
    
    if(strcmp(document,"")==0)
        return 0;
    int index=0,i=0,j=0,wordCount=0;
    
    while(true){
        
        //read an alpha
        if(isalpha(document[index])){
            docCopy[i][j]=tolower(document[index]);
            j++;
        }
        //read a space
        else if(document[index]==' '||document[index]=='\0'){
            
            if(j!=0)
            {
                docCopy[i][j]='\0'; // put a terminate point
                i++;
                wordCount++;
                j=0;
            }
        }
        
        //read something else
        index++;
    }
    return wordCount;
}

int main(){
    
    char doc[]="What is that";
    char arr[][MAX_WORD_LENGTH+1]={"yes","yes","yes","yes"};
    int res = toArray(doc,arr);
    //cerr<<res;
    for(int i=0;i<4;i++){
        cout<<arr[i]<<endl;
    }
        cout<<endl;
    
    
    
}
