#include <iostream>
#include <cstdlib>
#include  <ctime>
using namespace std;
const int N=5;

struct pole{
    int wiersz,suma;
};

void GenTab(int A[N*N],int N);
void SumSort(int A[N*N],int B[N*N],int N);
void PrintTab(int A[N*N],int N);
void Swap(pole &x, pole &y);
void QuickSort(pole ile[],int l,int p);

int main(){
    int A[N*N];
    int B[N*N];
    GenTab(A,N);
    PrintTab(A,N);
    SumSort(A,B,N);
    PrintTab(B,N);
    return 0;
}

void GenTab(int A[N*N],int N){
    srand(time(0));
    for(int i=0;i<N*N;i++){
        A[i]=rand()%(N*N)+10;
    }
}

void PrintTab(int A[N*N],int N){
     for(int i=0;i<N;i++){
        int suma=0;
        for(int j=0;j<N;j++){
            suma+=A[i*N+j];
            cout << A[i*N+j] << ' ';
        }
        cout << "| " << suma << endl;
    }
    cout << endl;
}

void SumSort(int A[N*N],int B[N*N],int N){
    pole ile[N];
    for(int i=0;i<N;i++){
        ile[i].wiersz=i;
        ile[i].suma=0;
        for(int j=0;j<N;j++){
            ile[i].suma+=A[i*N+j];
        }
    }
    QuickSort(ile,0,N-1);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            B[i*N+j]=A[ile[i].wiersz*N+j];
        }
    }
}

void QuickSort(pole ile[],int l,int p){
    int i=l;
    int j=p;
    int x=ile[(i+j)/2].suma;
    while(i<=j){
        while(ile[i].suma<x) i++;
        while(ile[j].suma>x) j--;
        if(i<=j){
            Swap(ile[i],ile[j]);
            i++;
            j--;
        }
    }
    if(i<p)QuickSort(ile,i,p);
    if(l<j)QuickSort(ile,l,j);
}

void Swap(pole &x, pole &y){
    pole tmp=x; x=y; y=tmp;
}

