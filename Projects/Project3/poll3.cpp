#include<iostream>
#include<string>
#include<cctype>
#include<cassert>
#include<sstream>
#include<vector>
using namespace std;
bool isValidUppercaseStateCode(string stateCode);
bool isStateForecast(string stateForecast);
bool hasProperSyntax(string pollData);
int tallySeats(string pollData, char party, int& seatTally);

int main(){

    assert(hasProperSyntax("CT5D,NY9R17D1I,VT,ne3r00D"));
    assert(!hasProperSyntax("ZT5D,NY9R17D1I,VT,ne3r00D"));
    int seats;
    seats = -999;
    assert(tallySeats("CT5D,NY9R17D1I,VT,ne3r00D", 'd', seats) == 0  &&  seats == 22);
    seats = -999;
    assert(tallySeats("CT5D,NY9R17D1I,VT,ne3r00D",'d',seats)==0 && seats == 22);
    cout << "All tests succeeded" << endl;
    
}
// Testing Code

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
    isValid = isStateForecast(pollData);
    return isValid;
}


bool isStateForecast(string stateForecast){
    if(stateForecast.size()<2&&stateForecast.size()==3) return false;
    
    bool isValid;
    if(isalpha(stateForecast[0]) && isalpha(stateForecast[1]))
    {   stateForecast[0] = toupper(stateForecast[0]);
        stateForecast[1] = toupper(stateForecast[1]);
    }
    else return false;
    
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

int tallySeats(string pollData, char party, int& seatTally){
    if (!hasProperSyntax(pollData))
        return 1;
    else if(!isalpha(party))
        return 2;
    seatTally = 0; //? need initialization?
    for(int i=1;i<pollData.size();i++){
        if(toupper(pollData[i])==toupper(party)){
            if(isdigit(pollData[i-1]))
                seatTally+=pollData[i-1]-48+(isdigit(pollData[i-2])?((pollData[i-2]-48)*10):0);
        }
        
    }
    return 0;
    
}
