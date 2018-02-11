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

node* GenList();
void PrintList(node*l);
void InsertList(node*&l,node*w);

int main(){
    node*l=GenList();
    PrintList(l);
    node*w=new node;
    cout << "Podaj co wstawiasz: " << endl;
    cin >> w->val;
    InsertList(l,w);
    PrintList(l);
    return 0;
}
void InsertList(node*&l,node*w){
    if(l==NULL or l->val>w->val){  // OR jest leniwy
        w->next=l->next;
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


