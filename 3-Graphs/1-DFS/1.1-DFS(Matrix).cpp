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

void DFS(int graph[N][N]);
void DFS_vis(int graph[N][N],bool visited[N],int w);
void DFS_vis_stack(int graph[N][N],bool visited[N],int w);

int main(){
    int graph_skier[N][N]={
        {0,0,0,0,0,1}, //A
        {0,0,1,1,0,0}, //B
        {0,0,0,0,0,0}, //C
        {0,0,0,1,0,0}, //D
        {0,1,1,0,0,0}, //E
        {0,0,0,0,0,0}, //F
    };
    int graph[N][N]={
        {0,1,0,0,1,0}, //A
        {1,0,0,1,1,1}, //B
        {0,0,0,1,0,1}, //C
        {0,1,1,0,0,0}, //D
        {1,1,0,0,0,0}, //E
        {0,1,1,0,0,0}, //F
    };
    cout << "Graf nieskierowany:" << endl;
    PrintGraph(graph);
    DFS(graph);
    cout << "Skierowany:" << endl;
    PrintGraph(graph_skier);
    DFS(graph_skier);


    return 0;
}
void DFS(int graph[N][N]){
    bool visited[N];
    for(int i=0;i<N;i++)
        visited[i]=false;
    for(int i=0;i<N;i++){
        if(!visited[i]){
            cout << "Zaczynam od: " << char(65+i) << endl;
            DFS_vis(graph,visited,i);
        }
    }
}
void DFS_vis(int graph[N][N],bool visited[N],int w){
    visited[w]=true;
    cout << "   " << "Odwiedzam: " << char(65+w) << endl;
    for(int i=0;i<N;i++)
        if(graph[w][i]!=0)
            if(!visited[i])
                DFS_vis(graph,visited,i);

}
void DFS_vis_stack(int graph[N][N],bool visited[N],int w){
    stack < int > s;
    visited[w]=true;
    cout << "   " << "Odwiedzam: " << char(65+w) << endl;
    while(!s.empty()){
        int w=s.top(); s.pop();
        for(int i=0;i<N;i++)
            if(graph[w][i]!=0)
                if(!visited[i])
                    s.push(i);
    }
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


