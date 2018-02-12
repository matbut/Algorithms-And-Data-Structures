#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct vert;
struct neibour;

struct vert{;
    char name;
	neibour*ne;
};
struct neibour{
    int v;
    neibour*next;
};
void PrintGraph(vert**V,int n);
vert**Init(int n);

int Max(int a,int b){
    if(a>=b)
        return a;
    else
        return b;
}
int DFS(vert**V,bool visited[],int n,int start){
    int Dim=0;
    visited[start]=true;
    neibour*q=V[start]->ne;
    while(q!=NULL){
        if(!visited[q->v])
            Dim=Max(Dim,DFS(V,visited,n,q->v));
        q=q->next;
    }
    return Dim+1;
}
int PathDFS(vert**V,int n,int start){
    bool visited[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    return DFS(V,visited,n,start)-1;
}
int GraphDiameter(vert**V,int n){
    int Dim=0;
    for(int i=0;i<n;i++)
        if(V[i]->ne!=NULL and V[i]->ne->next==NULL)
            Dim=Max(PathDFS(V,n,i),Dim);
    return Dim;
}

int main(){
    int n=6;
    vert**V=Init(n);
    PrintGraph(V,n);
    cout << "Srednica grafu to: " << GraphDiameter(V,n) << endl;
    return 0;
}
vert**Init(int n){
    int graph[n][n]={
        {0,1,1,1,1,1}, //A
        {1,0,0,0,0,0}, //B
        {1,0,0,0,0,0}, //C
        {1,0,0,0,0,0}, //D
        {1,0,0,0,0,0}, //E
        {1,0,0,0,0,0}, //F
    };
    vert**V=new vert*[n];
    for(int i=0;i<n;i++)
        V[i]=new vert;
    for(int i=0;i<n;i++){
        V[i]->name=(char)(i+'A');
        int j;
        V[i]->ne=NULL;
        for(j=n-1;j>=0;j--)
            if(graph[i][j]==1){
                neibour*q=new neibour;
                q->next=V[i]->ne;
                V[i]->ne=q;
                V[i]->ne->v=j;
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
            cout << V[q->v]->name << " ";
            q=q->next;
        }
        cout << endl;
    }
}
