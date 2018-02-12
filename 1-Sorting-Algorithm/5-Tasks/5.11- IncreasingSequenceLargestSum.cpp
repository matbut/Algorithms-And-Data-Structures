#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int N=10;
const int R=20;

int*GenTab(int n){
    int*Tab=new int[n];
    for(int i=0;i<n;i++)
        Tab[i]=rand()%9+1;
    return Tab;
}
void PrintTab(int*Tab,int n){
    for(int i=0;i<n;i++)
        cout << Tab[i] << "  ";
    cout << endl;
}
int MaxSum(int*Tab,int n){
    // F(i) max suma od 0 do i jak sie konczy na i elemencie
    int F[n];
    F[0]=Tab[0];
    int MaxSumIdx=0;
    for(int i=1;i<n;i++){
        if(Tab[i]>Tab[i-1])
            F[i]=F[i-1]+Tab[i];
        else
            F[i]=Tab[i];
        if(F[i]>F[MaxSumIdx])
            MaxSumIdx=i;
    }
    int Sum=F[MaxSumIdx];
    int i=MaxSumIdx;
    cout << "Podciag rosnacy o najwiekszej sumie: ";
    while (Sum>0){
        Sum-=Tab[i];
        i--;
    }
    i++;
    for(i;i<=MaxSumIdx;i++)
        cout << Tab[i] << " ";
    cout << endl;
    return F[MaxSumIdx];
}
int main(){
    srand(time(0));
    int n=10;
    int*t=GenTab(n);
    PrintTab(t,n);
    cout << "Maksymalna suma: " << MaxSum(t,n) << endl;
    return 0;
}


