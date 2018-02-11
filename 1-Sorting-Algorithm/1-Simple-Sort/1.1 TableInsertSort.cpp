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
void InsertSort(int t[N]);

int main(){
    int t[N];
    GenTab(t);
    PrintTab(t);
    InsertSort(t);
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
void InsertSort(int t[N]){
    for(int i=1;i<N;i++){
        int tmp=t[i];
        int j;
        for(j=i-1;j>=0 and t[j]>tmp;j--){
            t[j+1]=t[j];
        }
        t[j+1]=tmp;
    }
}

