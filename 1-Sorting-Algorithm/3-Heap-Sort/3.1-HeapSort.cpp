#include <iostream>
using namespace std;
const int N=10;

void PrintTab(int t[N]);

int Parent(int i){
    return (i-1)/2;
}
int Left(int i){
    return 2*i+1;
}
int Right(int i){
    return 2*i+2;
}
void Swap(int &a,int &b){
    int tmp=a; a=b; b=tmp;
}

void Heapify(int A[],int i,int n);
void BuildHeap(int A[],int n);
void HeapSort(int A[],int n);


int main(){
    int t[N]={7,2,17,13,23,19,3,1,5,11};
    PrintTab(t);
    HeapSort(t,N);
    PrintTab(t);

    return 0;
}
void Heapify(int A[],int i,int n){
    int l=Left(i);
    int r=Right(i);
    int Max=l;
    if(r<n and A[l]<A[r])
        Max=r;
    if(Max>=n or A[Max]<A[i])
        Max=i;
    if(l<n and Max!=i){
        Swap(A[i],A[Max]);
        Heapify(A,Max,n);
    }
}
void HeapSort(int A[],int n){
    BuildHeap(A,n);
    for(int i=n-1;i>=1;i--){
        Heapify(A,0,i+1);
        Swap(A[0],A[i]);
    }
}
void BuildHeap(int A[],int n){
    for(int i=n/2+1;i>=0;i--)
        Heapify(A,i,n);
}
void PrintTab(int t[N]){
    for(int i=0;i<N;i++){
        cout << t[i] << " ";
    }
    cout << endl;
}

