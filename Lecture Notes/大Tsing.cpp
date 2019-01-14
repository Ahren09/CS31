#include <iostream>
#include <string>
using namespace std;

const int INF = 10000;
const int M = 3;
const int N=3;
int h[M+1][N] = {
    
    {3,2,3},
    {2,1,7},
    {7,3,5},
    {1,1,2}
};
int v[M][N+1] = {
    
    {2,2,3,4},
    {3,3,5,4},
    {1,1,2,3}
};
/*
int shortest_path(int x, int y){
    if(!x && !y)
        return 0;
    if(dis[y][x]>0)
        return dis[y][x];
    int dx = INF;
    if(x>0)
        dx = shortest_path(x-1,y);
    if(y>0)
        dy=shortest_path(x,y-1);
    
              dis[y][x]=(dx>dy)?dy:dx;
              return dis[y][x];
    
}
*/

int pos(int a[][7],int x, int y, bool isKnight){
    
    
    else if(x==0||y==0)
        a[x][y]=1;
    else{
        a[x][y]=isKnight[x-1][y]pos(a,x-1,y)+pos(a,x,y-1);
    }
    return a[x][y];
    
}



int main(){
    int matrix[7][7];
    matrix[0][0]=1;
    cout<<"Number of Routes: "<<pos(matrix,6,6)<<endl;
    
    
    
}
