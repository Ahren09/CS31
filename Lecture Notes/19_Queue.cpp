
//

#include <iostream>
#include<stack>
#include<queue>
using namespace std;



int main(){
    queue<char> q;
    cout<<"Enter a list of text: ";
    char next;
    cin.get(next);
    
    while(next!='\n'){
        q.push(next);
        cin.get(next);
    }
    
    while(!q.empty()){
        cout<<q.back();
        q.pop();
    }
    cout<<endl;
    return 0;
    
    
    
}

