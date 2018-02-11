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
        int x=rand()%90+10;

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

void sort_wstaw(node*wynik,node*q){
    node*prev=wynik;
    node*biez=wynik->next;
    while(biez!=NULL){
        if(biez->w<=q->w){
            prev=biez;
            biez=biez->next;
        }else break;
    }
    prev->next=q;
    q->next=biez;
}
void sortuj(node*&first){
    node*wynik;
    init(wynik);
    if(first!=NULL){
        first=first->next;
        while(first!=NULL){
            node*q=first;
            first=first->next;
            sort_wstaw(wynik,q);
        }
    }
    first=wynik;
}

node* suma(node*zb1,node*zb2){
    zb1=zb1->next;
    zb2=zb2->next;
    node*sum;
    init(sum);
    node*biez=sum;
    while(zb1!=NULL and zb2!=NULL){
        node*q;
        if(zb1->w<zb2->w){
            q=zb1;
            zb1=zb1->next;
        }else if(zb2->w<zb1->w){
            q=zb2;
            zb2=zb2->next;
        }else{
            q=zb2;
            zb2=zb2->next;
            zb1=zb1->next;
        }
        biez->next=q;
        biez=biez->next;
    }
    if(zb1!=NULL){
        biez->next=zb1;
    }else if(zb2!=NULL){
        biez->next=zb2;
    }else{
        biez->next=NULL;
    }
    return sum;
}
int main(){
    node*zb1,*zb2,*zb3;
    init(zb1);
    init(zb2);
    init(zb3);
    wczytaj(zb1);
    wczytaj(zb2);
    sortuj(zb1);
    sortuj(zb2);
    drukuj(zb1);
    drukuj(zb2);
    zb3=suma(zb1,zb2);
    drukuj(zb3);

    return 0;}
