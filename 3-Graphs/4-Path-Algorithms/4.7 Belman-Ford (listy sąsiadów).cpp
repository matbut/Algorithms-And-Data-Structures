#include <iostream>
#include <cstdlib>
#include <ctime>
const int INF=100;

using namespace std;

struct vertex{
    int*edge;
    int*weight;
    int edges;
};
struct PriorityQueue;

vertex*Init(int n);
void PrintGraph(vertex*V,int n);
int *Belman_Ford(vertex*V,int n,int start);

int main(){
    int n=6;
    vertex*V=Init(n);
    PrintGraph(V,n);
    int*parent=Belman_Ford(V,n,0);
    cout << "Najkrotsze sciezki: "<< endl;
    for(int i=0;i<n;i++)
        cout << "Droga do " << (char)(i+'A') << " ma dlugosc: " << parent[i] << endl;
        //cout << "Parent " << (char)(i+'A') << " to " << (char)(parent[i]+'A') << endl;

    return 0;
}

int *Belman_Ford(vertex*V,int n,int start){
    int*dist=new int[n];
    int*prt=new int[n];
    for(int i=0;i<n;i++){
        dist[i]=INF;
        prt[i]=-1;
    }
    dist[start]=0;
    bool is_end=true;
    for(int k=0;k<n-1 and is_end; k++){
        is_end=false;
        for(int i=0;i<n;i++)
            for(int j=0;j<V[i].edges;j++){
                int idx=V[i].edge[j];
                if(dist[i]!=INF and dist[idx]>dist[i]+V[i].weight[j]){
                    dist[idx]=dist[i]+V[i].weight[j];
                    prt[idx]=i;
                    is_end=true;
                }
            }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<V[i].edges;j++){
            int idx=V[i].edge[j];
            if(dist[i]!=INF and dist[idx]>dist[i]+V[i].weight[j])
                return NULL;
        }
    return dist;
}

vertex*Init(int n){
    int graph[n][n]={
    //   A B C D E F
        {0,2,1,0,0,0}, //A
        {1,0,2,6,0,0}, //B
        {0,0,0,1,5,0}, //C
        {0,0,0,0,3,9}, //D
        {0,0,0,0,0,0}, //E
        {0,0,0,0,0,0}, //F
    };
    vertex*V=new vertex[n];
    for(int i=0;i<n;i++){
        V[i].edge=new int[n];
        V[i].weight=new int[n];

        int licznik=0;
        for(int j=0;j<n;j++){
            if(graph[i][j]>0){
                V[i].edge[licznik]=j;
                V[i].weight[licznik]=graph[i][j];
                licznik++;
            }
        }
        V[i].edges=licznik;
    }
    return V;
}
void PrintGraph(vertex*V,int n){
    for(int i=0;i<n;i++){
        cout << "Wierzcholek " << char(i+'A') << " ma siasiadow: ";
        for(int j=0;j<V[i].edges;j++)
            std::cout << "  " << char(V[i].edge[j]+'A') << '[' << V[i].weight[j] << ']';
        cout << endl;
    }
}





