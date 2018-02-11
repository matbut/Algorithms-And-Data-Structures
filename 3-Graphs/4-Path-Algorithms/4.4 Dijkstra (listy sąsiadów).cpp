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
vertex*Init(int n);
void PrintGraph(vertex*V,int n);
int *Dijkstra(vertex*V,int n,int start);

struct node{
    int pri;
    int val;
    node*next;
};

class PriorityQueue{
    public:
    node*first;

    PriorityQueue Init(){
        PriorityQueue Q;
        Q.first=NULL;
        return Q;
    }
    bool IsEmpty(){
        return this->first==NULL;
    }
    int Pop(){
        int val=this->first->val;
        node*q=this->first;
        this->first=this->first->next;
        delete q;
        return val;
    }
    void Push(int val,int pri){
        node*q=new node;
        q->val=val;
        q->pri=pri;

        if(this->first==NULL or (this->first->pri)>(pri)){  // OR jest leniwy
            q->next=this->first;
            this->first=q;
        }else{
            node*r=this->first;
            while((r->next!=NULL) and ((r->next->pri)>(q->pri))){   // AND jest leniwy
                r=r->next;
            }
            q->next=r->next;
            r->next=q;
        }
    }
};

int main(){
    int n=6;
    vertex*V=Init(n);
    PrintGraph(V,n);
    int*parent=Dijkstra(V,n,0);
    cout << "Najkrotsze sciezki: "<< endl;
    for(int i=0;i<n;i++)
        cout << "Dlugosc sciezki do " << (char)(i+'A') << " to " << parent[i] << endl;
    return 0;
}
int *Dijkstra(vertex*V,int n,int start){
    PriorityQueue Q=Q.Init();
    bool *processed=new bool[n];
    int *w=new int[n];
    int*parent=new int[n];
    for(int i=0;i<n;i++){
        processed[i]=false;
        w[i]=INF;
        parent[i]=0;
        //Q.Push(i,INF);
    }

    w[start]=0;
    Q.Push(start,0);
    while(!Q.IsEmpty()){
        int u=Q.Pop();
        cout << "Wyciagam z kolejki " << (char)(u+'A') << endl;
        if(processed[u])
            continue;
        processed[u]=true;
        cout << "Badam sasiadow " << (char)(u+'A') << ": ";
        for(int i=0;i<V[u].edges;i++){
            int t=V[u].edge[i];
            cout << " " << (char)(t+'A') << " ";
            if(!processed[t])
                if(w[t]>w[u]+V[u].weight[i]){
                    w[t]=w[u]+V[u].weight[i];
                    Q.Push(t,w[t]);
                    parent[t]=u;
                }
        }
        cout << endl;
    }
    return w;
}
vertex*Init(int n){
    int graph[n][n]={
    //   A B C D E F
        {0,1,4,0,0,0}, //A
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





