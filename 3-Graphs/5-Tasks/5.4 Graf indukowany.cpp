#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

const int INF=100;

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
void PrintGraph(vert**G,int n);
vert**Init(int n);
bool*inducated_graph(vert**G,int n,int k);

int main(){
    int n=6;
    vert**G=Init(n);
    PrintGraph(G,n);

    int k;
    cout << "Podaj maskymalny stopien grafu indukowanego: ";
    cin >> k;
    bool*deleted=inducated_graph(G,n,k);
    cout << "Graf tworza wierzcholki: ";
    for(int i=0;i<n;i++)
        if(!deleted[i])
        cout << G[i]->name << " ";
    return 0;
}
bool*inducated_graph(vert**G,int n,int k){
    queue < int > Q;
    bool*deleted=new bool[n];
    int degree[n];

    for(int i=0;i<n;i++)
        deleted[i]=false;
    for(int i=0;i<n;i++){
        neibour*q=G[i]->ne;
        degree[i]=0;
        while(q!=NULL){
            degree[i]++;
            q=q->next;
        }
        if(degree[i]<k){
            Q.push(i);
        }
    }
    while(!Q.empty()){
        int w=Q.front(); Q.pop();
        neibour*q=G[w]->ne;
        while(q!=NULL){
            if(!deleted[q->v->idx]){
                degree[q->v->idx]--;
                if(degree[q->v->idx]<k)
                    Q.push(q->v->idx);
            }
            q=q->next;
        }
        deleted[w]=true;
    }
    return deleted;
}
vert**Init(int n){
    int graph[n][n]={
        {0,1,1,0,1,1}, //A
        {1,0,0,1,1,1}, //B
        {1,1,0,1,0,1}, //C
        {0,1,1,0,0,1}, //D
        {1,1,0,0,0,0}, //E
        {0,1,1,1,1,0}, //F
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
