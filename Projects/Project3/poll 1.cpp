#include<iostream>
#include<string>
#include<cctype>
#include<cassert>
using namespace std;

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
    if(pollData.size()<2&&pollData.size()==3) return false;
    
    bool isValid;
    if(isValidUppercaseStateCode(pollData.substr(0,2))){
        isValid=true;
        if(pollData.size()==2)
            return true;
        else{
            int i = 3;
            while(i<pollData.size()&&isValid){
                if(isalpha(pollData[i])){
                    if(!isdigit(pollData[i-1])||(isdigit(pollData[i-1]) && pollData.size()==i+2))
                    isValid=false; //second char is letter but first
                    else if(i<=pollData.size()-2 && !isdigit(pollData[i+1]))
                        isValid = false;
                }
                else if(isdigit(pollData[i])){
                    if(i<=pollData.size()-2){ //test if the end is a number
                        if (!isdigit(pollData[i-1]) || !isalpha(pollData[i+1]))
                        {isValid=false;}
                    }
                    else {isValid = false;}
                    i++;
                }
                else isValid = false; //Neither Number Nor Digit
                i+=2;
            }
        }
    }
    else isValid = false; //test whether first two letters is a state
    return isValid;
    
}

/*
 
 if (isalpha(pollData[i]))
 {
 if(!isdigit(pollData[i-1]))
 return false;
 }
 else if(isdigit(pollData[i])){
 if(!(isdigit(pollData[i-1]) && isalpha(pollData[i+1])))
 {
 return false;
 }
 else i+=1;
 }
 
 
 */

int tallySeats(string pollData, char party, int& seatTally){
    if (!hasProperSyntax(pollData))
        return 1;
    else if(!isalpha(party))
        return 2;
    for(int i=3;i<pollData.size();i++){
        if(isalpha(pollData[i])){
            if(isdigit(pollData[i-1]))
                seatTally=pollData[i-1]+(isdigit(pollData[i-2])?pollData[i-2]*10:0);
            }
            
        }
    return 0;
    
}



int main(){
    /*
    assert(hasProperSyntax("CT5D,NY9R17D1I,VT,ne3r00D"));
    assert(!hasProperSyntax("CT5D,NY9R17D1I,VT,ne3r00D"));
    int seats;
    seats = -999;
    assert(tallySeats("CT5D,NY9R17D1I,VT,ne3r00D", 'd', seats) == 0  &&  seats == 22);
    seats = -999;    // so we can detect whether tallySeats sets seats
    assert(tallySeats("CT5D,NY9R17D1I,VT,ne3r00D", '%', seats) == 2  &&  seats == -999);
    cout << "All tests succeeded" << endl;
    
    */
    
    for(;;){
        cout<<"Enter poll data string: ";
        string pds;
        getline(cin,pds);
        if(pds=="quit")
            break;
        cout<<"hasproperSyntax returns ";
        if (hasProperSyntax(pds))
            cout << "true";
        else
            cout << "false";
        cout << endl;
    }
    
}




                
