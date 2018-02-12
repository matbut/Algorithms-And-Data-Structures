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
    char name;
	neibour*ne;
	// DO BFS:
	int color;
	vert*parent;
	int len_to_start;
	int licznik;
};
struct neibour{
    int idx;
    neibour*next;
};
void PrintGraph(vert**G,int n);
vert**Init(int n);

void BFS(vert**G,int n,int start,int koniec);

int main(){
    int n=10;
    vert**G=Init(n);
    PrintGraph(G,n);
    BFS(G,n,0,5);

    cout << "jest " << G[5]->licznik << " sciezek z " << G[0]->name << " do " << G[5]->name;


    return 0;
}
void BFS(vert**G,int n,int start,int koniec){
    queue < int > Q;

    for(int i=0;i<n;i++){
        G[i]->color=NOT_VISITED;
        G[i]->parent=NULL;
        G[i]->len_to_start=INF;
        G[i]->licznik=0;
    }
    G[start]->color=PROCESSED;
    G[start]->len_to_start=0;
    G[start]->licznik=1;
    Q.push(start);

    bool czykoniec=false;

    while(!Q.empty()){
        int u=Q.front(); Q.pop();
        neibour*q=G[u]->ne;
        while(q!=NULL and !czykoniec){
            if(q->idx==koniec)
                czykoniec=true;
            q=q->next;
        }
        q=G[u]->ne;
        while(q!=NULL){
            if(G[q->idx]->color==NOT_VISITED){
                G[q->idx]->color=PROCESSED;
                G[q->idx]->parent=G[u];
                G[q->idx]->len_to_start=G[u]->len_to_start+1;
                if(!czykoniec)
                    Q.push(q->idx);
            }
            G[q->idx]->licznik+=G[u]->licznik;
            q=q->next;
        }
        G[u]->color=VISITED;
    }
}
vert**Init(int n){
    int graph[n][n]={
       //A,B,C,D,E,F,G,H,I,J
        {0,1,1,0,0,0,0,0,0,0}, //A
        {1,0,0,1,0,0,0,1,0,0}, //B
        {1,0,0,1,1,0,0,0,0,0}, //C
        {0,1,1,0,0,1,0,0,0,0}, //D
        {0,0,1,0,0,1,0,0,0,0}, //E
        {0,0,0,1,1,0,0,0,1,1}, //F
        {0,0,0,0,0,0,0,1,1,1}, //G
        {0,1,0,0,0,0,1,0,1,0}, //H
        {0,0,0,0,0,1,1,1,0,0}, //I
        {0,0,0,0,0,1,1,0,0,0}, //J
    };
    vert**G=new vert*[n];
    for(int i=0;i<n;i++)
        G[i]=new vert;
    for(int i=0;i<n;i++){
        G[i]->name=(char)(i+'A');
        int j;
        G[i]->ne=NULL;
        for(j=n-1;j>=0;j--)
            if(graph[i][j]==1){
                neibour*q=new neibour;
                q->next=G[i]->ne;
                G[i]->ne=q;
                G[i]->ne->idx=j;
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
            cout << G[q->idx]->name << " ";
            q=q->next;
        }
        cout << endl;
    }
}
