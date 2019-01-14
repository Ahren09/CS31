#include <iostream>
#include <set>
#include <map>
using namespace std;

int main(){
    map<string,string> planets;
    planets["Mercury"] = "Hot planet";
    planets["Venus"] = "Full of CO2";
    planets["Earth"] = "Home";
    planets["Mars"] = "The Red Planet";
    planets["Jupiter"] = "Largest planet in our solar system";
    planets["Saturn"] = "Has rings";
    planets["Uranus"] = "Tilts on its side";
    planets["Neptune"] = "1500 mile-per-hour winds";
    planets["Pluto"] = "Dwarf planet";
 
    if(planets.find("Mercury")!=planets.end())
        cout<<"Mercury found"<<planets["Mercury"];
    if(planets.find("Ceres")==planets.end())
        cout<<"Ceres not found";
    
    cout<<"\n\nAll elements:\n";
    
    map<string,string>::iterator it;
    for(it=planets.begin();it!=planets.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    
    map<int,int> numset;
    for(int i=1;i<10;i++)
        numset[i]=i*11111;
    map<int,int>::const_iterator p;
    for(p=numset.begin();p!=numset.end();p++)
        cout<<p->first<<" "<<p->second<<endl;
    
    /*
    
    set<char> s;
    cout<<"Input elements of set: ";
    char ch;
    cin.get(ch);
    while(ch!='\n')
    {
        s.insert(ch);
        cin.get(ch);
    }
    
    cout<<endl<<"Set ";
    if(s.find('C')==s.end())
        cout<<"doesn't contain";
    else cout<<"contains ";
    cout<<"C\n";
    
    s.erase('C');
    cout<<endl;
    
    set<char>::const_iterator p;
    for(p=s.begin();p!=s.end();p++){
        cout<<*p;
    }
    cout<<endl;
    
    cout<<endl<<"Set ";
    if(s.find('C')==s.end())
        cout<<"doesn't contain ";
    else cout<<"contains";
    cout<<"C\n";
    
    */
    
}
