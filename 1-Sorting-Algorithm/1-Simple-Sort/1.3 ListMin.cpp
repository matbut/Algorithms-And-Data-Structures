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
node* MinList(node*&l);

int main(){
    node*l=GenList();
    PrintList(l);
    cout << MinList(l)->val << endl;
    PrintList(l);
    return 0;
}
node* MinList(node*&l){
    if(l==NULL) return l;
    node*pre_min=l;
    node*min_el=l;
    node*q=l;
    while(q->next!=NULL){
        if((q->next->val)<(min_el->val)){
            pre_min=q;
            min_el=q->next;
        }
        q=q->next;
    }
    if(min_el==l){
        l=l->next;
    }else{
        pre_min->next=min_el->next;
    }
    min_el->next=NULL;
    return min_el;
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


