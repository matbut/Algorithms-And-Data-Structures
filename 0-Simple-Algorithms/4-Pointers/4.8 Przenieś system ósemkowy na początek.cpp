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
        wstaw(prev,rand()%30);
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

bool osemki(int x){
    int piatki=0;
    while(x>0){
        if(x%10==5) piatki++;
        x=x/10;
    }
    return piatki%2;
}

void przenies(node*&first){
    if(first->next!=NULL){
        node*prev=first;
        node*spr=first->next;
        while(spr!=NULL){
            if(osemki(spr->w)){
                node*q=spr;
                spr=spr->next;
                prev->next=spr->next;
                q->next=first->next;
                first->next=q;
            }else{
                prev=spr;
                spr=spr->next;
            }


        }
    }
}

int main(){
    node*first;
    init(first);
    wczytaj(first);
    drukuj(first);
    przenies(first);
    drukuj(first);

return 0;}
