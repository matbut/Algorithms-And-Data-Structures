#include <iostream>
#include <cmath>
using namespace std;
const int N=12;
const int K=4;

void Print(int t[N]);
void CountSort(int t[N]);

int main(){
    int t[N]={0,1,1,0,2,3,1,1,2,3,1,0};
    Print(t);
    CountSort(t);
    Print(t);

    return 0;
}

void Print(int t[N]){
    for(int i=0;i<N;i++){
        cout << t[i] << " ";
    }
    cout << endl;
}

void CountSort(int t[N]){
    int ile[K],kt[N];
    for(int i=0;i<K;i++) ile[i]=0;
    for(int i=0;i<N;i++) ile[t[i]]++;
    for(int i=1;i<K;i++) ile[i]=ile[i]+ile[i-1];
    for(int i=N-1;i>=0;i--){
        kt[ile[t[i]]-1]=t[i];
        ile[t[i]]--;
    }
    for(int i=0;i<N;i++) t[i]=kt[i];
}


