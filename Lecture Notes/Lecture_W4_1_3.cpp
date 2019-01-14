#include<iostream>
#include<string>
#include<cctype>
#include<cmath>
using namespace std;

void makeUpperCase(string& s){
    for(int i=0;i<s.size();i++)
        if(islower(s[i]))
            s[i]=toupper(s[i]);
    return;
}

int main(){
    string s;
    cin>>s;
    makeUpperCase(s);
    cout<<s<<endl;
    return 0;
}
