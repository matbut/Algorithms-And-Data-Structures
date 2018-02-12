#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
const int N=20;
const int W=2;
const int R=100;

void GenTab(int t[]);
void PrintTab(int t[N]);
void Merge(int t[N],int p,int q,int k);
void MergeSort(int t[N],int p,int k);

int main(){
    int t[N];
    GenTab(t);
    PrintTab(t);
    MergeSort(t,0,N);
    PrintTab(t);
    return 0;
}
void MergeSort(int t[N],int p,int k){
    int q=(p+k)/2;
    if(p<q) MergeSort(t,p,q);
    if(q<k-1) MergeSort(t,q,k);
    Merge(t,p,q,k);

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


