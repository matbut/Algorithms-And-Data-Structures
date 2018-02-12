#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long int x, kx, suma=0;
    int c1,c2,cj;
    for (int x=11 ; x<9999999999999999 ; x++){
        kx=x;
        c1=kx%10;
        cj=c1;
        suma=0;

        while (kx>9){
            c2=c1;
            kx=kx/10;
            c1=kx%10;
            suma=suma+pow(c1,c2);
        }
        suma=suma+pow(cj,c1);
        if (suma==x) cout << x << " to liczba Gajeckiego!" << endl;
    }
}

