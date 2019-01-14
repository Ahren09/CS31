
#include <iostream>
using namespace std;

int main1(){
    const int MAX_NUM_OF_SCORES = 10000;
    int scores[MAX_NUM_OF_SCORES];
    int nScores=0;
    int total = 0;
    cout<<"Enter the scores(Negative when done):";
for(;;)
{
    int s;
    cin>>s;
    if(s<0)
        break;
    if(nScores==0){
        cout<<"I can handle only "<<MAX_NUM_OF_SCORES<<" scores!"<<endl;//examine whether out of bound
        break;
    }
    total+=s;
    scores[nScores] = s;
    nScores++;
}
    if(nScores==0)
        cout<<"There were no scores";
    else
        // double temp = total; 不可 已丢数据
        cout<<"The average of all scores is:"
        <<static_cast<double>(total)/nScores<<endl;
}

double computeMean()
{
    
    
    
}
