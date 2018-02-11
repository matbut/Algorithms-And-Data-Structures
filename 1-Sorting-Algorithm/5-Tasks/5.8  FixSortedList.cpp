#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int N=2;

struct node{
    int w;
    node*next;
};

void GenSortedList(node*&l);
void DestroySortedList(node*&l);
void PrintList(node*l);
void FixSortedList(node*&l);
void Insert(node*&l,node*r);

int main(){
    node*l;
    GenSortedList(l);
    PrintList(l);
    DestroySortedList(l);
    PrintList(l);
    FixSortedList(l);
    PrintList(l);
    return 0;
}

void DestroySortedList(node*&l){
    node*q=l;
    for(int i=rand()%N;i>0;i--){
    q=q->next;
    }
    q->w=0;
}

void GenSortedList(node*&l){
    srand(time(0));
    node*q,*p=NULL;
    for(int i=N-1;i>=0;i--){
        q=new node;
        q->w=N*i+rand()%N;
        q->next=p;
        p=q;
    }
    l=p;
}

void PrintList(node*l){
    while(l!=NULL){
        cout << l->w << ' ';
        l=l->next;
    }
    cout << endl;
}

void FixSortedList(node*&l){
    node*q=l;
    if((q->w)>(q->next->w)){
        l=l->next;
        Insert(l,q);
        return;
    }
    while((q->next->next!=NULL) and ((q->next->w)<(q->next->next->w))){
        q=q->next;
    }
    if((q->w)<(q->next->next->w)){
        node*r=q->next;
        q->next=q->next->next;
        Insert(l,r);
    }else{
        node*r=q->next->next;
        q->next->next=q->next->next->next;
        Insert(l,r);
    }

}
void Insert(node*&l,node*r){
    if((r->w)<(l->w)){
        r->next=l;
        l=r;
    }return;
    node*q=l;
    while((q->next!=NULL) and ((q->next->w)<(r->w))){
        q=q->next;
    }
    r->next=q->next;
    q->next=r;
}

