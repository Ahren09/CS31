#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

//4
void reverse(char* arr){
    //if(! *arr) return; OPTIONAL
    char* start=arr;
    char* end=arr;
    while(*(++end));
    end--;
    /*
     OR: while(*(end++)); end-=2; //notice here the pointer goes back by 2
     */
    
    while(start<end){
        char temp=*start;
        *start=*end;
        *end=temp;
        start++;end--;
    }
    
    
}

//6
void minMax(int arr[], int n, int*& min, int*& max){
    if(n!=0){ //if(*arr) //WRONG!!
        min=arr;
        max=arr;
        int* i=arr;
        while(i<arr+n){
            if(*i<*min)
                min=i;
            if(*i>*max)
                max=i;
            i++;
        }
    }
    return;
}

//9
void rotate(int* A, int n){
    int rotation=n%6;
    if(rotation==0) return;
    else if(rotation<0)
        rotation+=6;
    //int index=rotation;
    int *B=&A;
    for(int i=6-rotation;i<6;i++){
        swap(*A,*(A+6-rotation));
        A++;
    }
    for(int i=)
    else if(n<0){
        
        
    }
    
}


int main(){
    char c[5]="ucla";
    reverse(c);
    cout<<c<<endl;
    
    int arr[5]={0,5,7,-10,2};
    int *pmin;
    int *pmax;
    minMax(arr,5,pmin,pmax);
    cout<<*pmin<<"   "<<*pmax<<endl;
    
    int A[]={1,2,3,4,5,6};
    int B[]={1,2,3,4,5,6};
    
}
