#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int N=5;
const int M=5;
const int R=27;

struct node{
    node*next;
    int val;
};

node* GenList(int n);
void PrintList(node*l);
void InsertList(node*&l,node*w);
void ListInsertSort(node*&l);
node* MergeTwoList(node*l,node*s);

int main(){
    srand(time(0));

    node*l=GenList(N);
    ListInsertSort(l);
    PrintList(l);

    node*s=GenList(M);
    ListInsertSort(s);
    PrintList(s);

    node*ll=MergeTwoList(l,s);
    PrintList(ll);

    return 0;
}
void SwapNode(node*&l,node*&s){
    node*tmp=l; l=s; s=tmp;
}
node* MergeTwoList(node*l,node*s){
    node*tmp;
    if(l==NULL)
        return s;
    if(s==NULL)
        return l;
    if(s->val<l->val)
        SwapNode(l,s);
    node*first=l;

    while(l!=NULL and s!=NULL){
        while(l->next!=NULL and l->next->val <= s->val)
            l=l->next;
        tmp=l->next;
        l->next=s;
        l=tmp;
        if(l==NULL)
            continue;
        while(s->next!=NULL and s->next->val <= l->val)
            s=s->next;
        tmp=s->next;
        s->next=l;
        s=tmp;
    }
    return first;
}

void InsertList(node*&l,node*w){
    if(l==NULL or (l->val)>(w->val)){  // OR jest leniwy
        w->next=l;
        l=w;
    }else{
        node*q=l;
        while((q->next!=NULL) and ((q->next->val)<(w->val))){   // AND jest leniwy
            q=q->next;
        }
        w->next=q->next;
        q->next=w;
    }
}
void ListInsertSort(node*&l){
    node*q=NULL;
    while(l!=NULL){
        node*p=l;
        l=l->next;
        InsertList(q,p);
    }
    l=q;
}
node* GenList(int n){
    node*l=NULL;
    node*q;
    for(int i=n-1;i>=0;i--){
        q=new node;
        q->next=l;
        q->val=rand()%R+1;
        l=q;
    }
    return l;
}
void PrintList(node*l){
    cout << "Lista:" << endl;
    while(l!=NULL){
        cout.width(2);
        cout << l->val << " ";
        l=l->next;
    }
    cout << endl;
}


