#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;

struct vert;
struct neibour;

struct vert{;
    int idx;
    char name;
	int grade;
	neibour*ne;
};
struct neibour{
    vert*v;
    neibour*next;
};
void PrintGraph(vert*V,int n);
vert*Init(int n);
bool dwudzielnosc(vert*V,int n);
bool DFS_dwudzielnosc(vert*V,int n,int i,int* color,bool paint);

int main(){
    //srand(time(0));
    int n=6;
    vert*V=Init(n);
    PrintGraph(V,n);
    if(dwudzielnosc(V,n))
        cout << "Graf jest dwudzielny";
    else
        cout << "Graf nie jest dwudzielny";
    return 0;
}
bool dwudzielnosc(vert*V,int n){
    int* color=new int[n];
    for(int i=0;i<n;i++){
        color[i]=-1; // not visited;
    }
    bool paint=true;
    return DFS_dwudzielnosc(V,n,0,color,paint);
}
bool DFS_dwudzielnosc(vert*V,int n,int i,int* color,bool paint){
    if(color[i]==!paint){
        //cout << " konflikt kolorow " << V[i]->name << " kolor " << color[i] << " z " << (int)paint << endl;
        return false;
    }
    if(color[i]==-1){
        color[i]=paint;
        //cout << "   koloruje " << V[i]->name << " na kolor " << (int)paint << endl;
        neibour* q=V[i].ne;
        int licznik=0;
        bool czy=true;
        while(q!=NULL and czy){
            //cout << "   sprawdzam " << q->v->name << " na kolor " << endl;
            czy=DFS_dwudzielnosc(V,n,q->v->idx,color,!paint);
            q=q->next;
        }
        return czy;
    }
    return true;
}
vert*Init(int n){

    int graph[n][n]={
        {0,0,0,1,1,1}, //A
        {0,0,0,1,1,1}, //B
        {0,0,0,1,1,1}, //C
        {1,1,1,0,0,0}, //D
        {1,1,1,0,0,0}, //E
        {1,1,1,0,0,0}, //F
    };

    vert*V=new vert[n];
    for(int i=0;i<n;i++){
        V[i].idx=i;
        V[i].name=(char)(i+'A');
        //V[i]->grade=rand()%n;
        //int*index=index_init(n);
        int j;
        V[i].ne=NULL;
        for(j=0;j<n;j++)
            if(graph[i][j]==1){
                neibour*q=new neibour;
                q->next=V[i].ne;
                V[i].ne=q;
                V[i].ne->v=&V[j];
            }
        V[i].grade=j;
    }
    return V;
}
void PrintGraph(vert*V,int n){
    cout << "Wierzcholki grafu:" << endl;
    for(int i=0;i<n;i++){
        cout << "Wierzcholek " << V[i].name << " ma sasiadow: ";
        neibour*q=V[i].ne;
        while(q!=NULL){
            cout << q->v->name << " ";
            q=q->next;
        }
        cout << endl;
    }
}


