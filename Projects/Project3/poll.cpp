#include<iostream>
#include<string>
#include<cctype>
#include<cassert>
using namespace std;
bool isValidUppercaseStateCode(string stateCode);
bool isStateForecast(string stateForecast);
bool hasProperSyntax(string pollData);
int tallySeats(string pollData, char party, int& seatTally);

/*Testing Code
int main(){
    assert(hasProperSyntax("CT5D,NY9R17D1I,VT,ne3r00D")&&hasProperSyntax(",,")&&hasProperSyntax(",")&&hasProperSyntax(""));
    assert(!hasProperSyntax("ZT5D,NY9R17D1I,VT,ne3r00D")&&!hasProperSyntax("Ca001d5n,NY1"));
    int seats;
    seats = -999;
    assert(tallySeats("CT5D,NY9R17D1I,VT,ne3r00D", 'd', seats) == 0  &&  seats == 22);
    seats = -999;
    assert(tallySeats("CT5D,NY9R17D1I,VT,ne3r00D",'d',seats)==0 && seats == 22);
    assert(hasProperSyntax("MA9D,KS4R")  &&  hasProperSyntax("KS4R,MA9D"));
    assert(hasProperSyntax("MA9D,,KS4R") == hasProperSyntax("KS4R,,MA9D"));
    seats = -999;
    assert(tallySeats("CT5r,,NY",'d',seats) ==0&&seats ==0);
    cout << "All tests succeeded" << endl;
}
 */


//Test whether the first two characters indicate a valid state
//PS:stateCode.find('.'): ensure that invalid input with "." won't be judged as true
bool isValidUppercaseStateCode(string stateCode)
{
    const string codes =
    "AL.AK.AZ.AR.CA.CO.CT.DE.FL.GA.HI.ID.IL.IN.IA.KS.KY."
    "LA.ME.MD.MA.MI.MN.MS.MO.MT.NE.NV.NH.NJ.NM.NY.NC.ND."
    "OH.OK.OR.PA.RI.SC.SD.TN.TX.UT.VT.VA.WA.WV.WI.WY";
    return (stateCode.size() == 2  &&
            stateCode.find('.') == string::npos  &&  // no '.' in stateCode
            codes.find(stateCode) != string::npos);  // match found
}

bool hasProperSyntax(string pollData){
    bool isValid = true;
    while(isValid&&pollData.find(',')!=string::npos){
        isValid = isStateForecast(pollData.substr(0,pollData.find(',')));
        if(!isValid) return false;
        pollData = pollData.substr(pollData.find(',')+1);
        }
    isValid = isStateForecast(pollData);//Necessary! Test validity when input contains no ","
    return isValid;
}
/* PSEUDOCODE
 Check size of string, false if <2
 
 
 check the first two char
    if not a state, return false
 
 check the last letter
    if not a letter, return false
 
 repeatedly:
    check the char str[i] of string
        if is a number, check next char(increment i by 1)
 
        if is an alpha
        check last digit, if is number
        increment i by 1
 
        else return False
 */

bool isStateForecast(string stateForecast){
    if(stateForecast.size()==0)
        return true;
    else if(stateForecast.size()==1)
        return false;
        
    for(int i=0;i<stateForecast.size();i++) //IMPORTANT! Convert to Uppercase
        stateForecast[i]=toupper(stateForecast[i]);
    if(!isValidUppercaseStateCode(stateForecast.substr(0,2)))
        return false;
    if(!isalpha(stateForecast[stateForecast.size()-1]))
        return false;
    
    //use isValid as an indicator to exit the loop if stateForecast is already INVALID
    int i=2;
    bool isValid=true;
    
    while(i!=stateForecast.size()&&isValid){
        if(isdigit(stateForecast[i]))
        {
            i++;
            continue;
        }
        else if(isalpha(stateForecast[i])){
            if(!isdigit(stateForecast[i-1]))
                isValid = false;
            
            //Check whether a party result has more than two digits.
            else if(isdigit(stateForecast[i-2])&&isdigit(stateForecast[i-3]))
                isValid = false;
        }
        else isValid=false;
        i++;
    }
    return isValid;
}

 
int tallySeats(string pollData, char party, int& seatTally){
    if (!hasProperSyntax(pollData))
        return 1;
    else if(!isalpha(party))
        return 2;
    seatTally = 0;
    for(int i=1;i<pollData.size();i++){
        if(toupper(pollData[i])==toupper(party)){ //always "Toupper" first, since 'd'!='D'
            if(isdigit(pollData[i-1]))
                seatTally+=pollData[i-1]-48+(isdigit(pollData[i-2])?((pollData[i-2]-48)*10):0);
        }
        
    }
    return 0;
    
}

/* My first version of isStateForecast():
 
 
 bool isStateForecast(string stateForecast){
 if(stateForecast.size()<2&&stateForecast.size()==3) return false;
 for(char c:stateForecast)
 c=toupper(c);
 if(!isValidUppercaseStateCode(stateForecast.substr(0,2)))
 return false;
 bool isValid = true;
 
 if(isValidUppercaseStateCode(stateForecast.substr(0,2))){
 isValid=true;
 if(stateForecast.size()==2)
 return true;
 else{
 int i = (int)stateForecast.size()-1;
 while(i>=2&&isValid){
 if (isalpha(stateForecast[i])){  //test whether last one is letter
 if(isdigit(stateForecast[i-1]))
 {if(isdigit(stateForecast[i-2]))
 i--;}
 else isValid=false;
 }else isValid = false;
 i-=2;
 }
 }
 }
 else{isValid = false;}
 return isValid;
 }
 */
