#include <iostream>
const int N=6;
const int INF=99;

using namespace std;

void PrintGraph(int graph[N][N]);
void Floyd_Warshall(int graph[N][N],int D[N][N]);
int Min(int a,int b){
    if(a<=b)
        return a;
    return b;
}
int main(){
    int graph[N][N]={
    //   A B C D E F
        {0,2,0,0,5,0}, //A
        {1,0,0,1,2,1}, //B
        {0,0,0,3,0,10}, //C
        {0,5,1,0,0,0}, //D
        {0,0,0,0,0,0}, //E
        {2,0,0,0,3,0}, //F
    };
    PrintGraph(graph);
    int D[N][N];
    Floyd_Warshall(graph,D);
    PrintGraph(D);
    return 0;
}
void Floyd_Warshall(int graph[N][N],int D[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            if(i!=j)
                if(graph[i][j]>0)
                    D[i][j]=graph[i][j];
                else
                    D[i][j]=INF;
            else
                D[i][j]=0;
    }
    PrintGraph(D);
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                D[i][j]=Min(D[i][j],D[i][k]+D[k][j]);
}
void PrintGraph(int graph[N][N]){
    cout << "Graf:" << endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout.width(3);
            cout << graph[i][j];
        }
        cout << endl;
    }
}


