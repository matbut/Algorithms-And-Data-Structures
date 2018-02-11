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
        wstaw(prev,rand()%6+1);
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
bool czy_usuwac(int x){
    int tab[3];
    tab[1]=0;
    tab[2]=0;
    while(x>0){
        tab[x%3]++;
        x=x/3;
    }
    return tab[1]>tab[2];
}

void usuwaj(node*first){
    if(first->next!=NULL){
        node*prev=first;
        first=first->next;
        while(first!=NULL){
            if(czy_usuwac(first->w)){
                node*q=first;
                prev->next=first->next;
                first=first->next;
                delete q;
            }else{
                prev=first;
                first=first->next;
            }

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
