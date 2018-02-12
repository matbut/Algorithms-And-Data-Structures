#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long int x, kx, suma=0;
    int c1,c2,cj;
    cout << "c2 c1 kx c1 suma" << endl;
    for (int x=123 ; x<124 ; x++){
        kx=x;
        c1=kx%10;
        cj=c1;
        cout << "c1=" << c1 << " " ;
        cout << "cj=" << cj << " " << endl;
        suma=0;

        while (kx>9){

            cout << c2 << " ";
            c2=c1;
            cout << c1 << " ";
            kx=kx/10;
            cout << kx << " ";
            c1=kx%10;
            cout << c1 << " ";
            suma=suma+pow(c1,c2);
            cout << suma << " " << endl;
        }
        suma=suma+pow(cj,c1);
        cout << suma << " " << endl;
        //cout << cj << " " << c1 << " " << c2 <<endl;
        //cout << "Suma =" << suma << endl;
        if (suma==x) cout << x << " to liczba Gajeckiego!" << endl; //else cout << "To nie jest liczba Gajeckiego" << endl;
    }
}

