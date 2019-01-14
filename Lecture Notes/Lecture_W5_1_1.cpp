
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int score[10000];
    int nScore=0;
    int total = 0;
    cout<<"Enter the scores(Negative when done):";
    for(;;)
    {
        int s;
        cin>>s;
        if(s<0)
            break;
        total+=s;
        nScore++;
    }
    if(nScore==0)
    cout<<"There were no scores";
    else{
        double mean =static_cast<double>(total);
    // double temp = total; 不可 已丢数据
    cout<<"The average of all scores is:"
    <<mean/nScore<<endl;
        cout<<"The average of all the scores is "<<mean<<endl;
        double sumOfSquares=0;
        for(int k=0;k<nScore;k++)
        {
            double diff = score[k]-mean;
            sumOfSquares+=diff*diff;
        }
        cout<<"The Standard Deviation is "<<sqrt(sumOfSquares/nScore)<<endl;
        
    }
}
