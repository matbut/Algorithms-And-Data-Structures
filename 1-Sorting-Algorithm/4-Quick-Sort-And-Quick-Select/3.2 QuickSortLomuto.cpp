#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
const int N=10;

void GenTab(int A[N],int N);
void PrintTab(int A[N],int N);

void QuickSort_Lomuto(int A[],int l,int r);
int QuickSelect_Lomuto(int A[],int n,int k);
int Partition(int A[],int l,int r);


void Swap(int &x,int &y){
    int tmp=x; x=y; y=tmp;
}

int main(){
    srand(time(0));
    int A[N];
    int x;


    //cout << "Liczby na jakiej pozycji szukasz: ";
    //cin >> x;

    GenTab(A,N);
    PrintTab(A,N);
    //cout << QuickSelect_Lomuto(A,N-1,2) << " ";
    cout << QuickSelect_Lomuto(A,0,N-1,2) << endl;
    QuickSort_Lomuto(A,0,N-1);
    PrintTab(A,N);


    return 0;
}

void GenTab(int A[N],int N){

    for(int i=0;i<N;i++){
        A[i]=rand()%(N*N);
    }
}
void PrintTab(int A[N],int N){
    for(int i=0;i<N;i++){
        // cout << << "[" << i << "]"
        cout << A[i] << " ";
    }
    cout << endl;
}
void QuickSort_Lomuto(int A[],int l,int r){
    while(l<r){
        int p=Partition(A,l,r);
        QuickSort_Lomuto(A,l,p-1);
        l=p+1;
    }
}
int QuickSelect_Lomuto(int A[],int n,int k){
    if(n==1)  return A[0];
    int q=Partition(A,0,n-1);
    if(q==k) return A[q];
    else if(k<q) return QuickSelect_Lomuto(A,q,k);
    else return QuickSelect_Lomuto(A+q+1,n-(q+1),k-(q+1));
}
int Partition(int A[],int l,int r){
    int i=l;
    int j=l;
    int x=A[r];
    while(j<r){
        if(A[j]<x){
            Swap(A[j],A[i]);
            i++;
        }
        j++;
    }
    Swap(A[r],A[i]);
    return i;
}

