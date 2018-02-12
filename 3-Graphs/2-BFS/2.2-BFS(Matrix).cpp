#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <queue>
#include <stack>
const int N=6;
const int NOT_VISITED=-1;
const int PROCESSED=0;
const int VISITED=1;
const int INF=100;

const int SZARY=8;
const int NORMAL=7;

using namespace std;

struct BFS_data{
	int color;
	int parent;
	int len_to_start;
};

void Color(int c);
void PrintColor();

void PrintGraph(int graph[N][N]);
void BFS(int graph[N][N],int w);

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
    BFS(graph,0);
    cout << "Skierowany:" << endl;
    PrintGraph(graph_skier);
    BFS(graph_skier,0);


    return 0;
}
void BFS(int graph[N][N],int start){
    queue < int > Q;
    BFS_data data[N];
    for(int i=0;i<N;i++){
        data[i].color=NOT_VISITED;
        data[i].parent=INF;
        data[i].len_to_start=INF;
    }
    data[start].color=PROCESSED;
    data[start].len_to_start=0;

    Q.push(start);
    while(!Q.empty()){
        int u=Q.front(); Q.pop();
        for(int i=0;i<N;i++)
            if(i!=start and graph[u][i]==1)
                if(data[i].color==NOT_VISITED){
                    data[i].color=PROCESSED;
                    data[i].parent=u;
                    data[i].len_to_start=data[u].len_to_start+1;
                    Q.push(i);
                }
        data[u].color=VISITED;
    }
}


void PrintGraph(int graph[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(graph[i][j]==0)
                Color(SZARY);
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


