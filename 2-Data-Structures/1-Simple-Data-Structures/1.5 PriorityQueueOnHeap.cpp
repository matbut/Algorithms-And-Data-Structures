#include <iostream>
using namespace std;
const int N=10;

void PrintTab(int t[N]);

int Parent(int i){
    return (i-1)/2;
}
int Left(int i){
    return 2*i+1;
}
int Right(int i){
    return 2*i+2;
}
void Swap(int &a,int &b){
    int tmp=a; a=b; b=tmp;
}

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
    void Swap(node &a,node &b){
        node tmp=a; a=b; b=tmp;
    }
};

int main(){
    PriorityQueue Q;
    int x;

    if(Q.IsEmpty()) cout << "Kolejka jest pusta. " << endl; else cout << "Kolejka jest pelna. " << endl;
    Q.Push(1,10);
    Q.Push(2,20);
    if(Q.IsEmpty()) cout << "Kolejka jest pusta. " << endl; else cout << "Kolejka jest pelna. " << endl;
    x=Q.PopMax();
    cout << x << endl;
    x=Q.PopMin();
    cout << x << endl;
    if(Q.IsEmpty()) cout << "Kolejka jest pusta. " << endl; else cout << "Kolejka jest pelna. " << endl;

    return 0;
}

