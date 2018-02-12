#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int N=10;
const int W=20;
const int R=15;

void GenTab(int t[],int n);

int lis(int A[],int n);
void PrintList(int A[],int F[],int P[],int i);

int main(){
    srand(time(0));
    int A[N];
    GenTab(A,N);
    int x=lis(A,N);
    cout << endl << "Najdluzszy podciag rosnacy ma " << x << " elementow" << endl;
    return 0;
}
int lis(int A[],int n){
    int F[n];    // pole A[i] przechowuje dlugosc najdluzszego ciagu konczacego sie na A[i]
    int P[n];    // pole P[i] przechowuje poprzedni (dla elementu i) element ciagu.
    int Max=1;
    int Max_ind=0;

    for(int i=0;i<n;i++){
        F[i]=1;
        P[i]=-1;
        for(int j=0;j<i;j++){
            if(A[j]<A[i] and F[j]+1>F[i]){
                F[i]=F[j]+1;
                P[i]=j;
            }
        }
        if(F[i]>Max){
            Max=F[i];
            Max_ind=i;
        }
    }
    PrintList(A,F,P,Max_ind);
    return Max;
}
void PrintList(int A[],int F[],int P[],int i){
    if(P[i]>=0)
        PrintList(A,F,P,P[i]);
    cout << A[i] << "->";
}
void GenTab(int t[],int n){
    int x=rand()%W;
    for(int i=0;i<n;i++){
        t[i]=x+rand()%R;
        cout << t[i] << "  ";
    }
    cout << endl;
}




