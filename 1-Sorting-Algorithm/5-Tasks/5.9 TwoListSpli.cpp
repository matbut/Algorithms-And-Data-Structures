#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int N=10;

struct node{
    int w;
    node*next;
};
struct TwoLists{
    node*even,*odd;
};

void GenList(node*&l);
void PrintList(node*l);
TwoLists Spli(node* l);

int main(){
    node*l;
    GenList(l);
    PrintList(l);
    TwoLists p;
    p=Spli(l);
    PrintList(p.even);
    PrintList(p.odd);
    return 0;
}

void GenList(node*&l){
    srand(time(0));
    node*q,*p=NULL;
    for(int i=N-1;i>=0;i--){
        q=new node;
        q->w=rand()%N;
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

TwoLists Spli(node* l){
    TwoLists p;

    p.even=NULL;
    p.odd=NULL;

    while(l!=NULL){
        node*q=l;
        l=l->next;
        if((q->w)%2==0){
            q->next=p.even;
            p.even=q;
        }else{
            q->next=p.odd;
            p.odd=q;
        }
    }
    return p;

}

