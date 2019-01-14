
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int c, exp=0;
    cin>>c;
    if(c<1)
    {cout<<"Error"<<endl;
        return 0;
    }
    while(2*pow(2.0,exp)<=c){
        exp++;
    }
    cout<<exp<<endl;
    return 0;
    
    
    
}
