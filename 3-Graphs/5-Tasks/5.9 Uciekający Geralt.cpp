#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

const int L=5;
const int INF=100;

using namespace std;

struct corridor{
    int from;
    int len;
    int to;
    corridor*next;
};
struct room{
    int doors;
    int *door;
    int *length;
};
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

corridor* GenEdge();
void PrintDoor(corridor*d);
room*CorridorsIntoRooms(corridor*d,int n);
int*SaveGelart(corridor*d,int n,int start,int last);

int main(){
    srand(time(0));
    int n=5;
    corridor*d=GenEdge();
    PrintDoor(d);
    int*parent=SaveGelart(d,n,0,4);

    for(int i=4;i>=0;i--)
        cout << (char)(i+'A') << " ";

    return 0;
}
int*SaveGelart(corridor*d,int n,int start,int last){
    room*r=CorridorsIntoRooms(d,n);
    bool*visited=new bool[n];
    int*parent=new int[n];
    int*distance=new int[n];

    for(int i=0;i<n;i++){
        visited[i]=false;
        parent[i]=-1;
        distance[i]=INF;
    }
    PriorityQueue Q=Q.Init();


    parent[start]=-1;
    distance[start]=0;
    Q.Push(start,distance[start]);
    while(!Q.IsEmpty()){
        int w=Q.Pop();
        if(visited[w])
            continue;
        for(int i=0;i<r[w].doors;i++){
            int t=r[w].door[t];
            if(!visited[t]){
                if(distance[t]>distance[w]+r[w].length[t]){
                    distance[t]=distance[w]+r[w].length[t];
                    parent[t]=w;
                    Q.Push(t,distance[t]);
                }
            }
        }
        visited[start]=true;
    }
    return parent;
}
room*CorridorsIntoRooms(corridor*d,int n){

    room*r=new room[n];
    while(d!=NULL){
        r[d->from].doors++;
        d=d->next;
    }
    for(int i=0;i<n;i++){
        r[i].door=new int[r[i].doors];
        r[i].length=new int[r[i].doors];
        r[i].doors=0;
    }
    while(d!=NULL){
        r[d->from].door[r[d->from].doors]=d->to;
        r[d->from].length[r[d->from].doors]=d->len;
        r[d->from].doors++;
        d=d->next;
    }
    return r;
}
corridor* GenEdge(){
    corridor*d=NULL;
    int tab[2][8]={
        {0,0,1,1,1,2,3,4},
        {1,4,2,4,5,3,4,5},
    };
    for(int i=7;i>=0;i--){
        corridor*q=new corridor;
        q->from=tab[0][i];
        q->to=tab[1][i];
        q->len=rand()%L;
        q->next=d;
        d=q;
    }
    return d;
}
void PrintDoor(corridor*d){
    cout << "Korytarze miedzy komnatami:" << endl;
    while(d!=NULL){
        cout << "Z komnaty " << (char)(d->from+'A') << " do " << (char)(d->to+'A') << endl;
        d=d->next;
    }
}
