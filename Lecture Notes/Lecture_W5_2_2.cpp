#include <iostream>
using namespace std;

double computeMean(const int a[], int n);
void setFirst(int a[], int n, int value);

int main(){
    const int MAX_NUM_OF_SCORES = 10000;
    int scores[MAX_NUM_OF_SCORES];
    int nScores=0;
    //fill the array
    //double m1 = computeMean(scores, nscores);
    
    const int daysInMonth[12]={31,28,31,30,31,30};
    int stuff[100];
    setFirst(stuff,100,42);
    setFirst(daysInMonth,12,42); //Compile Error, daysInMonth is a const int[]
    double m1 = computeMean(daysInMonth,6);
    cout<< m1<<endl;
}

//Notice n = 0
double computeMean(const int a[], int n){//const: promise that function does not modify a[]
    if(n==0) return 0;
    int total = 0;
    for(int k=0;k<n;k++)
        total += a[k];
    //setFirst(a,n,k); // Compile Error, const->modify
    return static_cast<double>(total)/n; // First cast variable total, then divide by n
    //static_cast<double>(total/n); will miss the digits
}
void setFirst(int a[], int n, int value){
    if(n>=0)
        a[0]=value;
}
