#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include <cmath>
using namespace std;

/*

int findFirstNegative(double* a,int n){
    for(double* p=a;p<a+n;p++){
        if(*p<0)
            return p-a;//&a[2] equals &a[0]+2
        
    }
    return -1;
    
}
*/
double* findFirstNegative(double* a,int n){
    for(double* p=a;p<a+n;p++){
        if(*p<0)
            return p;//&a[2] equals &a[0]+2
        
    }
    return a+n;
    //return NULL;
    
}

int main(){
    double da[5]={1,2,3,-4,5};
    
    double* pfn=findFirstNegative(da, 5);
    
    /*
    //way 1
    if (pfn==da+5)
        cout<<"There are no negative values in the array";
    else{
        cout<<"The first negative value is "<<*pfn<<endl;
        cout<<"It is at element number "<<pfn-da<<endl;
    }
    */
    //way 2
    if (!pfn)
        cout<<"There are no negative values in the array";
    else{
        cout<<"The first negative value is "<<*pfn<<endl;
        cout<<"It is at element number "<<pfn-da<<endl;
    }
     
    
    /*
    int fnpos = findFirstNegative(da,5);
    if (fnpos==-1)
        cout<<"There are no negative values in the array";
    else{
        cout<<"The first negative value is "<<da[fnpos]<<endl;
        cout<<"It is at element number "<<fnpos<<endl;
    }
     */
    
    
}
