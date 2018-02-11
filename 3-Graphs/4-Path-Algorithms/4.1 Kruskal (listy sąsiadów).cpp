#include <iostream>
#include <cstdlib>

using namespace std;
const int K=8;

struct Edge {
    int u,v; // u<v
    int weight;
    bool mst;
};
Edge* GenEdge();
void PrintEdge(Edge*E);
void Kruskal(Edge*E,int n);

struct SetNode{
    char name;
    SetNode*parent;
    int grade;
};
SetNode* FindSet(SetNode*x){
    if(x!=x->parent)
        x->parent=FindSet(x->parent);
    return x->parent;
}
void MakeSet(SetNode*x){
    x->parent=x;
    x->grade=0;
}
void Union(SetNode*x,SetNode*y){
    SetNode*s1=FindSet(x);
    SetNode*s2=FindSet(y);
    if(s1==s2)
        return;

    if(s1->grade < s2->grade)
        s1->parent=s2;
    else{
        s2->parent=s1;
        if(s1->grade==s2->grade)
            s1->grade++;
    }
}
void PrintSets(SetNode**data,int n){
    cout << endl << "Zbiory rozlaczne: " << endl;
    for(int i=0;i<n;i++)
        cout << data[i]->name << " w zb: " << FindSet(data[i])->name << endl;
}
void InitSets(SetNode**data,int n){
    for(int i=0;i<n;i++){
        data[i]=new SetNode;
        MakeSet(data[i]);
        data[i]->name=(char)(i+'A');
    }
}
void qsort(void* base, size_t num, size_t size,int (*compar)(const void*,const void*));
int compar(const void*a,const void*b){
    Edge*wsk_a=(Edge*)a;
    Edge*wsk_b=(Edge*)b;
    return (wsk_a->weight-wsk_b->weight);
}

int main(){
    int n=6;
    Edge*E=GenEdge();
    PrintEdge(E);
    qsort(E,K,sizeof(Edge),&compar);
    PrintEdge(E);

    Kruskal(E,n);
    cout << endl <<"Minimalne drzewo rozpinajace: " << endl;
    for(int i=0;i<K;i++)
        if(E[i].mst)
            cout << "Krawedz z " << (char)(E[i].u+'A') << " do " << (char)(E[i].v+'A') << " o wadze: " << E[i].weight << endl;
}
void Kruskal(Edge*E,int n){
    SetNode**V=new SetNode*;
    InitSets(V,n);
    for(int i=0;i<K;i++){
        E[i].mst=false;
        SetNode*u=V[E[i].u];
        SetNode*v=V[E[i].v];
        if(FindSet(u)!=FindSet(v)){
            Union(u,v);
            E[i].mst=true;
        }
    }
}
Edge* GenEdge(){
    Edge*E=new Edge[K];
    int tab[3][K]={
        {0,0,1,1,1,2,3,4},
        {1,4,2,4,5,3,4,5},
        {11,2,3,10,5,9,3,8}
    };
    for(int i=0;i<K;i++){
        E[i].u=tab[0][i];
        E[i].v=tab[1][i];
        E[i].weight=tab[2][i];
    }
    return E;
}
void PrintEdge(Edge*E){
    cout << "Krawedzie grafu:" << endl;
    for(int i=0;i<K;i++)
        cout << "Krawedz z " << (char)(E[i].u+'A') << " do " << (char)(E[i].v+'A') << " o wadze: " << E[i].weight << endl;
}

