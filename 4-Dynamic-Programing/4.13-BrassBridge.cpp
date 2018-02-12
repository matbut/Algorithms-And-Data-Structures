#include <iostream>
#include <string>

const int N=10;
using namespace std;

int Max(int a,int b){
    if(a>=b)
        return a;
    return b;
}

int main(){
    int bridge[N]={4,2,6,4,8,2,4,1,9,4};
    int F[N+1]; // max zysk z kradziezy i filarow
    cout << "Zawartosc miedzi w filarach: " << endl;
    for(int i=0;i<N;i++)
        cout << "Filar " << i << " zawiera " << bridge[i] << " miedzi" << endl;
    cout << endl;

    F[0]=0;
    F[1]=bridge[0];
    F[2]=bridge[0]+bridge[1];

    for(int i=3;i<=N;i++){
        F[i]=Max(F[i-3]+bridge[(i-1)-1]+bridge[i-1],F[i-2]+bridge[i-1]);
        F[i]=Max(F[i],F[i-1]);
    }

    cout << "Najwiecej miedzi ile mozna ukrasc: " << F[N] << endl;
    return 0;
}


