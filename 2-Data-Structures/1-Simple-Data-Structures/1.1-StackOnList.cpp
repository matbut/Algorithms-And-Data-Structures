#include <iostream>

using namespace std;
const int N=10;

struct stos{
    stos*next;
    int val;
};

bool IsEmpty(stos*s);
void push(stos*&s,int n);
int pop(stos*&s);

int main(){
    stos*s=NULL;
    if (IsEmpty(s)) cout << "stos pusty" << endl;
    else cout << "stos pelny" << endl;
    push(s,5);
    if (IsEmpty(s)) cout << "stos pusty" << endl;
    else cout << "stos pelny" << endl;
    cout << pop(s) << endl;
    if (IsEmpty(s)) cout << "stos pusty" << endl;
    else cout << "stos pelny" << endl;

    return 0;
}
bool IsEmpty(stos*s){
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
