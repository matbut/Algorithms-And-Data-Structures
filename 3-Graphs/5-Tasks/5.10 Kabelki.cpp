#include <iostream>
#include <cstdlib>
#include <ctime>
const int INF=100;
const int N=100;
using namespace std;

struct vertex{
    int*edge;
    int*weight;
    int edges;
};

class PriorityQueue{
    private:
    struct node{
        int pri;
        int val;
    };

    public:
    node*Tab;
    int Size;
    int MaxSize;

    PriorityQueue(){
        Tab=new node[N];
        Size=0;
        MaxSize=N;
    }
    bool IsEmpty(){
        return (Size==0);
    }
    int PopMax(){
        Size--;
        Swap(Tab[0],Tab[Size]);
        Heapify(0);
        return Tab[Size].val;
    }
    int PopMin(){
        Size--;
        return Tab[Size].val;
    }
    void Push(int val,int pri){
        Tab[Size].val=val;
        Tab[Size].pri=pri;
        Swap(Tab[0],Tab[Size]);
        Size++;
        Heapify(0);
    }
    private:
    void Heapify(int i){
        int l=Left(i);
        int r=Right(i);
        int Max=l;
        if(r<Size and Tab[l].pri<Tab[r].pri)
            Max=r;
        if(Max>=Size or Tab[Max].pri<Tab[i].pri)
            Max=i;
        if(l<Size and Max!=i){
            node tmp=Tab[i]; Tab[i]=Tab[Max]; Tab[Max]=tmp;
            Heapify(Max);
        }
    }
    int Parent(int i){
        return (i-1)/2;
    }
    int Left(int i){
        return 2*i+1;
    }
    int Right(int i){
        return 2*i+2;
    }
    void Swap(node &a,node &b){
        node tmp=a; a=b; b=tmp;
    }
};

vertex*Init(int n){
    int graph[n][n]={
    //   A B C D E F
        {0,1,4,0,0,0}, //A
        {1,0,2,6,0,0}, //B
        {4,2,0,1,5,0}, //C
        {0,6,1,0,3,9}, //D
        {0,0,5,3,0,0}, //E
        {0,0,0,9,0,0}, //F
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
        cout << "Kabelek " << char(i+'A') << " laczy: ";
        for(int j=0;j<V[i].edges;j++)
            std::cout << "  " << char(V[i].edge[j]+'A') << '[' << V[i].weight[j] << ']';
        cout << endl;
    }
}

int Dijkstra(vertex*V,int n,int start,int finish){
    bool visited[n];
    int dist[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
        dist[i]=INF;
    }
    PriorityQueue Q;
    dist[start]=0;
    Q.Push(start,dist[start]);

    bool End=false;
    while(!Q.IsEmpty() and !End){
        int u=Q.PopMin();
        if(visited[u])
            continue;
        visited[u]=true;
        if(u==finish)
            End=true;
        for(int i=0;i<V[u].edges and !End;i++){
            int t=V[u].edge[i];
            if(!visited[t])
                if(dist[t]>dist[u]+V[u].weight[i]){
                    dist[t]=dist[u]+V[u].weight[i];
                    Q.Push(t,dist[t]);
                }
        }
    }
    return dist[finish];
}
int Delete(vertex*V,int n,int a,int b){
    int i=0;
    while(i<V[a].edges and b!=V[a].edge[i])
        i++;
    if(i>=V[a].edges)
        return INF;
    V[a].weight[i]=INF;
    i=0;
    while(i<V[b].edges and a!=V[b].edge[i])
        i++;
    if(i>=V[b].edges)
        return INF;

    int x=V[b].weight[i];
    V[b].weight[i]=INF;
    return x;
}
bool Origami(vertex*V,int n,int a,int b){
    int x=Delete(V,n,a,b);
    cout << x << endl;
    PrintGraph(V,n);
    return x>Dijkstra(V,n,a,b);
}
int main(){
    int n=6;
    vertex*V=Init(n);
    PrintGraph(V,n);
    int a,b;
    cout << "Podaj sprawdzana krawedz: " << endl;
    cin >> a;
    cin >> b;
    if(Origami(V,n,a,b))
        cout << "Mozna powiesic origami!" << endl;
    else
        cout << "Nie mozna powiesic origami!" << endl;

}







