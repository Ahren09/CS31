
#include <iostream>
using namespace std;

int main(){
    char ch=76;
    int k ='L';
    
    ch+=1;
    k=77;
    
    double d=3.68;
    cout.setf(ios::fixed);
    cout.precision(1);
    cout<<d<<endl; //calls the function for double, writes '3', '.', '7'
    //if ASCII, this is 51, 46, 55
    //if EBCDIC, this is 243,75,247
    cout<<k<<endl; //calls the function for int, writes '7' '7'
    //if ASCII, this is 55, 55
    //if EBCDIC, this is 247,247
    cout<<ch<<endl; //calls the function for char, writes 'M' if ASCII, 'C' if EBCDIC
    //if ASCII, this is 77,77
    //if EBCDIC, this is 77,77
    string s = "A7";
    cout<<s<<endl; //calls the function for string; writes 'A' '7'
    //if ASCII, this is 65, 55
    //if EBCDIC, this is 193,247
}
