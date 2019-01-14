#include <iostream>
#include <stack>
using std::cin;
using std::cout;
using std::stack;
using std::endl;

int main(){
    stack<char> s;
    char next;
    cout<<"Input a set of char:";
    cin.get(next);
    
    while(next != '\n'){
        s.push(next);
        cin.get(next);
    }
    
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    return 0;
}
