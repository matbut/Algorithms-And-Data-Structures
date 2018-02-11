#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <queue>
#include <stack>
const int NOT_VISITED=-1;
const int PROCESSED=0;
const int VISITED=1;
const int INF=100;

using namespace std;

struct vert;
struct neibour;

struct vert{;
    int idx;
    char name;
	neibour*ne;
	// DO BFS:
	int color;
	vert*parent;
	int len_to_start;
};
struct neibour{
    vert*v;
    neibour*next;
};
void PrintGraph(vert**G,int n);
vert**Init(int n);

void BFS(vert**G,int n,int start);

int main(){
    int n=6;
    vert**G=Init(n);
    PrintGraph(G,n);
    BFS(G,n,0);

    return 0;
}
void BFS(vert**G,int n,int start){
    queue < int > Q;

    for(int i=0;i<n;i++){
        G[i]->color=NOT_VISITED;
        G[i]->parent=NULL;
        G[i]->len_to_start=INF;
    }
    G[start]->color=PROCESSED;
    G[start]->len_to_start=0;

    Q.push(start);

    while(!Q.empty()){
        int u=Q.front(); Q.pop();
        neibour*q=G[u]->ne;
        while(q!=NULL){
            if(q->v->color==NOT_VISITED){
                q->v->color=PROCESSED;
                q->v->parent=G[u];
                q->v->len_to_start=G[u]->len_to_start+1;
                Q.push(q->v->idx);
            }
            q=q->next;
        }
        G[u]->color=VISITED;
    }
}
vert**Init(int n){
    int graph[n][n]={
        {0,1,0,0,1,0}, //A
        {1,0,0,1,1,1}, //B
        {0,0,0,1,0,1}, //C
        {0,1,1,0,0,0}, //D
        {1,1,0,0,0,0}, //E
        {0,1,1,0,0,0}, //F
    };
    vert**G=new vert*[n];
    for(int i=0;i<n;i++)
        G[i]=new vert;
    for(int i=0;i<n;i++){
        G[i]->idx=i;
        G[i]->name=(char)(i+'A');
        int j;
        G[i]->ne=NULL;
        for(j=n-1;j>=0;j--)
            if(graph[i][j]==1){
                neibour*q=new neibour;
                q->next=G[i]->ne;
                G[i]->ne=q;
                G[i]->ne->v=G[j];
            }
    }
    return G;
}
void PrintGraph(vert**G,int n){
    cout << "Wierzcholki grafu G:" << endl;
    for(int i=0;i<n;i++){
        cout << "Wierzcholek " << G[i]->name << " ma sasiadow: ";
        neibour*q=G[i]->ne;
        while(q!=NULL){
            cout << q->v->name << " ";
            q=q->next;
        }
        cout << endl;
    }
}
