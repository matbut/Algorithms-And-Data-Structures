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
    neibour*predsim;
};
void PrintGraph(vert*V,int n);
vert*Init(int n);

void DFS_Euler(vert*V,int n);
void DFS_vis_Euler(vert*V,int n,int i);

int main(){
    int n=6;
    vert*V=Init(n);
    PrintGraph(V,n);
    DFS_Euler(V,n);

    return 0;
}
void DFS_Euler(vert*V,int n){
    cout << endl << "Cykl Eulera:" << endl;
    DFS_vis_Euler(V,n,0);

}
void DFS_vis_Euler(vert*V,int n,int i){
    neibour*q=V[i].ne;
    cout <<"badam sasiadow wierzcholka " << V[i].name << endl;
    while(q!=NULL and q->next!=NULL){
        cout << " sasiad: " << q->next->v->name << endl;
        cout << " usuwam " << q->next->v->name <<  q->next->predsim->next->v->name << endl;

        neibour*p=q->next->predsim->next;

        q->next->predsim->next=q->next->predsim->next->next;

        delete p;


        cout << " usuwam " << V[i].name <<  q->next->v->name << endl;
        p=q->next;
        q->next=q->next->next;
        int x=q->next->v->idx;
        delete p;

            DFS_vis_Euler(V,n,x);
        q=q->next;
    }
    cout << V[i].name << "-";

}
vert*Init(int n){

    int graph[n][n]={
        {0,1,0,1,0,0}, //A
        {1,0,1,0,0,0}, //B
        {0,1,0,1,1,1}, //C
        {1,0,1,0,0,0}, //D
        {0,0,1,0,0,1}, //E
        {0,0,1,0,1,0}, //F
    };
    vert*V=new vert[n];
    for(int i=0;i<n;i++){
        V[i].idx=i;
        V[i].name=(char)(i+'A');
        int j;
        V[i].ne=NULL;
        for(j=n-1;j>=0;j--)
            if(graph[i][j]==1){
                neibour*q=new neibour;
                q->next=V[i].ne;
                V[i].ne=q;
                V[i].ne->v=&V[j];
            }
        // WARTOWNIK
        neibour*guard=new neibour;
        guard->next=V[i].ne;
        V[i].ne=guard;
    }
    // UZUPELNIANIE SIMPRED;
    for(int i=0;i<n;i++){
        neibour*q=V[i].ne;
        while(q->next!=NULL){
            cout << " sasiad " << q->next->v->idx << " to ";
            neibour*p=V[q->next->v->idx].ne;
            while(p->next->v->idx!=i ){
                p=p->next;
            }
            cout << p->next->v->idx << endl;
            q->next->predsim=p;
            p->next->predsim=q;

            q=q->next;
        }
    }
    return V;
}
void PrintGraph(vert*V,int n){
    cout << "Wierzcholki grafu:" << endl;
    for(int i=0;i<n;i++){
        cout << "Wierzcholek " << V[i].name << " ma sasiadow: ";
        neibour*q=V[i].ne->next;
        while(q!=NULL){
            cout << q->v->name << " ";
            q=q->next;
        }
        cout << endl;
    }
}
