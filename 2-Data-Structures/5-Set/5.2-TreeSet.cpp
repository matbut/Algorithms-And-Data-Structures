#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
const int N=10;
using namespace std;

struct SetNode{
    int val;
    SetNode*parent;
    int rank;
};

SetNode* FindSet(SetNode*x);
void MakeSet(SetNode*x);
void Union(SetNode*x,SetNode*y);
void PrintSets(SetNode*data[]);
void InitSets(SetNode*data[]);

int main(){
    srand(time(0));
    SetNode*data[N];
    InitSets(data);

    Union(data[0],data[1]);
    Union(data[2],data[1]);
    Union(data[2],data[3]);


    Union(data[5],data[7]);
    Union(data[6],data[8]);
    Union(data[8],data[7]);
    Union(data[9],data[5]);

    Union(data[2],data[5]);

    PrintSets(data);

    PrintSets(data);
    return 0;
}
void MakeSet(SetNode*x){
    x->parent=x;
    x->rank=0;
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
        s1->parent=s2;
    }else{
        s2->parent=s1;
        if(s1->rank==s2->rank)
            s1->rank++;
    }
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
