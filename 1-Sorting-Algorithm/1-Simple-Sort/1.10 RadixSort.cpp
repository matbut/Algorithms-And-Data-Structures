#include <iostream>
#include <cmath>
using namespace std;
const int N=7;
const int K=3;
const int ASCII=97;
const int ILE_LITER=26;

struct node{
    node *next;
    string s;
};


void PrintList(node*l);
void RadixSort(node*&l);
void QuickSort(node*&l,int p);

int main(){
    string napisy[N]={"kot","tak","rak","kac","tor","tir","kit"};
    node*l=NULL;
    node*q;
    for(int i=N-1;i>=0;i--){
        q=new node;
        q->s=napisy[i];
        q->next=l;
        l=q;
    }

    RadixSort(l);
    PrintList(l);
}

void PrintList(node*l){
    while(l!=NULL){
        cout << l->s << ' ';
        l=l->next;
    }
    cout << endl;
}

void RadixSort(node*&l){
    for(int i=K-1;i>=0;i--){
        PrintList(l);
        QuickSort(l,i);
    }
}

node*koniec(node*q){
    if(q==NULL) return NULL;
    while(q->next!=NULL)
        q=q->next;
    return q;
}

void QuickSort(node*&l,int p){
    if(l==NULL) return;
    node*l1=NULL,*l2=NULL,*l3=NULL;
    int x=l->s[p];
    while(l!=NULL){
        node*q=l;
        l=l->next;
        if(q->s[p]<x){
            q->next=l1;
            l1=q;
        }
        else if(q->s[p]==x){
            q->next=l2;
            l2=q;
        }else{
            q->next=l3;
            l3=q;
        }
    }
    QuickSort(l1,p);
    QuickSort(l3,p);

    l=l2;
    if(koniec(l1)!=NULL) {
        koniec(l1)->next=l2;
        l=l1;
    }
    koniec(l2)->next=l3;
}

