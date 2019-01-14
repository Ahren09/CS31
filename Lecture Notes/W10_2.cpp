#include <string>
#include <iostream>
using namespace std;

class Fan{
    
public:
    void turnOn();
};

class Rock{
public:
    double weight() const;
    
};

class Robot{
    Fan m_cooler;
    Rock* m_rock;
    
public:
    void Blah();
    
};

void Robot::Blah(){
    if(m_rock!=nullptr && m_rock->weight()>=50)
        m_cooler.turnOn();
    
}

class Employee{
public:
    Employee(string nm, double sal);
    void receiveBonus(double rate) const;
private:
    string m_name;
    double m_salary;
    Company* m_company;
};

class Company{
public:
    Company();
    ~Company();
    void hire(string nm, double sal);
    void setBonusRate(double rate);
    void giveBonus() const;
    double bonusRate();
private:
    Employee* m_employees[100];
    int m_nEmployees;
    double m_bonusRate;
    
};

Employee::Employee(string nm, double sal){
    m_name = nm;
    m_salary = sal;
}



Company::Company(){
    m_nEmployees=0;
    m_bonusRate=0;
}

Company::~Company(){
    for(int k=0;k<m_nEmployees;k++) //Pay attention to loop limit
        delete m_employees[k];
    
}

void Company::hire(string nm, double sal){
    if(m_nEmployees == 100)
        cout<<"error";
    m_employees[m_nEmployees] = new Employee(nm,sal);
    m_nEmployees++;
}

void Company::setBonusRate(double rate){
    
    
    m_bonusRate=rate;
}

void Employee::receiveBonus() const
{
    cout<<"Pay to "<<m_name<<" $"<<m_company->bonusRate()*m_salary<<endl;
    
    
}

void Company::giveBonus() const{
    for(int k=0;k<m_nEmployees;k++)
        m_employees[k]->receiveBonus(m_bonusRate);
}

int main(){
    
    
    
}



