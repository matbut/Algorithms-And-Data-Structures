#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
const int N=10;
const int W=2;
const int R=100;

void GenTab(int t[]);
void PrintTab(int t[N]);
void Merge(int t[N],int p,int q,int k);
void MergeSort(int t[N]);
void Series(int t[N],int p,int &q,int &k);

int main(){
    int t[N];
    GenTab(t);
    PrintTab(t);
    MergeSort(t);
    PrintTab(t);
    return 0;
}
void MergeSort(int t[N]){
    while(true){
        int p=0;
        int q=p;
        int k=p;
        while(q<N){
            Series(t,p,q,k);
            if(p==0 and q==N) return;
            Merge(t,p,q,k);
            p=k;
        }
        PrintTab(t);

    }
}
void Merge(int t[N],int p,int q,int k){
    int i=p;
    int j=q;
    int l=0;
    int kt[k-p];
    while(i<q and j<k){
        if(t[i]<t[j]){
            kt[l]=t[i];
            i++;
        }else{
            kt[l]=t[j];
            j++;
        }
        l++;
    }
    while(i<q){
        kt[l]=t[i];
        i++;
        l++;
    }
    while(j<k){
        kt[l]=t[j];
        j++;
        l++;
    }
    for(l=0;l<k-p;l++){
        t[p+l]=kt[l];
    }
}
void Series(int t[N],int p,int &q,int &k){
    if(p+1<N) q=p+1;
        else q=N;
    while(q<N and t[q-1]<=t[q]) q++;

    if(q+1<N) k=q+1;
        else k=N;
    while(k<N and t[k-1]<=t[k]) k++;

}


void GenTab(int t[]){
    srand(time(0));
    int x=rand()%W;
    for(int i=0;i<N;i++){
        t[i]=x+rand()%R;
    }
}
void PrintTab(int t[N]){
    for(int i=0;i<N;i++){
        cout << t[i] << " ";
    }
    cout << endl;
}



