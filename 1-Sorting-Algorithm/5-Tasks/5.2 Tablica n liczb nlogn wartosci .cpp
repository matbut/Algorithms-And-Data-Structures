#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
const int N=10;
const int M=int(log(N))+2;

struct pole{
    int liczba,licznik;
};

void PrintTab(int t[N]);
void Sort(int t[N]);
int BinSearch(pole ile[],int p,int k,int x);

int main(){
    srand(time(0));
    int t[N];
    int x=rand()%(N*N)+N;
    for(int i=0;i<N;i++){
        t[i]=x+rand()%M;
    }
    PrintTab(t);
    Sort(t);
    PrintTab(t);
    return 0;
}
void PrintTab(int t[N]){
    for(int i=0;i<N;i++){
        cout << t[i] << ' ';
    }
    cout << endl;
}
void Sort(int t[N]){
    pole ile[M];
    int koniec=0;

    for(int i=0;i<N;i++){
        int x=BinSearch(ile,0,koniec,t[i]);
        if(x>=0){
            ile[x].licznik++;
        }else{
            x=-x-1;
            koniec++;
            for(int j=koniec;j>x;j--){
                ile[j]=ile[j-1];
            }
            ile[x].liczba=t[i];
            ile[x].licznik=1;
        }
    }
    for(int i=1;i<M;i++){
        ile[i].licznik+=ile[i-1].licznik;

    }
    int kopia[N];
    for(int i=N-1;i>=0;i--){
        kopia[ile[BinSearch(ile,0,M-1,t[i])].licznik-1]=t[i];
        ile[BinSearch(ile,0,M-1,t[i])].licznik--;
    }
    for(int i=0;i<N;i++){
        t[i]=kopia[i];
    }
}

int BinSearch(pole ile[],int p,int k,int x){
    if(p==k){
        if(ile[p].liczba==x) return p;
        return -(p+1);
    }
    if(ile[(p+k)/2].liczba<x) return BinSearch(ile,(p+k)/2+1,k,x);
    else return BinSearch(ile,p,(p+k)/2,x);
}


