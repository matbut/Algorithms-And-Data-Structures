#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
const int INF=100;
const int N=100;
using namespace std;

struct Pair{
    int x,y;
};

class PriorityQueue{
    private:
    struct node{
        int pri;
        Pair val;
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
    Pair PopMax(){
        Size--;
        Swap(Tab[0],Tab[Size]);
        Heapify(0);
        return Tab[Size].val;
    }
    Pair PopMin(){
        Size--;
        return Tab[Size].val;
    }
    void Push(Pair val,int pri){
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
int**GenBoard(int n){
    int**Board;
    Board=(int**)calloc(n,sizeof(int*));
    for(int i=0;i<n;i++)
        Board[i]=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n*n;i++)
        Board[i/n][i%n]=rand()%8+1;


    return Board;
}
void PrintBoard(int**Board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << " " << Board[i][j] << " ";
        cout << endl;
    }
}

Pair*BestPath(int**Board,int n){
    int Ruchy[2][4]={
    {1,-1,0, 0},
    {0, 0,1,-1},
    };
    int**Cost=new int*[n];
    bool**Visited=new bool*[n];
    Pair**Parent=new Pair*[n];
    for(int i=0;i<n;i++){
        Cost[i]=new int[n];
        Visited[i]=new bool[n];
        Parent[i]=new Pair[n];
        for(int j=0;j<n;j++){
            Cost[i][j]=INF;
            Visited[i][j]=false;
            Parent[i][j].x=INF;
            Parent[i][j].y=INF;
        }
    }
    Pair start; start.x=0,start.y=0;
    PriorityQueue Q;
    Cost[0][0]=Board[0][0];
    Parent[0][0].x=-1; Parent[0][0].y=-1;
    Q.Push(start,Cost[0][0]);

    bool End=false;
    while(!Q.IsEmpty() and !End){
        Pair u=Q.PopMin();
        if(Visited[u.x][u.y])
            continue;
        Visited[u.x][u.y]=true;
        if(u.x==n-1 and u.y==n-1)
            End=true;
        for(int i=0;i<4 and !End;i++){
            Pair t; t.x=u.x+Ruchy[0][i]; t.y=u.y+Ruchy[1][i];
            if((t.x>=0 and t.x<n) and (t.y>=0 and t.y<n)){
                if(!Visited[t.x][t.y])
                    if(Cost[t.x][t.y]>Cost[u.x][u.y]+Board[t.x][t.y]){
                        Cost[t.x][t.y]=Cost[u.x][u.y]+Board[t.x][t.y];
                        Parent[t.x][t.y]=u;
                        Q.Push(t,Cost[t.x][t.y]);
                    }
            }
        }
    }
    Pair*result=new Pair[2*n-2];
    Pair i; i.x=n-1; i.y=n-1;

    while(Parent[i.x][i.y].x>=0 and Parent[i.x][i.y].y>=0){
        result[Parent[i.x][i.y].x+Parent[i.x][i.y].y]=i;
        i=Parent[i.x][i.y];

    }

    return result;
}

int main(){
    srand(time(0));
    int n=6;
    int**B=GenBoard(n);
    PrintBoard(B,n);
    Pair*Result=BestPath(B,n);
    cout << "Optymalna droga: " << endl;
    for(int i=0;i<2*n-2;i++)
        cout << "[" << Result[i].x << "," << Result[i].y << "]" << endl;
    return 0;
}
