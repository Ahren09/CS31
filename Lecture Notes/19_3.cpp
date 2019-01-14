#include <iostream>
#include <vector>

using std::vector;
using std::endl;
using std::cout;

int main(){
    vector<char> v;
    for(char ch='A';ch<'Q';ch++){
        v.push_back(ch);
    }
    
    vector<char>::iterator it;
    cout<<"Elements are:";
    for(it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    
    vector<char>::reverse_iterator rit;
    cout<<"Reverse order:";
    for(rit=v.rbegin();rit!=v.rend();rit++)
    {
        cout<<*rit<<" ";
    }
    cout<<endl;
    
    
    
    
    
}
