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

void sortuj(node*tab[N],node*last[N],node*first){
    if(first!=NULL){
        first=first->next;


        while (first!=NULL){
            int c=first->w%10;
            wstaw(last[c],first->w);
            first=first->next;
        }
        for(int i=0;i<N;i++){
            last[i]->next=NULL;
            drukuj(tab[i]);
        }
    }
}
node* gen_sortuj(node*first){
    node*tab[N];
    node*last[N];
    for(int i=0;i<N;i++){
        tab[i]=new node; //wartownik
        tab[i]->next=NULL;
        last[i]=tab[i];
    }
    sortuj(tab,last,first);

    node*wynik=NULL;
    for(int i=N-1;i>=0;i--){
        if(i!=0){
            node*q=tab[i];
            tab[i]=tab[i]->next;
            delete q; // usuwanie wartownikow bez pierwszego
        }

        if(tab[i]!=NULL){
            last[i]->next=wynik;
            wynik=tab[i];
        }
    }
    return wynik;
    /* TO^ ALBO TO:
    for(int i=N-1;i>0;i--){
        node*q=tab[i];
        tab[i]=tab[i]->next;
        delete q; // usuwanie wartownikow

        if(last[i-1]!=NULL){
            last[i-1]->next=tab[i];
        }else{
            last[i-1]=tab[i];
        }
    }
    return tab[0];
*/
}



int main(){
    node*first;
    init(first);
    wczytaj(first);
    drukuj(first);
    drukuj(gen_sortuj(first));


return 0;}
