//
// Created by Tyler on 2018/10/22.
// A Tester for poll.cpp
//

#include <cassert>
#include <iostream>
#include <string>
#define TRASH_VAL 0x80808080
using namespace std;

extern bool hasProperSyntax(string pollData);

extern int tallySeats(string pollData, char partyCode, int& seatTally);

int main() {
    //normal
    assert(hasProperSyntax("nY10R34D,Nc00A"));
    assert(hasProperSyntax("CT5D,NY9R17D1I,VT,ne3r00D"));
    assert(hasProperSyntax("ct5D,NY9R17D1I,VT,ne3r00D"));
    //Empty String
    assert(hasProperSyntax(""));
    //One state
    assert(hasProperSyntax("VT"));
    //One state & One data
    assert(hasProperSyntax("VT0r"));
    //wrong state code
    assert(!hasProperSyntax("ZT5D,NY9R17D1I,VT,ne3r00D"));
    //special char
    assert(!hasProperSyntax("CT5D,NY9R17D1I,VT, ne3r00D"));
    assert(!hasProperSyntax(string("CT5D") + '\0' + ",NY9R17D1I,VT,ne3r00D")); // make sure there can be a '\0' in str
    //an extra number at the end
    assert(!hasProperSyntax("ct5D,NY9R17D1I,VT,ne3r00D1"));
    //an extra number in seat
    assert(!hasProperSyntax("CT5D,ny9R171D1I,VT,ne3r00D"));
    //no number before party code
    assert(!hasProperSyntax("CT5D,NY9R17DI,VT,ne3r00D"));
    //Maybe out-of-bound error with one char "state code"
    assert(!hasProperSyntax("CT5D,NY9R17D1I,V,ne3r00D"));
    //empty state result
    assert(!hasProperSyntax("CT5D,NY9R17D1I,,ne3r00D"));
    assert(!hasProperSyntax(",CT5D,NY9R17D1I,VT,ne3r00D"));
    int seats;
    seats = TRASH_VAL;    // so we can detect whether tallySeats sets seats
    assert(tallySeats("CT5D,NY9R17D1I,VT,ne3r00D", 'd', seats) == 0  &&  seats == 22);
    seats = TRASH_VAL;    // so we can detect whether program runs with multiple seat data of same party in same state
    assert(tallySeats("NY9R17D1I,VT,NJ3D5R4D,KS4R", 'd', seats) == 0  &&  seats == 24);
    seats = TRASH_VAL;    // so we can detect whether tallySeats sets seats
    assert(tallySeats("CT5D,NY9R17D1I,VT,ne3r00D", 'A', seats) == 0  &&  seats == 0);
    seats = TRASH_VAL;    // so we can detect whether tallySeats sets seats
    assert(tallySeats("", 'r', seats) == 0  &&  seats == 0);
    seats = TRASH_VAL;    // so we can detect whether syntax check works properly
    assert(tallySeats(",CT5D,NY9R17D1I,VT,ne3r00D", 'k', seats) == 1  &&  seats == TRASH_VAL);
    seats = TRASH_VAL;    // so we can detect whether tallySeats sets seats
    assert(tallySeats("CT5D,NY9R17D1I,VT,ne3r00D", '%', seats) == 2  &&  seats == TRASH_VAL);
    seats = TRASH_VAL;    // so we can detect whether tallySeats sets seats with internal special character
    assert(tallySeats("CT5D,NY9R17D1I,VT,ne3r00D", '\0', seats) == 2  &&  seats == TRASH_VAL);
    cout << "All tests succeeded" << endl;
    return 0;
}

