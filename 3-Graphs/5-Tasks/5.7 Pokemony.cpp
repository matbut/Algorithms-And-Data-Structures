#include <iostream>
using namespace std;

struct HuntigList {
    int predator;
    int pray;
    HuntigList *next;
};
struct Pred{
    int pred;
    Pred*next;
};
struct Poke{;
    int licznik;
    bool calm;
	Pred*pred;
};
class Queue{
    public:
    int len;
    int last;
    int first;
    int*tab;

    void Init(){
        len=100;
        first=-1;
        last=0;
        tab=new int[len];
    }
    bool IsEmpty(){
        return (last>first);
    }
    int Pop(){
        last++;
        return tab[(last-1)%len];
    }
    void Push(int val){
        first++;
        tab[first%len]=val;
    }
    void Delete(){
        delete[] tab;
    }
};
HuntigList* GenHuntigList(int n);
void PrintHuntigList(HuntigList*List,int n);
int*ReleaseThemAll(HuntigList*List,int n);

int main(){
    int n=10;
    HuntigList*List=GenHuntigList(n);
    PrintHuntigList(List,n);
    int*Order=ReleaseThemAll(List,n);
    cout << endl;
    if(Order==NULL)
        cout << "Pokemony Cie atakuja!";
    else{
        cout << "Kolejnosc pokemonow:" << endl;
        for(int i=0;i<n;i++)
            cout << (char)(Order[i]+'A') << "->";
    }
    return 0;
}
int*ReleaseThemAll(HuntigList*List,int n){
    Poke**pokemons=new Poke*[n];
    for(int i=0;i<n;i++){
        pokemons[i]= new Poke;
        pokemons[i]->pred=NULL;
        pokemons[i]->licznik=0;
        pokemons[i]->calm=true;
    }
    while(List!=NULL){
        Pred*q=new Pred;
        q->pred=List->predator;
        pokemons[List->predator]->calm=false;
        q->next=pokemons[List->pray]->pred;
        pokemons[List->pray]->pred=q;
        List=List->next;
    }
    int Released=0;
    int*Order=new int[n];

    Queue Q;
    Q.Init();

    for(int i=0;i<n;i++)
        if(pokemons[i]->calm) // czyli jest spokojny
            Q.Push(i);
    while(!Q.IsEmpty()){
        int p=Q.Pop();
        //cout << "Wyciam z koeljki " << (char)(p+'A') << endl;
        Order[Released]=p;
        Released++;
        Pred*q=pokemons[p]->pred;
        while(q!=NULL){
            pokemons[q->pred]->licznik++;
            if(!pokemons[q->pred]->calm and ((pokemons[q->pred]->licznik++)>=2)){
                pokemons[q->pred]->calm=true;
                Q.Push(q->pred);
            }
            q=q->next;
        }
    }
    Q.Delete();
    if (Released==n)
        return Order;
    return NULL;
}
HuntigList* GenHuntigList(int n){
    HuntigList*List=NULL;
    int tab[2][15]={
        {2,0,2,4,3,2,6,1,1,3,4,5,6,5,0},
        {0,1,1,1,2,4,5,5,6,6,6,8,8,9,7}
    };
    for(int i=14;i>=0;i--){
        HuntigList*q=new HuntigList;
        q->predator=tab[0][i];
        q->pray=tab[1][i];
        q->next=List;
        List=q;
    }
    return List;
}
void PrintHuntigList(HuntigList*List,int n){
    cout << "Lista pokemnonow:" << endl;
    for(int i=0;i<n;i++)
        cout << (char)(i+'A') << ", ";
    cout << endl;
    while(List!=NULL){
        cout << "Pokemon " << (char)(List->predator+'A') << " poluje na " << (char)(List->pray+'A') << endl;
        List=List->next;
    }
}

