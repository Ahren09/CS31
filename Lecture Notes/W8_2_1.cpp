#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct target{
    //"member functions" "operations" "methods"
    //These three func have special permission to manipulate
public:
    //void init();
    target(); //constructor
    bool move(char dir);
    int position() const; //putting const after the function, so that compiler knows that function won't modify a member variable
    void replayHistory() const;
    void report(target x);
        
    
    
    
    
private:
    //only
    
    //"data members" of type" "attributes"
    //"fields" "instance variables"
    int pos;
    //pos can be deleted because it can be figured out through history
    
    string history;
    
  
    
};

class

//This specifies that function belongs to target
//since there might be player::init(); ...


//Constructor: no return type

target::target(){
    pos=0;
    history="";
    
}

/*
void target::init(){
 //generates a pointer to the object already created, instead of creating a new one
 
    //"this" is the name for the pointer generated
    //"this" represents the object you call this function on
    this->pos=0;//points to t;
    this->history="";
}
 */

//void f(const target& x){...} //won't compile

int target::position() const{
    
    // this->pos++; //won't compile
    return this->pos;
    
}

bool target::move(char dir){
    switch(dir){
        case 'r':
        case 'R':
            pos++;
            break;
        case 'L':
        case 'l':
            pos--;
            break;
        default:
            return false;
    }
    history +=toupper(dir);
    return true;
    
}
void target::replayHistory() const{
    for(int k=0;k<history.size();k++){
        cout<<history[k];
    }
    
    
}

void repeatMove(target& x, int nTimes, char dir){
    for(int k=0;k<nTimes;k++)
        x.move(dir);
}

void report(const target& x){ //cheaper cost because just passing t2
    cout<<"There's a target at position "<<x.position()<<endl;
    
    
}


void f(){
    while(){
        playGame();
        
    }
    
}

void playGame(){
    target *targets[100];
    int nTargets = 0; //track number of targets currently have
    if()
        addTargets(targets,nTargets,3);
    int i;
    targets[i]->move('R'); //targets is an array of POINTERS!
    
    delete targets[1]; //delete the object pointed by this pointer
    //now, undefined behavior to follow this pointer: *targets[1]
    //"dangling pointer"
    
    targets[1]=targets[2]; //now, dangling pointer liminated
    ntargets--;
    targets[2]=nullptr; //not necessary, if following convention
    
    targets[nTargets] = new target;
    nTargets++;
    
    for(int k=0;k<nTargets;k++)
        delete targets[k];
    
}


// Dynamic Allocated Array
void addTargets(target* ta[],int& nt, int howManyNewOnes){
    for(int k=0;k<howManyMore;k++){
        //"new" - give new space to target
        ta[nt]=new target; 
        /*WRONG: Creating Local Variables
         target t;
         ta[nt]=&t;
         */
        nt++;
    }
    
}

class Person{
public:
    Person(string nm,int by);
    string name() const;
private:
    string m_name;
    int m_birthYear;
    
}

//Constructor that takes parameter
Person::Person(string nm, int by){
    name = nm;
    birthYear= by;
    
}

string Person::name() const{
    return m_name;
    
}


/*
 Person::Person(string name, int by){
 this->name = name; //"this" indicates the object we alter//This is not convenient
 birthYear= by;
 }
 
 
 */

Person p("Fred",1999);


int main(){
    target t;
    target t2;
    //t.init();
    t2=t; //legal!
    t.move('R');
    t.move('r');
    for(int i=0;i<4;i++)
        t.move('L');
    
    t.pos=23;// won't compile
    cout<<t.pos; //won't compile
    
    repeatMove(t,4,'R');
    report(t2);
    
    //not initializing a target before we actually use it
    
    
    Target ta[3];
    ta[0].move('L');
    ta[1].move('R');
    repeatMove(ta[2],'L',3);
    
    int k=1;
    ta[k]->move('R');
}
