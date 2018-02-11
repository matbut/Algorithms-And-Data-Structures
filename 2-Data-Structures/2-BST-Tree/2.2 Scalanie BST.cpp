#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int N=10;
const int M=5;

struct BSTnode{
    BSTnode*left,*right,*parent;
    int key;
};
void PrintBST(BSTnode*root){
    if(root==NULL) return;

    if(root->left!=NULL)
        PrintBST(root->left);
    cout << root->key << "." << "  ";
    if(root->right!=NULL)
        PrintBST(root->right);

}
void InsertBST(BSTnode*&root,BSTnode*q){
    q->left=q->right=q->parent=NULL;
    if(root==NULL){
        root=q;
        return;
    }
    BSTnode*r=root;
    BSTnode*p;
    while(r!=NULL){
        p=r;
        if(q->key<r->key)
            r=r->left;
        else
            r=r->right;
    }
    if(q->key<p->key)
        p->left=q;
    else
        p->right=q;
    q->parent=p;
}
BSTnode*GenBST(int index[],int n){
    BSTnode*root=NULL;
    for(int i=0;i<n;i++){
        BSTnode*q=new BSTnode;
        q->key=index[i];
        InsertBST(root,q);
    }
    return root;
}

BSTnode*Min(BSTnode*root){
    if(root==NULL)
        return NULL;
    while(root->left!=NULL)
        root=root->left;
    return root;
}
BSTnode*Succ(BSTnode*x){
    if(x==NULL)
        return NULL;
    if(x->right!=NULL)
        return Min(x->right);
    while(x->parent!=NULL and x->parent->left!=x)
        x=x->parent;
    return x->parent;
}
void GenBSTfromTab(BSTnode*&root,int tab[],int n,int s,int e){
    if(s>e)
        return;

    BSTnode*q=new BSTnode;
    q->key=tab[(s+e)/2];
    InsertBST(root,q);
    GenBSTfromTab(root,tab,n,s,(s+e)/2-1);
    GenBSTfromTab(root,tab,n,(s+e)/2+1,e);
}
BSTnode*MergeTheSame(BSTnode*a,BSTnode*b){
    a=Min(a);
    b=Min(b);
    int tab[N];
    int licznik=0;
    while(a!=NULL and b!=NULL){
        while(a!=NULL and a->key<b->key)
            a=Succ(a);
        while(a!=NULL and b!=NULL and b->key<a->key)
            b=Succ(b);
        if(a!=NULL and b!=NULL and a->key==b->key){
            tab[licznik]=a->key;
            licznik++;
            a=Succ(a);
            b=Succ(b);
        }
    }
    BSTnode*root=NULL;
    GenBSTfromTab(root,tab,licznik,0,licznik-1);
    return root;
}
BSTnode*MergeTheDifferent(BSTnode*a,BSTnode*b){
    a=Min(a);
    b=Min(b);
    int tab[N];
    int licznik=0;
    while(a!=NULL and b!=NULL){
        while(a!=NULL and a->key<b->key){
            tab[licznik]=a->key;
            licznik++;
            a=Succ(a);
        }
        while(a!=NULL and b!=NULL and b->key<a->key){
            tab[licznik]=b->key;
            licznik++;
            b=Succ(b);
        }
        if(a!=NULL and b!=NULL and a->key==b->key){
            a=Succ(a);
            b=Succ(b);
        }
    }
    while(a!=NULL){
        tab[licznik]=a->key;
        licznik++;
        a=Succ(a);
    }
    while(b!=NULL){
        tab[licznik]=b->key;
        licznik++;
        b=Succ(b);
    }
    BSTnode*root=NULL;
    GenBSTfromTab(root,tab,licznik,0,licznik-1);
    return root;
}
int main(){
    srand(time(0));
    int i1[N]={8,4,12,1,6,15,3,7,13,2 };
    int i2[M]={4,9,3,8,5};

    BSTnode*root_1=GenBST(i1,N);
    BSTnode*root_2=GenBST(i2,M);
    cout << endl << "Drzewo 1:" << endl;
    PrintBST(root_1);
    cout << endl << "Drzewo 2:" << endl;
    PrintBST(root_2);

    BSTnode*same=MergeTheSame(root_1,root_2);
    cout << endl << "Drzewo 3:" << endl;
    PrintBST(same);
    BSTnode*diff=MergeTheDifferent(root_1,root_2);
    cout << endl << "Drzewo 3:" << endl;
    PrintBST(diff);
    return 0;
}
