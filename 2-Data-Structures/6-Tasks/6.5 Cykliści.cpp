#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
const int DUZA_LICZBA_PIERWSZA=701;

const int N=10;
using namespace std;

struct Cyclist{
    int id;
    int n_id;
};

struct SetNode{
    int cyclist_id;
    SetNode*parent;
    int rank;
    int group_size;
};

SetNode* FindSet(SetNode*x);
void MakeSet(SetNode*x);
void Union(SetNode*x,SetNode*y);

int Hash(int num,int len_htab);
void HashInsert(SetNode*w,SetNode*Hdata[],int len_htab);
SetNode*HashSearch(int num,SetNode*Hdata[],int len_htab);

int smallestGroup(Cyclist cyclist[],int n);

int main(){
    srand(time(0));
    int input_data[2][N]={
    {25,15,33,45,11,34,21,67,19,17},
    {67,33,-1,11,-1,19,45,17,25,-1},
    };
    Cyclist cyclist[N];
    for(int i=0;i<N;i++){
        cyclist[i].id=input_data[0][i];
        cyclist[i].n_id=input_data[1][i];
    }
    cout << "Najmniejsza grupka liczy: " << smallestGroup(cyclist,N) << " rowerzystow." << endl;


    return 0;
}
int smallestGroup(Cyclist cyclist[],int n){
    // WYPELNIANIE
    int htab_len=2*n;
    SetNode*Hdata[htab_len];
    for(int i=0;i<htab_len;i++)
        Hdata[i]=NULL;
    for(int i=0;i<n;i++){
        SetNode*q=new SetNode;
        q->cyclist_id=cyclist[i].id;
        MakeSet(q);
        HashInsert(q,Hdata,htab_len);
    }
    // LACZENIE W ZBIORY
    int *Rep=new int[n];
    int RepNum=0;
    for(int i=0;i<n;i++){
        if(cyclist[i].n_id!=-1){
            Union(HashSearch(cyclist[i].id,Hdata,htab_len),HashSearch(cyclist[i].n_id,Hdata,htab_len));
        }else{
            Rep[RepNum]=cyclist[i].id;
            RepNum++;
        }
    }
    // WYNIKI
    int Min_group_size=Rep[0];
    cout << "Rozmiary grup: " << endl;
    for(int i=0;i<RepNum;i++){
        int group_size=FindSet(HashSearch(Rep[i],Hdata,htab_len))->group_size;
        cout << group_size << endl;
        if(group_size<Min_group_size)
            Min_group_size=group_size;
    }
    return Min_group_size;
}

void HashInsert(SetNode*w,SetNode*Hdata[],int len_htab){
    int idx=Hash(w->cyclist_id,len_htab);
    while(Hdata[idx%len_htab]!=NULL)
        idx++;
    Hdata[idx%len_htab]=w;
}
SetNode*HashSearch(int num,SetNode*Hdata[],int len_htab){
    int idx=Hash(num,len_htab);
    while(Hdata[idx%len_htab]->cyclist_id!=num)
        idx++;
    return Hdata[idx%len_htab];
}
int Hash(int num,int len_htab){
    return (num%DUZA_LICZBA_PIERWSZA)%len_htab;
}
void MakeSet(SetNode*x){
    x->parent=x;
    x->rank=1;
    x->group_size=1;
}
SetNode* FindSet(SetNode*x){
    if(x!=x->parent)
        x->parent=FindSet(x->parent);
    return x->parent;
}
void Union(SetNode*x,SetNode*y){
    SetNode*s1=FindSet(x);
    SetNode*s2=FindSet(y);
    if(s1==s2)
        return;
    if(s1->rank < s2->rank){
        s2->group_size+=s1->group_size;
        s1->parent=s2;
    }else{
        s1->group_size+=s2->group_size;
        s2->parent=s1;
        if(s1->rank==s2->rank)
            s1->rank++;
    }
}
