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
void ListReverse(node*&l);

int main(){
    node*l=GenList();
    PrintList(l);
    ListReverse(l);
    PrintList(l);
    return 0;
}
void ListReverse(node*&l){
    node*q=NULL;
    while(l!=NULL){
        node*p=l;
        l=l->next;
        p->next=q;
        q=p;
    }
    l=q;
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


