#include <iostream>
#include <string>

class BankAccount{
    
public:
    BankAccount(double balance, int password);
    bool deposit(double amount, int pw);
    bool withdraw(double amount, int pw);
    int balance(int pw) const;
    bool setPassword(int pw, int newpw);
    
private:
    double m_balance;
    int m_password;
};

BankAccount getNewAccount(int pw){
    return new BankAccount(10,pw);
    
}

BankAccount::BankAccount(double balance, int password){
    if(balance<0)
        m_balance=0.00;
    else m_balance=balance;
    m_password=pw;
    
}

double BankAccount::balance(int pw) const{
    if(pw==m_password)
        return m_balance;
    return -1;
}

bool BankAccount::deposit(double amount, int pw){
    if(pw==m_password && amount>=0){
        m_balance+=amount;
        return true;
    }
    return false;
}

bool BankAccount::withdraw(double amount, int pw){
    if(pw==m_password){
        if(m_balance<0||amount>m_balance||amount<0)
            return false;
        m_balance-=amount;
        return true;
    }
    return false;
}


bool BankAccount::setPassword(int pw, int newpw){
    if(m_password==pw){
        m_password=newpw;
        return true;
    }
    return false;
}


class CoinMoon
{
public:
    CoinMoon();
    void addDollar(); // Add a dollar coin to the machine.
    void addQuarter(); // Add a quarter to the machine.
    void addDime(); // Add a dime to the machine.
    void addNickel(); // Add a nickel to the machine.
    void addPenny(); // Add a penny to the machine.
    void giveMeBills(); // Print what the user will get.
    // See the example below.
private:
    // TODO: Add private variables here.
    double m_amount
};

CoinMoon::CoinMoon(){
    m_amount=0;
}
void CoinMoon::addDollar(){
    m_amount+=1;
}
void CoinMoon::addQuarter(){
    m_amount+=0.25;
}
void CoinMoon::addDime(){
    m_amount+=0.1;
}
void CoinMoon::addNickel(){
    m_amount+=0.05;
}
void CoinMoon::addPenny(){
    m_amount+=0.01;
}
void CoinMoon::giveMeBills(){
    int dollar=m_amount;
    cout<<dollar<<" dollar bill(s)"<<endl;
    m_amount-=dollar;
    
    int quarter=m_amount/0.25;
    cout<<quarter<<" quarter(s)"<<endl;
    m_amount-=quarter*0.25;
    
    
    int dime=m_amount/0.1;
    cout<<dime<<" dime(s)"<<endl;
    m_amount-=dime*0.1;
    
    int nickel=m_amount/0.05;
    cout<<nickel<<" nickel(s)"<<endl;
    m_amount-=nickel*0.05;
    
    int penny=m_amount/0.01;
    cout<<penny<<" penny(ies)"<<endl;
    
}

const char RESERVED = 'R';
const char OCCUPIED = 'O';
const char EMPTY = 'E';
const int FLOORS = 20;
const int ROOMSPERFLOOR = 50;
class Hotel
{
public:
    Hotel();
    bool reserve(int roomNum);
    bool cancel(int roomNum);
    bool checkIn(int roomNum);
    bool checkOut(int roomNum);
    int numEmpty(int floor) const;
private:
    char m_rooms[FLOORS][ROOMSPERFLOOR];
    // More private members here, if necessary.
    bool checkRoom(int roomNum, int f, int n);
    
};
Hotel::Hotel()
{
    // EMPTY the rooms.
    for (int i = 0; i < FLOORS; i++)
        for (int j = 0; j < ROOMSPERFLOOR; j++)
            m_rooms[i][j] = EMPTY;
}

bool Hotel::reserve(int roomNum)
{
    // TODO: If the room is EMPTY, set it to RESERVED, and return true.
    // In all other cases, do not change anything and return false.
    int f,n;
    if(!checkRoom(roomNum,f,n))
       return false;
    
    if(m_rooms[f][n]==EMPTY)
    {
        m_rooms[f][n]=RESERVED;
        return true;
    }
    return false;
}
    
bool Hotel::cancel(int roomNum)
{
        // TODO: If the room is RESERVED, set it to EMPTY, and return true.
        // In all other cases, do not change anything and return false.
    
    int f,n;
    if(!checkRoom(roomNum,f,n))
       return false;
    if(m_rooms[f][n]==RESERVED)
    {
        m_rooms[f][n]=EMPTY;
        return true;
    }
    return false;
}
bool Hotel::checkIn(int roomNum)
{
        // TODO: If the room is RESERVED, set it to OCCUPIED, and return true.
        // In all other cases, do not change anything and return false.
    int f,n;
    if(!checkRoom(roomNum,f,n))
       return false;
    if(m_rooms[f][n]==RESERVED)
    {
        m_rooms[f][n]=OCCUPIED;
        return true;
    }
    return false;
}
bool Hotel::checkOut(int roomNum)
{
        // TODO: If the room is OCCUPIED, set it to EMPTY, and return true.
        // In all other cases, do not change anything and return false.
    int f,n;
    if(!checkRoom(roomNum,f,n)
       return false;
    if(m_rooms[f][n]==OCCUPIED)
    {
        m_rooms[f][n]=EMPTY;
        return true;
    }
    return false;
}
int Hotel::numEmpty(int floor)
{
    // TODO: Return the number of empty rooms on the floor.
    // Return -1 if floor is invalid.
    int f,n;
    if(!checkRoom(roomNum,f,n)
       return -1;
    
    int nEmpty = 0;
    for(int i=0;i<50;i++){
        if(m_rooms[floor][i]==EMPTY)
            nEmpty++;
    }
    return nEmpty;
    
}
    // Write helper functions down here if necessary.

bool checkRoom(int roomNum, int& f, int& n);
{
    f=roomNum/100;
    n=roomNum%100;
    if(f>=0 && f<20 && n>=0 && n<50)
        return true;
    else return false;
}
       
    
       


