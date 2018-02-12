#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int N=40;

void GenTab(int A[N],int N);
void PrintTab(int A[N],int N);
void RotTab(int A[N],int N,int ile);
void Swap(int &x,int &y){
    int tmp=x; x=y; y=tmp;
}

int main(){
    int A[N];
    GenTab(A,N);
    PrintTab(A,N);
    RotTab(A,N,39);
    PrintTab(A,N);
}
void RotTab(int A[N],int N,int ile){
    int i=0;
    int zamiana=0;
    int x=-1;
    while (zamiana<N){
        while(A[i%N]!=-1 and zamiana<N){
            Swap(A[i%N],x);
            zamiana++;
            i+=ile;
        }
        Swap(A[i%N],x);
        i++;
    }
}
void GenTab(int A[N],int N){
    srand(time(0));
    for(int i=0;i<N;i++){
        A[i]=rand()%(N);
    }
}
void PrintTab(int A[N],int N){
    for(int i=0;i<N;i++){
        //cout << "[" << i << "]"
        cout << A[i] << " ";
    }
    cout << endl;
}


