#include <iostream>
#include <cstdlib>
#include <ctime>
const int n=6;
const int INF=100;

using namespace std;

int**Init(int n);
void PrintGraph(int V[n][n],int n);
void Dijkstra(int V[n][n],int start,int n,int*dist,int*prt);

int main(){
    int V[n][n]={
    //   A B C D E F
        {0,1,4,0,0,0}, //A
        {1,0,2,6,0,0}, //B
        {0,0,0,1,5,0}, //C
        {0,0,0,0,3,9}, //D
        {0,0,0,0,0,0}, //E
        {0,0,0,0,0,0}, //F
    };
    PrintGraph(V,n);
}
void Dijkstra(int V[n][n],int start,int n,int*dist,int*prt){
    prt=new int[n];
    dist=new int[n];
    visited=new int[n];
    for(int i=0;i<n;i++){
        dist[i]=INF;
        prt[i]=-1;
    }
    dist[start]=0;
    for(int i=0;i<n;i++){
        int u=0;
        for(int j=0;j<n;j++)
            if(j!=i and !visited[j] and dist[j]<dist[i])
    }
}
void PrintGraph(int V[n][n],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << V[i][j] << " ";
        cout << endl;
    }
}





