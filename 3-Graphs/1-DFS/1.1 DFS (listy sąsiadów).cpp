#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <queue>
#include <stack>

using namespace std;

struct vert;
struct neibour;

struct vert{;
    int idx;
    char name;
	neibour*ne;
};
struct neibour{
    vert*v;
    neibour*next;
};
void PrintGraph(vert**V,int n);
vert**Init(int n);

void DFS(vert**V,int n);
void DFS_vis(vert**V,bool*visited,int n,int i);

int main(){
    int n=6;
    vert**V=Init(n);
    PrintGraph(V,n);
    DFS(V,n);

    return 0;
}
void DFS(vert**V,int n){
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            cout << "Zaczynam od: " << V[i]->name << endl;
            DFS_vis(V,visited,n,i);
        }
    }
}
void DFS_vis(vert**V,bool*visited,int n,int i){
    visited[i]=true;
    cout << "   " << "Odwiedzam: " << V[i]->name << endl;
    neibour*q=V[i]->ne;
    while(q!=NULL){
        if(!visited[q->v->idx]){
            DFS_vis(V,visited,n,q->v->idx);
        }
        q=q->next;
    }
    // SORTOWANIE TOPOLOGICZNE
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
    vert**V=new vert*[n];
    for(int i=0;i<n;i++)
        V[i]=new vert;
    for(int i=0;i<n;i++){
        V[i]->idx=i;
        V[i]->name=(char)(i+'A');
        int j;
        V[i]->ne=NULL;
        for(j=n-1;j>=0;j--)
            if(graph[i][j]==1){
                neibour*q=new neibour;
                q->next=V[i]->ne;
                V[i]->ne=q;
                V[i]->ne->v=V[j];
            }
    }
    return V;
}
void PrintGraph(vert**V,int n){
    cout << "Wierzcholki grafu:" << endl;
    for(int i=0;i<n;i++){
        cout << "Wierzcholek " << V[i]->name << " ma sasiadow: ";
        neibour*q=V[i]->ne;
        while(q!=NULL){
            cout << q->v->name << " ";
            q=q->next;
        }
        cout << endl;
    }
}
