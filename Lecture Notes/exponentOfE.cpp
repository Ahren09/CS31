#include <iostream>
#include <cmath>
using namespace std;

int main(){
    const double e = 2.718281828459;
    double result;
    cout.setf(ios::fixed);
    cout.precision(2);
    for(double i = -50;i<=50;i+=1){
        result = pow(e,i)/pow(1 + pow(e,2*i),1.5);
        cout<<"i = "<<i<<" || result = "<<result<<endl;
    }
}
