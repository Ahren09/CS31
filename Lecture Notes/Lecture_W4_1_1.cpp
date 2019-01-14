#include<iostream>
#include<string>
#include<cctype>
#include<cmath>
using namespace std;

void polarToCartisian(double rho, double theta, double &xx, double& yy){
    
    xx=rho*cos(theta);
    yy=rho*sin(theta);
    
}


int main(){
    double rho = 1, theta = 2, x = 1,y = 1;
    polarToCartisian(rho,theta,x,y);
    cout<<"rho = "<<rho<<", theta = "<<theta<<", x = "<<x<<" ,y = "<<y<<endl;
    return 0;
}
