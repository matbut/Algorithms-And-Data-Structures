#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <queue>
#include <stack>

using namespace std;

struct Edge {
    int u,v; // u<v
    Edge *next;
};

Edge* GenEdge();
void PrintEdge(Edge*E);
bool Euleran(Edge*E,int n);

int main(){
    int n=6;
    Edge*E=GenEdge();
    PrintEdge(E);

    if(Euleran(E,n))
        cout << "Graf ma cykl Eulera" << endl;
    else
        cout << "Graf nie ma cyklu Eulera" << endl;

    return 0;
}
bool Euleran(Edge*E,int n){
    int* stopien=new int[n];
    for(int i=0;i<n;i++)
        stopien[i]=0;
    while(E!=NULL){
         stopien[E->u]++;
         stopien[E->v]++;
         E=E->next;
    }
    for(int i=0;i<n;i++)
        if(stopien[i]%2!=0)
            return false;
    return true;
}

Edge* GenEdge(){
    Edge*E=NULL;
    int tab[2][8]={
        {0,0,1,1,1,2,3,4},
        {1,4,2,4,5,3,4,5},
    };
    for(int i=7;i>=0;i--){
        Edge*q=new Edge;
        q->u=tab[0][i];
        q->v=tab[1][i];
        q->next=E;
        E=q;
    }
    return E;
}
void PrintEdge(Edge*E){
    cout << "Krawedzie grafu:" << endl;
    while(E!=NULL){
        cout << "Krawedz z " << (char)(E->u+'A') << " do " << (char)(E->v+'A') << endl;
        E=E->next;
    }
}

