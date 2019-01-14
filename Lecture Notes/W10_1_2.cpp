#include <iostream>
#include <string>

using namespace std;



class Pet {
public:
    Pet(string nm,int initialHealth);
    void addToy();
    ~Pet(); //destructor
    
private:
    string m_name;
    int m_health;
    Toy* m_favoriteToy; //may or may not exist
}; // note the ";"

Pet::Pet(string nm, int initialHealth)
{
    m_name = nm;
    m_health = initialHealth;
    m_favoriteToy = nullptr; //default: not having a toy
    
}

//Feasible, but unpleasant to use
void Pet::cleanup(){
    delete m_favoriteToy;
    
}

Pet::~Pet(){
    delete m_favoriteToy;
    
    //The following is not necessary. The compiler will first check
    if(m_favoriteToy!=nullptr)
        delete m_favoriteToy;
    
}


void Pet::addToy{
    delete m_favoriteToy;
    m_favoriteToy = new Toy;
    // if does not delete toy first,
}


void f(){
    Pet p("Frisky", 20);
    p.addToy();
}

// Before a Pet is delete, must delete the toy of the pet

int main(){
    Pet* pp;
    pp= new Pet; //error, there's no constructor taking no argument
    pp = new Pet("Fidel",10);
    pp->addToy();
    delete pp;
    
    Pet pa[100];//Wrong!! Since pet must be initialized with arguments!!
    //Solution 1: write multiple constructors, with one of them taking no argument
    
    //Solution 2:Dynamically allocated array
    Pet* pa[100];
    
}


