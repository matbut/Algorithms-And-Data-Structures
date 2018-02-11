#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <queue>
#include <stack>
const int N=6;
const int ACTIVE=14;
const int VISITED=8; //153; //mielizna
const int NORMAL=7;

using namespace std;

void Color(int c);
void PrintColor();

void PrintGraph(int graph[N][N]);

void DFS_Euler(int graph[N][N]);
void DFS_vis_Euler(int graph[N][N],int visited[N][N],int w);
void DFS_vis_stack(int graph[N][N],int visited[N][N],int w);

int main(){
    int graph[N][N]={
        {0,1,0,1,0,0}, //A
        {1,0,1,0,0,0}, //B
        {0,1,0,1,1,1}, //C
        {1,0,1,0,0,0}, //D
        {0,0,1,0,0,1}, //E
        {0,0,1,0,1,0}, //F
    };

    cout << "Graf:" << endl;
    PrintGraph(graph);
    DFS_Euler(graph);


    return 0;
}
void DFS_Euler(int graph[N][N]){
    cout << endl << "Cykl Eulera:" << endl;
    int visited[N][N]; // pomocnicza tablica do usuwania krawêdzi
    for(int i=0;i<N*N;i++)
        visited[i/N][i%N]=graph[i/N][i%N];
    DFS_vis_Euler(graph,visited,0);
}
void DFS_vis_Euler(int graph[N][N],int visited[N][N],int w){
    for(int i=0;i<N;i++)
            if(visited[w][i]==1){
                visited[w][i]=0;
                visited[i][w]=0;
                DFS_vis_Euler(graph,visited,i);
            }
    cout << char('A'+w) << "-";
}
void PrintGraph(int graph[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(graph[i][j]==0)
                Color(VISITED);
            else
                Color(NORMAL);
            cout << " " << graph[i][j];
        }
        Color(NORMAL);
        cout << endl;
    }
}

void Color(int c) {
     //7 bialoszary 8 szary 15bialy 14 zolty
     HANDLE uchwyt;
     uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(uchwyt,c);
}
void PrintColor(){
    for(int i=0;i<256;i++){
        Color(i);
        cout << i << endl;
    }
}


