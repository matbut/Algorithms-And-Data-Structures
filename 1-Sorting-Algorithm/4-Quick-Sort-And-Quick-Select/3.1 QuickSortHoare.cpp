#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
const int N=10;

void GenTab(int A[N],int N);
void PrintTab(int A[N],int N);

void QuickSort_Hoare(int A[],int l,int r);
int QuickSelect_Hoare(int A[],int l,int r,int k);

void Swap(int &x,int &y){
    int tmp=x; x=y; y=tmp;
}
void QS(int A[],int l,int r){
    int i=l;
    int j=r;
    int x=A[(i+j)/2];
    while(j<=i){
        while(A[i]<x)
            i++;
        while(A[j]>x)
            j--;
        if(j<=i)
            Swap(A[i],A[j]);
            i++;
            j--;
    }
    if(l<j) QS(A,l,j);
    if(i<r) QS(A,i,r);
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
    cout << QuickSelect_Hoare(A,0,N-1,2) << endl;
    QuickSort_Hoare(A,0,N-1);
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

void QuickSort_Hoare(int A[],int l,int r){
    int i=l;
    int j=r;
    int x=A[(i+j)/2];
    while(i<=j){
        while(A[i]<x) i++;
        while(A[j]>x) j--;
        if(i<=j){
            Swap(A[i],A[j]);
            i++;
            j--;
        }
    }
    if(l<j) QuickSort_Hoare(A,l,j);
    if(i<r) QuickSort_Hoare(A,i,r);
}
int QuickSelect_Hoare(int A[],int l,int r,int k){
    if(l==r)
        return A[l];

    int i=l;
    int j=r;
    int x=A[(i+j)/2];
    //cout << (i+j)/2 << ',';
    while(i<=j){
        while(A[i]<x) i++;
        while(A[j]>x) j--;
        if(i<=j){
            Swap(A[i],A[j]);
            i++;
            j--;
        }
    }
    if(l<j and k<j) return QuickSelect_Hoare(A,l,j,k);
    if(i<r and i<k) return QuickSelect_Hoare(A,i,r,k);
}



