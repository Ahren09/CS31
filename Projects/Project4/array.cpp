#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
using namespace std;

void swapString(string& a, string& b);
int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int divide(string a[], int n, string divider);



int main()
{
    
    string h[7] = { "greg", "gavin", "ed", "xavier", "", "eleni", "fiona" };
    assert(lookup(h, 7, "eleni") == 5);
    assert(lookup(h, 7, "ed") == 2);
    assert(lookup(h, 2, "ed") == -1);
    assert(lookup(h, 2, "") == -1);
    assert(positionOfMax(h, 7) == 3 && positionOfMax(h, -2) == -1);
    
    string g[4] = { "greg", "gavin", "fiona", "kevin" };
    assert(differ(h, 4, g, 4) == 2);
    assert(appendToAll(g, 4, "?") == 4 && g[0] == "greg?" && g[3] == "kevin?");
    assert(appendToAll(g, 0,"!")==0&&appendToAll(g, -1,"!")==-1);
    assert(rotateLeft(g, 4, 1) == 1 && g[1] == "fiona?" && g[3] == "gavin?");
    assert(rotateLeft(g,-5,4)==-1 && rotateLeft(g,4,-1)==-1 && rotateLeft(g,0,0)==-1);
    assert(rotateLeft(g,3,4)==-1&&rotateLeft(g,3,3)==-1);
    
    string m[3]={"greg", "fiona", "kevin"};
    assert(differ(h, 4, m, 3) == 1);
    assert(differ(h, 4, m, -3) == -1);
    assert(differ(h, 4, m, 0) == 0);
    
    
    string e[4] = { "ed", "xavier", "", "eleni" };
    assert(subsequence(h, 7, e, 4) == 2);
    
    string d[5] = { "gavin", "gavin", "gavin", "xavier", "xavier" };
    assert(countRuns(d, 5) == 2);
    string k[4] = { "gavin", "gavin", "gavin", "gavin"};
    assert(countRuns(k, 4) == 1);
    
    
    
    
    string f[3] = { "fiona", "ed", "john" };
    assert(lookupAny(h, 7, f, 3) == 2);
    assert(lookupAny(h, 1, f, 3) == -1 && lookupAny(h, 7, f, -3)==-1);
    assert(flip(f, 3) == 3 && f[0] == "john" && f[2] == "fiona");
    assert(flip(f, -3) == -1);
    assert(divide(h, 7, "fiona") == 3);
    
    //Additional Tests
    string str1[7]={"ab","cd","ef","ab","cd","ef","gh"};
    string str2[4]={"ab","cd","ef","gh"};
    assert(subsequence(str1,7,str2,4)==3 && subsequence(str1, 7, str2, 3)==0 && subsequence(str1,0,str2,0)==0 && subsequence(str1,-4,str2,0)==-1);
    
    //test the string modified by divide()
    string str3[14]={"n","d","f","s","p","i","o","s","ge","f","a","o","o","c"};
    string str4[10]={"n","n","n","n","n","n","n"};
    string str5[5]={"c","c","c","c","c"};
    divide(str3,14,"o");
    divide(str4,7,"n");
    divide(str5,5,"n");
    
    int i = 0;
    while(i<14){
        cerr<<str3[i]<<" ";
        i++;
    }//str3 should equal {"n","d","f","c","ge","i","a","f","o","o","o","s","p","s"};
    cerr<<endl;
    
    i=0;
    while(i<7){
        cerr<<str4[i]<<" ";
        i++;
    }//str4 should equal {"n","n","n","n","n","n","n"};
    cerr<<endl;
    
    i=0;
    while(i<5){
        cerr<<str5[i]<<" ";
        i++;
    }//str5 should equal {"c","c","c","c","c"};
    cerr<<endl;
    
    cerr<<endl;
    cerr << "All tests succeeded" << endl;
    
}

//An extra function for swapping two elements

void swapString(string& a, string& b){
    string temp = a;
    a = b;
    b=temp;
}


int appendToAll(string a[], int n, string value){
    if(n<=0) return (n==0)?0:(-1); //when size of a[] is equal to/smaller than the value
    for(int i=0;i<n;i++){
        a[i] += value;
    }
    return n;
}

int lookup(const string a[], int n, string target){
    if(n<=0) return (n==0)?0:(-1); //same as above
    for(int i=0;i<n;i++){
        if(a[i]==target)
            return i;
    }
    return -1;
}

// ?? z
int positionOfMax(const string a[], int n){
    //return 1 if no interesting elements
    //return 0 if there's only one element in the array
    if(n<=1) return(n==1)?0:(-1);
    
    int pos=0;
    string max = a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max){
            max=a[i];
            pos=i;
        }
    }
    return pos;
}

// ?? What if size = 0
int rotateLeft(string a[], int n, int pos){
    
    if(n<=0||pos>=n||pos<0) return -1;
    else if(n==1||pos==n-1) return pos; //Avoid pos+1 being Out Of Bound
    int ret = pos;
    while(pos<n-1){
        swapString(a[pos],a[pos+1]);
        pos++;
    }
    return ret;
}
int countRuns(const string a[], int n){
    if(n<=0) return (n==0)?0:(-1);
    else if(n==1) return 1;
    int count = 1;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1])
            count++;
    }
    return count;
}

int flip(string a[], int n){
    //n=1 won't cause OutOfBound
    if(n<=0) return (n==0)?0:(-1);
    int i=0;
    while(i<n-i-1){
        swapString(a[i], a[n-i-1]);
        i++;
    }
    return n;
}

int differ(const string a1[], int n1, const string a2[], int n2){
    if(n1<0||n2<0) return -1;
    else if(n1==0||n2==0) return 0; //if either is empty string, differ() returns 0
    int i=0;
    while(a1[i]==a2[i] && i<n1 && i <n2)
        i++;
    return i;
}

int subsequence(const string a1[], int n1, const string a2[], int n2){
    if(n1<0||n2<0) return -1;
    if(n2==0)
        return 0;
    
     //j is used to compare elements
    for(int i=0; i<n1;i++){
        if(a1[i]==a2[0]){
            int j=0;
            //Make sure both a1 and a2 are not OutOfBound
            while(i+j<n1 && j<n2 && a1[i+j]==a2[j]){
                j++;
            }
            if(j==n2)
                return i;
            else continue;
        }
    }
    return -1;
}
int lookupAny(const string a1[], int n1, const string a2[], int n2){
    if(n1<=0||n2<=0) return -1;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(a2[j]==a1[i])
                return i;
        }
    }
    return -1;
}


int divide(string a[], int n, string divider){
    int lower = 0; //count the number of strings that <divider
    int i=0;
    int numOfDivider=0;
    while(i<n){
        if(a[i]<divider)
            lower++;
        else if(a[i]==divider)
            numOfDivider++;
        i++;
    }
    
    
    //Second pass
    //We cut array into three regions: lower/equal/higher
    //if a[] contains the divider, move all dividers to the "equal" region
    int j=n-1;
    i=0;
    if(numOfDivider>0){
        int k=0;
        while(j>=numOfDivider+lower){
            if(a[j]==divider){
                swap(a[j],a[lower+k]);
                k++;
            }
            j--;
        }
        while(i<lower){
            if(a[i]==divider){
                swap(a[i],a[lower+k]);
                k++;
            }
            i++;
        }
    }
    
    //Third pass
    //swap lower ones with higher ones
    i=0;
    j=n-1;
    while(i<lower&&j>=lower+numOfDivider){
        while(a[i]<divider)
            i++;
        while(a[j]>divider)
            j--;
        swapString(a[i], a[j]);
    }
    return lower;
}
