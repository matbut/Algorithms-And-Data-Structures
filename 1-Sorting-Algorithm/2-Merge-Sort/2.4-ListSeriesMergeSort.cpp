#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int N=10;
const int R=20;

struct node{
    node*next;
    int val;
};

node* GenList(){
    srand(time(0));
    node*l=NULL;
    node*q;
    for(int i=N-1;i>=0;i--){
        q=new node;
        q->next=l;
        q->val=rand()%R;
        l=q;
    }
    return l;
}
void PrintList(node*l){
    while(l!=NULL){
        cout << l->val << " ";
        l=l->next;
    }
    cout << endl;
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
void Series(node*l,node*&hd,node*&tl){
    hd=l;
    node*q=l;
    l=l->next;
    while(l!=NULL and l->val>=q->val){
        q->next=l;
        q=q->next;
        l=l->next;
    }
    tl=q;
}

void SwapNode(node*&l,node*&s){
    node*tmp=l; l=s; s=tmp;
}
node* Merge(node*hd1,node*hd2,node*tl1,node*tl2){
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
int main(){
    node*l=GenList();
    PrintList(l);
    node*hd,*tl;
    Series(l,hd,tl);
    PrintList(l);
    PrintList(hd);
    PrintList(tl);

    return 0;
}


