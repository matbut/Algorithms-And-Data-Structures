#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
const int N=10;
const int W=2;
const int R=100;

void GenTab(int t[]);
void PrintTab(int t[N]);
void SelectSort(int t[N]);
int FindMin(int t[N],int p);
void Swap(int &x,int &y){
    int tmp=x; x=y; y=tmp;
}

int main(){
    int t[N];
    GenTab(t);
    PrintTab(t);
    SelectSort(t);
    PrintTab(t);
    return 0;
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
int FindMin(int t[N],int p){
    int min_i=p;
    for(int i=p+1;i<N;i++){
        if(t[i]<t[min_i])
            min_i=i;
    }
    return min_i;
}

void SelectSort(int t[N]){
    for(int i=0;i<N-1;i++){
        Swap(t[i],t[FindMin(t,i)]);
        /*
        int min_i=FindMin(t,i);
        int tmp=t[i];
        t[i]=t[min_i];
        t[min_i]=tmp;
        */
    }
}

