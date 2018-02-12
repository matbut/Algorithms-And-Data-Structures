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

void sortuj(node*tab[N],node*first){
    if(first!=NULL){
        first=first->next;

        node*biez[N];
        for(int i=0;i<N;i++){
            biez[i]=tab[i];
        }
        while (first!=NULL){
            int c=first->w%10;
            node*q=new node;
            wstaw(biez[c],first->w);
            first=first->next;
        }
        for(int i=0;i<N;i++){
            biez[i]->next=NULL;
        }
    }
}

int main(){
    node*first;
    init(first);
    wczytaj(first);
    drukuj(first);

    node*tab[N];
    for(int i=0;i<N;i++){
        tab[i]=new node; //wartownik
        tab[i]->next=NULL;
    }
    sortuj(tab,first);
    cout << endl;
    for(int i=0;i<N;i++){
        cout << "Liczby z cyfra jednosci " << i << " to: ";
        drukuj(tab[i]);
    }

return 0;}
