#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Complex{
    
public:
    Complex(double re, double im);
    Complex();
    double real() const;
    double imag() const;
    
private:
    double m_rho;
    double m_theta;
    
};

Complex::Complex(double re, double im){
    m_rho=sqrt(re*re+im*im);
    m_theta=atan(im,re);
    
}

Complex::Complex(){
    m_rho=0;
    m_theta=0;
    
}

double Complex::real() const{
    return m_rho*cos(m_theta);
    
}

double Complex::imag() const{
    return m_rho*sin(m_theta);
}

//Overloading
void f(int i);
void f(double d);

void g(int i,double d);
void g(double d,int i);

int main(){
    Complex c1(4, -1);
    cout<<c1.real();
    Complex ca[100];
    
    
    f(1);
    f(1.0);
    //BUT WHAT IF??
    f('a');
    
    
    g(1,2); //Ambiguous situation: all versions of Conversions are Equally bad - compilation error
    
}
