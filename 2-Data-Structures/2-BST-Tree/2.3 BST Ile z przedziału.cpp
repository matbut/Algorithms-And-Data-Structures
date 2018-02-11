#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int N=10;

struct BSTnode{
    BSTnode*left,*right;
    int key;
    string val;
};
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
    }
}
BSTnode*GenBST(){
    BSTnode*root=NULL;
    string t[N]={"ala","ola","ula","ela","ada","ewa","iga","ida","mia","nel"};
    int index[N]={8,4,12,1,6,15,3,7,13,2};
    for(int i=0;i<N;i++){

        BSTnode*q=new BSTnode;
        q->left=q->right=NULL;
        q->key=index[i];
        q->val=t[i];
        InsertBST(root,q);
    }
    return root;
}
int IntervalBST(BSTnode*root,int a,int b){
    if(root==NULL)
        return 0;
    int sum=0;
    if(a<root->key)
        sum+=IntervalBST(root->left,a,b);
    if(a<=root->key and root->key<=b){
        cout << root->key << "." << root->val << "  ";
        sum++;
    }
    if(root->key<b)
        sum+=IntervalBST(root->right,a,b);
    return sum;
}
void PrintBST(BSTnode*root){
    if(root==NULL) return;

    if(root->left!=NULL) PrintBST(root->left);
    cout << root->key << "." << root->val << "  ";
    if(root->right!=NULL) PrintBST(root->right);

}
int main(){
    srand(time(0));
    BSTnode*root=GenBST();
    PrintBST(root);
    int a;
    int b;
    cout << endl << "Podaj poczatek przedzialu: ";
    cin >> a;
    cout << "Podaj koniec przedzialu: ";
    cin >> b;
    cout << endl << "Przedzial zawiera " << IntervalBST(root,a,b) << " elementow" << endl;
    return 0;
}






