#include <iostream>
#include <string>
using namespace std;

int main(){
    int start,end,distance,d,month;
    double amount=0;
    string lux,name = "";
    
    cout<<"Odometer at start: ";
    cin>>start;
    cout<<"Odometer at end: ";
    cin>>end;
    cout<<"Rental days: ";
    cin>>d;
    cout<<"Customer name: ";
    cin.ignore(10000,'\n');
    getline(cin,name);
    cout<<"Luxury car?(y/n): ";
    getline(cin,lux);
    cout<<"Month (1=Jan, 2=Feb, etc.): ";
    cin>>month;
    
    cout<<"---\n";
    
    
    if(start<0)
        cout<<"The starting odometer reading must be nonnegative.";
    else if(end<start)
        cout<<"The final odometer reading must be at least as large as the starting reading.";
    else if(d<=0)
        cout<<"The number of rental days must be positive.";
    else if(name=="")
        cout<<"You must enter a customer name.";
    else if(lux!="y"&&lux!="n")
        cout<<"You must enter y or n.";
    else if(month>12||month<1)
        cout<<"The month number must be in the range 1 through 12.";
    
    
    
        
    else{
        amount+=d*(lux=="y"?61:33);
        distance=end-start;
        if(distance<=100)
            amount+=distance*0.27;
        else
        {
            amount+=27;
            if(month==1||month==2||month==3||month==12)
                amount+=0.27*((distance-400)>=0?300:(distance-100));
            else amount+=0.21*((distance-400)>=0?300:(distance-100));
            amount +=0.19*((distance-400)>0?(distance-400):0);
        }
        cout.setf(ios::fixed);
        cout.precision(2);
        cout<<"The rental charge for "<<name<<" is $"<<amount<<endl;
    }
    
    
    return 0;
    
    
}

