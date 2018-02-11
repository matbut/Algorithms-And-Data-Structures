// PROGRAM WYKRESLANIE CYFR< PODZIELNOŒÆ PRZEZ 7
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int x, kx, r=0, kr, l,c=0;
    /* x wprowazana liczba
       kx kopia x
       r rewers x
       kr kopia r
       l liczba tworzona przez wykreslanie
       c liczba cyfr*/

    cin >> x;
    kx=x;

    while(kx>0) { //rewers liczby
        r=r*10+kx%10;
        kx=kx/10;
        c++;
    }
    for (int i=0; i<pow(2,c) ; i++){
        kr=r;
        int ki=i;   // ki - matryca
        l=0;
        while (ki>0){
            if(ki%2==1) l=l*10+kr%10;
            kr=kr/10;
            ki=ki/2;
        }
        if (l%7==0) {cout << l << endl;}
    }

return 0;
}
