#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct HT{
    int*Table;
    int Size;
};
int Hash(int x){
    int N=701;
    return x%N;
}

HT* Init();
void Insert(HT*ht,int x);
void Print(HT*ht);
void Enlarge(HT*&ht);

int main(){
    HT*ht=Init();
    Print(ht);
    Enlarge(ht);
    Print(ht);
    return 0;
}
void Enlarge(HT*&ht){
    HT*new_ht=new HT;
    new_ht->Size=2*ht->Size;
    new_ht->Table=new int[new_ht->Size];
    for(int i=0;i<new_ht->Size;i++)
        new_ht->Table[i]=-1;
    for(int i=0;i<ht->Size;i++)
        if(ht->Table[i]>=0){
            int idx=Hash(ht->Table[i]);
            if(ht->Table[idx%(new_ht->Size)]<0){
                new_ht->Table[idx%(new_ht->Size)]=ht->Table[i];
                ht->Table[i]=-1;
            }
        }
    for(int i=0;i<ht->Size;i++)
        if(ht->Table[i]>=0)
            Insert(new_ht,ht->Table[i]);
    ht=new_ht;
}
void Insert(HT*ht,int x){
    int idx=Hash(x);
    while(ht->Table[idx%ht->Size]>=0)
        idx++;
    ht->Table[idx%ht->Size]=x;
}
HT* Init(){
    HT *ht=new HT;
    ht->Size=21;
    ht->Table=new int[ht->Size];
    int Data[10]={3,67,21,19,19,51,67,47,94,19};

    for(int i=0;i<ht->Size;i++)
        ht->Table[i]=-1;
    for(int i=0;i<10;i++)
        Insert(ht,Data[i]);
        return ht;
}
void Print(HT*ht){
    for(int i=0;i<ht->Size;i++){
        cout.width(2);
        cout << i << ".";
        if(ht->Table[i]<0){
            cout << " *";
        }else{
            cout.width(3);
            cout << ht->Table[i] << "(" << Hash(ht->Table[i])%ht->Size << ")";
        }
        cout << endl;
    }
}
