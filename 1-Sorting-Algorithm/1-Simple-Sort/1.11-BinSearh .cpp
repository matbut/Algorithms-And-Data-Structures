#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
const int N=10;

void GenTab(int A[N*N],int N);
void PrintTab(int A[N*N],int N);
int BinSearch(int A[N],int p,int k,int x);

int main(){
    int A[N];
    int x;
    GenTab(A,N);
    PrintTab(A,N);
    cout << "Czego szukasz: ";
    cin >> x;
    x=BinSearch(A,0,N-1,x);
    if(x>=0) cout << "Jest na pozycji " << x << endl;
    else cout << "Nie ma, powinien byæ na pozycji " << -x-1 << endl;
    return 0;
}

void GenTab(int A[N],int N){
    srand(time(0));
    A[0]=rand()%N+1;
    for(int i=1;i<N;i++){
        A[i]=A[i-1]+rand()%N;
    }
}
void PrintTab(int A[N],int N){
    for(int i=0;i<N;i++){
        cout << A[i] << ' ';
    }
    cout << endl;
}
int BinSearch(int A[N],int p,int k,int x){
    if(p==k)
        if(A[p]==x) return p;
            else return -(p+1);
    if(A[(p+k)/2]>=x)    return BinSearch(A,p,(p+k)/2,x);
    else    return BinSearch(A,(p+k)/2+1,k,x);
}
