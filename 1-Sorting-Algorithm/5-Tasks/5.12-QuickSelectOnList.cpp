#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int N=10;

struct node{
    node*next;
    int val;
};
node* GenList(){
    srand(time(0));
    node*l=NULL;
    node*q;
    for(int i=N-1;i>=0;i--){
        q=new node;
        q->next=l;
        q->val=rand()%90+10;
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
node* QucikSelect(node*l,int k){
    if (l==NULL)
        return NULL;
    node*piwot=l;
    //cout << k << " Piwot: " << piwot->val << "; ";
    l=l->next;
    int less_num=0;
    node*great_list=NULL;
    node*less_list=NULL;

    while(l!=NULL){
        node*q=l;
        l=l->next;
        if(q->val<piwot->val){
            //cout << q->val << "l ";
            less_num++;
            q->next=less_list;
            less_list=q;
        }else{
            //cout << q->val << "g ";
            q->next=great_list;
            great_list=q;
        }
    }
    //cout << endl;
    if(less_num+1>k)
        return QucikSelect(less_list,k);
    if(less_num+1<k)
        return QucikSelect(great_list,k-less_num-1);
    return piwot;
}
int main(){
    srand(time(0));
    node*List=GenList();
    PrintList(List);
    int k;
    cout << "Ktorego eleementu szukasz: ";
    cin >> k;
    node*p=QucikSelect(List,k);
    if(p!=NULL)
        cout << k << " elementem z kolei jest: " << p->val << endl;
    else
        cout << "Brak";
    return 0;
}



