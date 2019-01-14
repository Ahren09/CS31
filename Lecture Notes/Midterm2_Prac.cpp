#include <string>
#include <iostream>
using namespace std;

int updatePoints(int pos)
{
    if( pos == 3 ) return 1;
    if( pos == 1 ) return -1;
    if( pos == 5 ) return 2;
    if( pos == 2 ) return -2;
    return 0;
}
int executeCommands(string cmdStr, int pos, int points)
{
    for(char c:cmdStr)
        if(c!='L'&&c!='R'&&c!='U'&&c!='D')
            return -1;
    int size=cmdStr.size();
    points += updatePoints(pos);
    char CString[50];
    strcpy(CString,cmdStr.c_str());
    for(char *i=CString;i<CString+size;i++){
        if(*i=='L')
            pos--;
        else if(*i=='R')
            pos++;
        points+=updatePoints(pos);
        
    }
    return points;
}
int main()
{
    string command1 = "LULDR";
    string command2 = "LRDULRDUXX";
    string command3 = "UUDDLLRRBA";
    string command4 = "DDURDDUR";
    cout << executeCommands(command1, 0 , 0) << endl;
    cout << executeCommands(command2, 1 , 1) << endl;
    cout << executeCommands(command3, 2 , 2) << endl;
    cout << executeCommands(command4, 3 , 3) << endl;
}
