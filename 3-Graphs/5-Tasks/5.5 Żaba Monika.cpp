#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

struct Pair{
    double x,y;
};

using namespace std;
const int N=10;

Pair* GenRocks(int n){
    double Tab[2][N]={
        {1.0,1.5,1.8,1.5,2.6,1.8,1.1,2.3,2.6,3.0},
        {1.0,1.9,1.7,1.6,1.2,2.5,2.2,2.7,1.6,3.0}
    };
    Pair*Rocks=new Pair[n];
    for(int i=0;i<n;i++){
        Rocks[i].x=Tab[0][i];
        Rocks[i].y=Tab[1][i];
    }
    return Rocks;
}
void PrintRocks(Pair*Rocks,int n){
    for(int i=0;i<n;i++)
        cout << "Kamien o wspolrzednych " << Rocks[i].x << " " << Rocks[i].y << endl;
}
struct ne{
    int idx;
    ne*next;
};
struct Vertex{
    int idx;
    ne*ne;
};

double dist(Pair a,Pair b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void AddEdge(Vertex &a, Vertex &b){
    ne*q=new ne;
    q->idx=b.idx;
    q->next=a.ne;
    a.ne=q;

    q=new ne;
    q->idx=a.idx;
    q->next=b.ne;
    b.ne=q;
}
void PrintGraph(Vertex*V,int n){
    for(int i=0;i<n;i++){
        cout << "Kamien " << i << " ma siasiadow: ";
        ne*q=V[i].ne;
        while(q!=NULL){
            cout << q->idx << "  ";
            q=q->next;
        }
        cout << endl;
    }
}

int Jumps(Pair*Rocks,int n,double L){
    Vertex*Norm_Rocks=new Vertex[n];
    Vertex*Rest_Rocks=new Vertex[n];
    for(int i=0;i<n;i++){
        Norm_Rocks[i].ne=NULL;
        Norm_Rocks[i].idx=i;
        Rest_Rocks[i].ne=NULL;
        Rest_Rocks[i].idx=i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            if(i!=j){
                if(dist(Rocks[i],Rocks[j])<L)
                    AddEdge(Norm_Rocks[i],Norm_Rocks[j]);
                else if(dist(Rocks[i],Rocks[j])<(L/2.0))
                    AddEdge(Rest_Rocks[i],Norm_Rocks[j]);
                if(dist(Rocks[i],Rocks[j])<2*L)
                    AddEdge(Norm_Rocks[i],Rest_Rocks[j]);
            }
    }
    PrintGraph(Norm_Rocks,n);

    PrintGraph(Rest_Rocks,n);
}
int main(){
    int n=10;
    Pair*Rocks=GenRocks(n);
    PrintRocks(Rocks,n);
    Jumps(Rocks,n,1.0);
    return 0;
}


