#include <iostream>
#include <cstring>
using namespace std;

int main(){
    
    //C++ string
    string t = "Ghost";
    string s; //empty string
    for(int k=0;k!=t.size();k++)
        cout<<t[k]<<endl;
    cout<<t;
    getline(cin,s);
    s=t;//set s to "Ghost"
    s += "!!!";
    
    
    //C string
    // char str[10] = {'G','H','O','S','T'};
    char str1[10]="hello";
    char str[10] = "Ghost";//when initialized, can be less than the assigned size
    char strr[100] = ""; //initialize an empty string, put a zero byte at the first element
    //char strr[]; //Illegal!!
    cout<<strlen(str);
    for(int k=0;k!=strlen(str);k++)
        cout<<str[k];
    for(int k=0;str[k]!='\0';k++)
        cout<<str[k];
    cin.getline(strr,100); //read input, maximun 100 characters,stop input when reaching maximum
    //cin will automatically put a '\0' at the end
    //if input does not have space, we can use:
    cin>>strr;
    
    //s = t; //Error, Arrays cannot be assigned by "=",m
    strcpy(strr,str); //strcpy(destination, source)
    strcpy(str,"abcdefghij");//C does not guarantee that the array is big enough to hold the string
    cout<<strr;
    
    //strcat cannot concatonate a char
    strcat(str1,"!"); //now str1 is "hello!"
    strcat(str1,'!'); //ERROR
    //C String可以用“=”按照一个个char一位位地复制元素,只要size不超上限
    int len=strlen(str1);
    cs[len]='!';
    cs[len+1]='\0'; //末尾必须手动添加\0！！
    
    cout<<str1;// 2D的C String可直接打印整个单词，而不必逐个字母打印
    //if(str<str1) //compiles, but does not compare the elements
        //actually compare the memory address
    strcmp(str,strr); //return an int, negative a comes before b, 0 if a equals b, positive if a comes after b
    
    //Examine whether str1 is empty
    if(strcmp(str1,"")==0);
    if(str1[0]=="\0");
    if(strlen(str1)==0);
    
    
    
    
    
    
        
    
}
