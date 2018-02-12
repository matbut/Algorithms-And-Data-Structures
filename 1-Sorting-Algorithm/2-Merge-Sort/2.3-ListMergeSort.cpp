#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int N=10;
const int R=20;

struct node{
    node*next;
    int val;
};

node* GenList();
void PrintList(node*l);
void ListMergeSort(node*&hd);
node* Merge(node*hd1,node*hd2,node*&tl);
node* Series(node*&hd);

void InsertList(node*&l,node*w);
void ListInsertSort(node*&l);

int main(){
    node*l=GenList();

    PrintList(l);

    ListMergeSort(l);

    PrintList(l);
    return 0;
}

node* GenList(){
    srand(time(0));
    node*l=NULL;
    node*q;
    for(int i=N-1;i>=0;i--){
        q=new node;
        q->next=l;
        q->val=rand()%R;
        l=q;
    }
    return l;
}
void PrintList(node*l){
    while(l!=NULL){
        cout << l->val << " ";
        l=l->next;
    }
    cout << endl;
}

void ListMergeSort(node*&hd){
    node*w=new node;
    w->next=hd;
    while(true){
        node*tl=w;
        node*hd;
        node*hd_s1;
        node*hd_s2;
        while(tl->next!=NULL){
            PrintList(tl->next);
            hd=tl->next;
            hd_s1=Series(hd);
            hd_s2=Series(hd);
            tl->next=Merge(hd_s1,hd_s2,hd);
            tl=hd;
            if(hd_s1==w->next and tl==NULL){
                hd=w->next;
                delete w;
                return;
            }
        }
    }
}

node* Series(node*&hd){
    if(hd==NULL) return NULL;
    node*l=hd;
    while(hd->next!=NULL and (hd->val)<=(hd->next->val)){
        hd=hd->next;
    }

    node*q=hd;
    hd=hd->next;
    q->next=NULL;
    return l;
}

node* Merge(node* hd1,node* hd2,node*&tl){

    if(hd1==NULL) return hd2;
    if(hd2==NULL) return hd1;

    node*hd;
    if((hd1->val)<(hd2->val)){
        hd=hd1;
        hd1=hd1->next;
    }else{
        hd=hd2;
        hd2=hd2->next;
    }
    node*p=hd;
    node*q;
    while(hd1!=NULL and hd2!=NULL){
        if((hd1->val)<(hd2->val)){
            q=hd1;
            hd1=hd1->next;
        }else{
            q=hd2;
            hd2=hd2->next;
        }
        p->next=q;
        p=q;
    }


    if(hd1!=NULL)
        p->next=hd1;
    else if(hd2!=NULL)
        p->next=hd2;
    while(p->next!=NULL)
        p=p->next;
    p->next=tl;
    tl=p;
    return hd;
}


void InsertList(node*&l,node*w){
    if(l==NULL or (l->val)>(w->val)){  // OR jest leniwy
        w->next=l;
        l=w;
    }else{
        node*q=l;
        while((q->next!=NULL) and ((q->next->val)<(w->val))){   // AND jest leniwy
            q=q->next;
        }
        w->next=q->next;
        q->next=w;
    }
}
void ListInsertSort(node*&l){
    node*q=NULL;
    while(l!=NULL){
        node*p=l;
        l=l->next;
        InsertList(q,p);
    }
    l=q;
}

