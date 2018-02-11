#include<iostream>
#include<cstdlib>
#include<ctime>
const int N=10;
using namespace std;

struct node{
    int w;
    node *next;
};

struct podlancuch{
    node *pre_start;
    int dl;
    int ile;
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
        wstaw(prev,rand()%5+1);
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

podlancuch znajdz_podlancuch_rosnacy(node*first){
        podlancuch biez,maks;
        maks.dl=0;
        biez.dl=1;
        node*prev=first;
        node*q=first->next;
        while(q->next!=NULL){
            if(((prev->w)<(q->w)) and (prev!=first)){
                biez.dl++;
            }else{
                if(biez.dl>maks.dl){
                    maks=biez;
                }else if(biez.dl==maks.dl){
                    maks.ile++;
                }
                biez.pre_start=prev;
                biez.dl=1;
                biez.ile=1;
            }
            prev=q;
            q=q->next;
        }
        if(biez.dl>maks.dl){
            maks=biez;
        }else if(biez.dl==maks.dl){
            maks.ile++;
        }
        cout << "Najdluzszy podciag rosnacy zaczyna sie od " << maks.pre_start->next->w << " i ma dlugosc " << maks.dl << " i wystapil " << maks.ile << " razy" << endl;
        return maks;
}

void usun(node *&first,podlancuch maks){
    node*endd=maks.pre_start->next;
    for(int i=0;i<maks.dl;i++){
        node*q=endd;
        endd=endd->next;
        maks.pre_start->next=endd;
        delete q;
    }

}

void usun_podlancuch_rosnacy(node*&first){
    podlancuch maks=znajdz_podlancuch_rosnacy(first);
    if(maks.ile==1) usun(first,maks);
}



int main(){
    node*first;
    init(first);
    wczytaj(first);
    drukuj(first);
    usun_podlancuch_rosnacy(first);
    drukuj(first);

return 0;}
