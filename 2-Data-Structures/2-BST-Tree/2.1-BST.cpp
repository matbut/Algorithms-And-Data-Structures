#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int N=10;

struct BSTnode{
    BSTnode*left,*right,*parent;
    int key;
    string val;
};

void PrintBST(BSTnode*root);
void InsertBST(BSTnode*&root,BSTnode*q);

BSTnode*GenBST();
BSTnode*MinBST(BSTnode*root);
BSTnode*MaxBST(BSTnode*root);
BSTnode*FindBST(BSTnode*root,int key);
BSTnode*NextBST(BSTnode*q);
BSTnode*PrevBST(BSTnode*q);
void DeleteBST(BSTnode*&root,BSTnode*q);

int main(){
    srand(time(0));
    BSTnode*root=GenBST();
    PrintBST(root);

    cout << endl << endl;
    cout << "Najmniejszy: " << MinBST(root)->key << '.' << MinBST(root)->val << endl;
    cout << "Najwiekszy: " << MaxBST(root)->key << '.' << MaxBST(root)->val << endl;

    int key;
    cout << endl << "Czego szukasz:";
    cin >> key;


    BSTnode*q=FindBST(root,key);
    if (q!=NULL) cout << q->key << '.' << q->val << endl ;
    else cout << "Nie ma" << endl;

    if (NextBST(q)!=NULL) cout << "Jego nastepnik to: " << NextBST(q)->key << '.' << NextBST(q)->val << endl ;
    else cout << "Nie ma nastepnika" << endl;

    if (PrevBST(q)!=NULL) cout << "Jego poprzednik to: " << PrevBST(q)->key << '.' << PrevBST(q)->val << endl ;
    else cout << "Nie ma poprzednik" << endl;

    DeleteBST(root,q);
    PrintBST(root);

    return 0;
}

BSTnode*GenBST(){
    BSTnode*root=NULL;
    string t[N]={"ala","ola","ula","ela","ada","ewa","iga","ida","mia","nel"};
    int index[N]={8,4,12,1,6,15,3,7,13,2};
    for(int i=0;i<N;i++){

        BSTnode*q=new BSTnode;
        q->left=q->right=q->parent=NULL;
        q->key=index[i];
        q->val=t[i];
        InsertBST(root,q);
    }
    return root;
}
void InsertBST(BSTnode*&root,BSTnode*q){
    if (root==NULL) root=q;
    else{
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
}
void PrintBST(BSTnode*root){
    if(root==NULL) return;

    if(root->left!=NULL) PrintBST(root->left);
    cout << root->key << "." << root->val << "  ";
    if(root->right!=NULL) PrintBST(root->right);

}
BSTnode*FindBST(BSTnode*root,int key){
    while(root!=NULL and root->key!=key)
        if(key<root->key) root=root->left;
        else root=root->right;
    return root;
}
BSTnode*NextBST(BSTnode*q){
    if (q==NULL) return NULL;
    if(q->right!=NULL) return MinBST(q->right);
    int key=q->key;
    q=q->parent;
    while(q!=NULL and q->key<key)
        q=q->parent;
    return q;
}
BSTnode*PrevBST(BSTnode*q){
    if (q==NULL) return NULL;
    if(q->left!=NULL) return MaxBST(q->left);
    int key=q->key;
    q=q->parent;
    while(q!=NULL and q->key>key)
        q=q->parent;
    return q;
}
BSTnode*MinBST(BSTnode*root){
    if(root==NULL) return NULL;
    while(root->left!=NULL) root=root->left;
    return root;
}
BSTnode*MaxBST(BSTnode*root){

    if(root==NULL) return NULL;
    while(root->right!=NULL) root=root->right;
    return root;
}
void DeleteBST(BSTnode*&root,BSTnode*q){


    if(q->left==NULL or q->right==NULL){
        BSTnode*next;
        if(q->left==NULL)
            next=q->right;
        else
            next=q->left;

        if(q->parent==NULL){
                root=next;
        }else{
            if(q->key<q->parent->key)
                q->parent->left=next;
            else
                q->parent->right=next;
        }
    }else{
        if(q->parent==NULL){
            root=q->right;

        }else{
            if(q->key<q->parent->key)
                q->parent->left=q->right;
            else
                q->parent->right=q->right;
        }
        NextBST(q)->left=q->left;
    }
    delete q;
}



