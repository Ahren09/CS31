#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int getVolume(double a, double b=1, double c=1){
    return a*b*c;

}

int main()
{
    /*
    char c[5];
    string s,str;
    
    //cin>>s;
    
    for(int i=0;i<5;i++){
        cin>>c[i];
        //cin>>noskipws>>c[i];
    }
    cin>>s>>str;
    cout<<c<<endl<<s<<endl<<str<<endl;
    cout<<strlen(c)<<endl;
     cout<<sizeof(c)<<endl;
    
    enum e {E,W,S,N};
    int i = e;
    cout<<i<<endl;

    cout.setf(ios::fixed);
    cout.precision(2);
    double p = pow(2.0,3.0);
    cout<<p<<endl;
    cout<<static_cast<double>(static_cast<int>(p))<<endl;
    int i;
    srand(98);
    for (i = 0; i < 10; i++)
        cout << (rand( ) % 11) << endl;
    srand(98);
    for (i = 0; i < 10; i++)
        cout << (rand( ) % 11) << endl;
     */
    int a,b,c;
    cin>>a>>b;
    cout<<"Volume: "<<getVolume(a,b,c)<<endl;
    cout<<"Volume: "<<getVolume(4)<<endl;
    return 0;
    
}

