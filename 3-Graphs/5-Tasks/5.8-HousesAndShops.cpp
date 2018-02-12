#include <iostream>
#include <cstdlib>
#include <ctime>
const int INF=100;

using namespace std;

struct vertex{
    bool shop;
    int edge;
    int*distances;
    int*edges;
    int d_store;
};
struct PriorityQueue;

vertex*Init(int n);
void PrintGraph(vertex*V,int n);
void DistanceToClosestStore(vertex*V,int n);
int*Dijkstra(vertex*V,int n,int start);

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
    srand(time(0));
    int n=6;
    vertex*V=Init(n);
    //PrintGraph(V,n);
    DistanceToClosestStore(V,n);
    PrintGraph(V,n);
}
void DistanceToClosestStore(vertex*V,int n){
    for(int i=0;i<n;i++)
        if(V[i].shop)
            V[i].d_store=0;
        else
            V[i].d_store=INF;

    for(int i=0;i<n;i++){
        if(V[i].shop){
            int*distances=Dijkstra(V,n,i);
            for(int j=0;j<n;j++)
                if(!V[j].shop and V[j].d_store>distances[j])
                    V[j].d_store=distances[j];
        }
    }
}
int*Dijkstra(vertex*V,int n,int start){
    PriorityQueue Q=Q.Init();
    int*distances=new int[n];
    bool *processed=new bool[n];
    for(int i=0;i<n;i++){
        distances[i]=INF;
        processed[i]=false;
    }

    distances[start]=0;
    Q.Push(start,distances[start]);
    while(!Q.IsEmpty()){
        int w=Q.Pop();
        if(processed[w])
            continue;
        processed[w]=true;
        for(int i=0;i<V[w].edge;i++){
            int t=V[w].edges[i];
            if(distances[t]>distances[w]+V[w].distances[i]){
                distances[t]=distances[w]+V[w].distances[i];
                Q.Push(t,distances[t]);
            }
        }
    }
    return distances;
}
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
        V[i].edges=new int[n];
        V[i].distances=new int[n];
        V[i].shop=(rand()%2 and rand()%2);

        int licznik=0;
        for(int j=0;j<n;j++){
            if(graph[i][j]>0){
                V[i].edges[licznik]=j;
                V[i].distances[licznik]=graph[i][j];
                licznik++;
            }
        }
        V[i].edge=licznik;
    }
    return V;
}
void PrintGraph(vertex*V,int n){
    for(int i=0;i<n;i++){
        if(V[i].shop)
            cout << "Sklep ";
        else
            cout << "Dom   ";
        cout << char(i+'A') << " ma siasiadow: ";
        for(int j=0;j<V[i].edge;j++)
            cout << "  " << char(V[i].edges[j]+'A') << '[' << V[i].distances[j] << ']';
        cout << endl << " Odleglosc do najblizszego sklepu: " <<  V[i].d_store << endl;
        cout << endl;
    }
    cout << endl;
}





