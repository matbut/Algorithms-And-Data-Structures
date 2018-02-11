#include <iostream>

using namespace std;
const int N=10;

struct stos{
    stos*next;
    int val;
};
struct kolejka{
    stos*s1,*s2;
};

bool IsEmpty_stos(stos*s);
void push(stos*&s,int n);
int pop(stos*&s);

bool IsEmpty_kolejka(kolejka k);
void put(kolejka &k,int n);
int get(kolejka &k);

int main(){
    kolejka k;
    k.s1=NULL; k.s2=NULL;

    if (IsEmpty_kolejka(k)) cout << "kolejka pusta" << endl;
    else cout << "kolejka pelna" << endl;
    put(k,5);
    if (IsEmpty_kolejka(k)) cout << "kolejka pusta" << endl;
    else cout << "kolejka pelna" << endl;
    cout << get(k) << endl;
    if (IsEmpty_kolejka(k)) cout << "kolejka pusta" << endl;
    else cout << "kolejka pelna" << endl;

    return 0;
}
bool IsEmpty_stos(stos*s){
    return s==NULL;
}
void push(stos*&s,int n){
    stos*q=new stos;
    q->next=s;
    q->val=n;
    s=q;
}
int pop(stos*&s){
    int n=s->val;
    stos*q=s;
    s=s->next;
    delete q;
    return n;
}

bool IsEmpty_kolejka(kolejka k){
    return IsEmpty_stos(k.s1) and IsEmpty_stos(k.s2);
}
void put(kolejka &k,int n){
    stos*q=new stos;
    push(k.s1,n);
}
int get(kolejka &k){
    if(IsEmpty_stos(k.s2))
        while(!IsEmpty_stos(k.s1)){
            push(k.s2,pop(k.s1));
        }
    return pop(k.s2);
}
