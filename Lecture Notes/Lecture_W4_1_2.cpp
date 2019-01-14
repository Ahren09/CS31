#include<iostream>
#include<string>
#include<cctype>
using namespace std;

void ChangeArray(int arr[], int size){
    for(int i=0;i<size;i++)
        arr[i]++;
}

bool isValidPhoneNumber(string phone){
    int num=0,i=0;
    while(i<phone.size()){
        if(isdigit(phone[i]))
            num++;
        i++;
    }
    return num == 10;
}

string digitsOf(string pn){
    int i=0;
    string number="";
    while(i<pn.size()){
        if(isdigit(pn[i]))
            number+=pn[i];
        i++;
    }
    return number;
}
    


int main()
{
    string phone;
    while(true){
        
        cout<<"Enter Phone Number: ";
        getline(cin,phone);
        if(isValidPhoneNumber(phone))
            break;
        cout<<"A phone number must have 10 digits"<<endl;
    }
    cout<<"Digits are: "<<digitsOf(phone)<<endl;
    return 0;
}
    
    /*
     string s ="";
     cout<<s.length()<<endl;
     cout<<s.size()<<endl;
     cout<<s.length()-1<<endl;
     cout<<s.size()-1<<endl;
     
     int arr[20] = {{1},{2}};
     for(int i : arr) cout<<i<<" ";
     cout<<endl;
     ChangeArray(arr[], 20);
     for(int i : arr) cout<<i<<" ";
     */
