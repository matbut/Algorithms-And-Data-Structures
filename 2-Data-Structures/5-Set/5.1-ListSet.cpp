#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
const int N=10;

using namespace std;

struct SetNode{
    int val;
    SetNode*next;
    SetNode*parent;
    int length;
};
void SwapSets(SetNode*&s1,SetNode*&s2){
    SetNode*tmp=s1; s1=s2; s2=tmp;
}
SetNode* FindSet(SetNode*x);
void MakeSet(SetNode*x);
void Union(SetNode*x,SetNode*y);
void PrintSets(SetNode*data[]);
void InitSets(SetNode*data[]);

int main(){
    srand(time(0));
    SetNode*data[N];
    InitSets(data);

    PrintSets(data);

    Union(data[0],data[1]);
    Union(data[2],data[1]);
    Union(data[2],data[3]);

    Union(data[5],data[7]);
    Union(data[6],data[8]);
    Union(data[8],data[7]);
    Union(data[9],data[5]);

    Union(data[2],data[5]);

    PrintSets(data);
    return 0;
}
void MakeSet(SetNode*x){
    x->length=1;
    x->parent=x;
    x->next=NULL;
}
SetNode* FindSet(SetNode*x){
    return x->parent;
}
void Union(SetNode*x,SetNode*y){
    cout << "Union: " << x->val << ' ' << y->val << endl;
    SetNode*s1,*s2;
    s1=FindSet(x);
    s2=FindSet(y);
    if(s1->length>s2->length)
        SwapSets(s1,s2);

    s2->length+=s1->length;
    SetNode*q=s1;
    q->parent=s2;
    while(q->next!=NULL){

        q->next->parent=s2;
        q=q->next;
    }
    q->next=s2->next;
    s2->next=s1;
}
void InitSets(SetNode*data[]){
    data[0]=new SetNode;
    data[0]->val=5;
    MakeSet(data[0]);
    for(int i=1;i<N;i++){
        data[i]=new SetNode;
        data[i]->val=data[i-1]->val+rand()%N+1;
        MakeSet(data[i]);
    }
}
void PrintSets(SetNode*data[]){
    cout << endl << "Zbiory rozlaczne: " << endl;
    for(int i=0;i<N;i++){
        cout << data[i]->val << " w zb: " << FindSet(data[i])->val << endl;
    }
}

