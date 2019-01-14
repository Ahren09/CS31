#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main() {
    int i=-1;
    string str;
    cout<<"Input String: ";
    cin >> str;
    bool b = false;
    
    do
    {
        b=islower(str[i++]);
    }while(b==false && i<str.size());
    if(b==true)
        cout<<"Lower Case Character: "<<str[i-1]<<endl;
    else
        cout<<"No lowercase character"<<endl;
    
    /*
    do
    {
        b=islower(str[++i]);
    }while(b==false && i<str.size()-1);
    if(b==true)
        cout<<"Lower Case Character: "<<str[i]<<endl;
    else
        cout<<"No lowercase character"<<endl;
     */
    return 0;
}
