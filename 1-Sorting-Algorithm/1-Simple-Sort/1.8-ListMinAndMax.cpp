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

struct supernode{
    node*Min,*Max;
};

node* GenList();
void PrintList(node*l);
supernode MinAndMaxList(node*&l);

int main(){
    node*l=GenList();
    PrintList(l);
    supernode p=MinAndMaxList(l);
    cout << "Najwiekszy to: " << p.Max->val << endl << "Najmniejszy to: " << p.Min->val << endl;
    PrintList(l);
    return 0;
}
supernode MinAndMaxList(node*&l){
    node*p=new node; // Wartownik
    p->next=l;
    l=p;

    supernode pre;
    pre.Min=p;
    pre.Max=p;
    while(p->next!=NULL and p->next->next!=NULL){ //and jest leniwy
        if((p->next->val)<(p->next->next->val)){
            if((p->next->val)<(pre.Min->next->val))
                pre.Min=p;
            if((p->next->next->val)>(pre.Max->next->val))
                pre.Max=p->next;
        }else{
            if((p->next->next->val)<(pre.Min->next->val))
                pre.Min=p->next;
            if((p->next->val)>(pre.Max->next->val))
                pre.Max=p;
        }
        p=p->next;
    }
    if((p!=NULL) and (p->next->val)<(pre.Min->next->val))
                pre.Min=p;
    if((p!=NULL) and (p->next->val)>(pre.Max->next->val))
                pre.Max=p;


    supernode r;
    r.Max=pre.Max->next;
    r.Min=pre.Min->next;
    pre.Min->next=pre.Min->next->next;
    if(pre.Max!=pre.Min) pre.Max->next=pre.Max->next->next;
    p=l;
    l=l->next;
    delete p;
    return r;
}

node* GenList(){
    srand(time(0));
    node*l=NULL;
    node*q;
    for(int i=N-1;i>=0;i--){
        q=new node;
        q->next=l;
        q->val=rand()%R+1;
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


