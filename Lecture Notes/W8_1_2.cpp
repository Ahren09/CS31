#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Employee
{
    string name;
    double salary;
    int age;
    
    
}; // MUST WRITE ";"

void printPaycheck(const Employee& e){ //pass by reference: save some memory
    //const: cannot change the value passed
    cout<<"Pay to the order of "<<e.name<<" the amount $"<<e.salary/12<<endl;
    
    
}
void celebrate(Employee &e){
    e.age++;
    
}
//OR
void celebrate(Employee *ep){
    ep->age++; //*ep.age won't compile, "." has higher precedence
    //(*ep).age is ok, UGLY!
    
}

double totalPayroll(const Employee emps[], int n){
    double total=0;
    for(int k=0;k<n;k++)
        total += emps[k].salary;
    return total;
    
}


int main(){
    Employee e1;
    Employee e2 = { .name="Ahren", .salary = -10000000, .age = 180};
    
    e1.name = "Fred";
    e1.salary=60000;
    e1.age = 50;
    e1.age++;
    
    cout<<e2.name<<endl;
    cout<<"Enter a name: ";
    getline(cin,e2.name);
    
    Employee company[100]; //get an array of Employee
    company[3].name = "Ricky";
    for(int k=0;k!=company[3].name.size();k++)
        cout<<company[3].name[k]<<endl;
    
    
    
    Employee Google[100];
    int nEmployee = 100;
    // ...read in info, fill some of the array, set nEmployees
    printPaycheck(Google[0]);
    celebrate(&company[1]);
    for(Employee* ep=company /*&OR company[0]*/; ep<company+nEmployee;ep++){
        cout<<ep->name<<endl;
    }
    cout<<totalPayroll(company,nEmployee)<<endl;
}
