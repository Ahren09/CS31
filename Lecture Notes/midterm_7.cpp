//
//  midterm_7.cpp
//  CS31
//
//  Created by 靳轶乔 on 10/21/18.
//  Copyright © 2018 靳轶乔. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int score=0;
    char judge = 'y';
    
    do{
        cout<<endl<<"Please enter the student's score: ";
        cin>>score;
        switch(score/10){
            case 10:
            case 9:
                cout<<"Score is A"<<endl;
                break;
            case 8:
                cout<<"Score is B"<<endl;
                break;
            case 7:
                cout<<"Score is C"<<endl;
                break;
            case 6:
                cout<<"Score is D"<<endl;
                break;
            default:
                cout<<"Score is F"<<endl;
                break;
                
        }
        cout<<"Continue?(y/n): ";
        cin>>judge;
    }while(judge=='y');
    return 0;
}
