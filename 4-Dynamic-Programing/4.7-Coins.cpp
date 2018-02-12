#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int N=4;
int change(int C[], int k, int n);

int main(){
    int Coins[N]={1,3,8,17};
    cout << "Monety: ";
    for(int i=0;i<N;i++)
        cout << Coins[i] << " ";
    cout << endl << "Podaj kwote: ";
    int x;
    cin >> x;
    cout << "Potrzeba " << change(Coins,x,N) << " monet";
    return 0;
}

int change(int C[], int k, int n){ //k to kwota, n to liczba nominalow
    int T[k+1];
    int P[k+1];
    T[0]=0;
    // T[t]=T[t-C[i]]+1; C[i] jak najwieksze
    for(int t=1;t<k+1;t++){
        T[t]=0;
        bool mam=false;
        for(int i=n-1;i>=0 and !mam;i--)
            if(t-C[i]>=0){
                T[t]=T[t-C[i]]+1;
                P[t]=C[i];
                mam=true;
            }
    }
    int t=k;
    cout << "Monety: ";
    while(t>0){
        cout << P[t] << " ";
        t=t-P[t];
    }
    return T[k];
}
