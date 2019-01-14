#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include <cmath>
using namespace std;

int lookup(const string a[], int n, int target){
    //OR write:lookup(const string* a, int n, int target), same thing
    //The parameter a[] is actually passed as a pointer
    for(int k=0; ;){
        
        
    }
    // ... a[k]...
}

int main(){
    
    string sa[5]={"cat","mouse","eel","ferret","horse"};
    int i=lookup(sa,5,"eel"); // We are not passing a string as the parameter, but a pointer pointing to the first element of the array
    int j=lookup(&sa[0],5,"eel");
    
    int m=lookup(sa+1,3,"ferret");
    //which is:
    int m2=lookup(&sa[1],3,"ferret");
    
    
    
    
    double a = 3.2;
    double b = 5.1;
    double *p=&a;
    //double *q= 7.6; won't compile,q is only an address, not a double
    
    double c = a;
    // double d = p; won't compile
    double d=*p; //compile
    
    double& dd=d;// a rerefence, not a pointer
    
    //p=b; WRONG
    //Two ways to fix:
    p = &b; //assigning one pointer to another
    *p = b; //assigning one double to another
    *p += 4; //add 4 to b
    
    int k=7;
    //p=&k; Cannot compile. p can only hold pointer to double
    int* z=&k;
    
    cout<<(k * b); //ok
    //cout<<(k * p); //won't compile, can't multiply an int and a pointer, same as cout<<(k *p);
    cout<<(k * *p);//ok, k*b
    cout<<(k**p);//will compile correctly, but it's confusing
    cout<<(*z * *p)<<endl<<endl;
    
    double* q;
     // *q=4.7; undefined behavior, q is uninitialized
    q=p;
    double *r=&a;
    *r = b; //b points to a, 5.1
    
    if(p==r) //false - comparing two pointers - comparing the memory address
        cout<<"Hello";
    if(p==q) //true - comparing two pointers - same memory address
        cout<<"Yes";
    if(*p==*r) //true - comparing two doubles
        cout<<"Yeap";
    
    //TRAVERSING ARRAY
    
    const int MAXSIZE=5;
    double da[MAXSIZE];
    int k;
    double* dp;
    
    for(k=0;k<MAXSIZE;k++){
        da[k]=3.6;
    }
    
    for(dp=&da[0];dp<&da[MAXSIZE];dp++) //adding 1 is adding 1 unit of space taken by a double(8 bytes)
       *dp=3.6;
    
    for(dp=da;dp<da+MAXSIZE;dp++) //adding 1 is adding 1 unit of space taken by a double(8 bytes)
        *dp=3.6;
   
    
    //all three give the same result
    *dp=3.6;
    *(&da[0])=3.6;
    da[0]=3.6
    
    //all four give the same result
    dp++;
    dp=&da[0]+1;
    dp=&da[0+1];
    dp=&da[1];
    
    
}
