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
        wstaw(prev,rand()%4+2);
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
bool dwojki(int x){
    int jedynki=0;
    while(x>0){
        if(x%2==1) jedynki++;
        x=x/2;
    }
    return (jedynki+1)%2;
}

void usuwaj(node*&first){
    if(first->next!=NULL){
        if(first->next->next!=NULL){
            node*prev=first;
            node*spr=first->next; //1 el listy
            node*nxt=first->next->next; //2 el listy
            while(nxt!=NULL){
                if(dwojki(spr->w)){
                    prev->next=nxt;
                    delete spr;
                }else{
                    prev=spr;
                }
                spr=nxt;
                nxt=nxt->next;          }
        }
    }
}

int main(){
    node*first;
    init(first);
    wczytaj(first);
    drukuj(first);
    usuwaj(first);
    drukuj(first);

return 0;}
