#include<iostream>
#include<cstdlib>
#include<ctime>
const int N=10;
using namespace std;

struct node{
    int w;
    node *next;
};

void init(node* &first){
    first=new node; //wartownik
    first->next=NULL;
}
void wstaw(node*&prev,int w){
    node*q=new node;
    q->w=w;
    prev->next=q;
    prev=prev->next;
}
void wczytaj(node*prev){
    srand(time(0));
    int i;
    cout << "Ile elementow mam miec lista: ";
    cin >> i;
    for(i;i>0;i--){
        wstaw(prev,rand()%90+10);
    }
    prev->next=NULL;
}
void drukuj(node*first){
    if(first!=NULL){
        first=first->next;
        while(first!=NULL){
            cout << first->w << " ";
            first=first->next;
        }
        cout << endl;
    }
}

node* odwroc(node*first){
    node*nowa;
    init(nowa);
    if(first!=NULL){
        first=first->next;
        while(first!=NULL){
            node*q=first;
            first=first->next;
            q->next=nowa->next;
            nowa->next=q;
        }
    }
    return nowa;
}

int main(){
    node*first;
    init(first);
    wczytaj(first);
    drukuj(first);
    first=odwroc(first);
    drukuj(first);

return 0;}
