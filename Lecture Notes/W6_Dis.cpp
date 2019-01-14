
#include <cstring>
#include <iostream>
using namespace std;

//2.
void eraseChar(char str[],char c){
    int i=0;
    while(str[i]!='\0'){
        if(str[i]==c){
            int j;
            for(j=i;str[j]!='\0';j++){
                str[j]=str[j+1];
            }
            str[j]='\0';
        }
        else i++; //NOTICE: i does not change if an element is erased
    }
}
void strcat(char str1[],char str2[]){
    int i;
    for(i=0;str1[i]!='\0';i++);
    for(int j=0;str2[j]!='\0';){
        str1[i++]=str2[j++];
    }
    str1[i]='\0';
}

void removeDuplicate(char str1[]){
    int i=1,j=1;
    
    while(str1[j]!='\0'){
        int m=i-1;
        while(m>=0){
            if(str1[m]==str1[j]){
                
                break;
            }
            m--;
        }
        //无重复元素
        if(m==-1){
            str1[i]=str1[j];
            i++;
            j++;
        }
        
        //有重复元素
        else{
            j++;
        }
    }
    str1[i]='\0';
    
}

int find(string words[],int weights[], char word[], int n){
    for(int i=0;i<n;i++){
        if(strcmp(words[i].c_str(),word)==0){
            return weights[i];
        }
    }
    return 0;
}

int score(char sentence[], string words[], int weights[],int n){
    int score=0;
    int i=0;
    while(sentence[i]!='\0'){
        int len=i+1;
        if(isalpha(sentence[len])){
            int j=i+1;
            while(sentence[j]!='\0'&&sentence[j]!=' '){
                len++;
                j++;
            }
            char substr[100];
            strncpy(substr,sentence+i,len);
            substr[len]='\0';
            score=find(words,weights,substr,n);
            i+=len;
        }
    }
    
    return score;
}


int main(){
    char str5[100]="Yes";
    char str6[10]="Yes";
    cout<<strcmp(str5,str6);
    char str1[]="hello";
    char str2[]="world";
    char str3[]="helloworld";
    strcat(str1,str2);
    cout<<str1<<endl;
    removeDuplicate(str3);
    cout<<str3<<endl;
    
}
