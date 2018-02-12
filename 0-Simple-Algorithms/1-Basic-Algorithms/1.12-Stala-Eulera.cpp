// PROGRAM STALA EULERA

#include <iostream>
#include <cmath>
#include <iomanip>
const float eps=1e-10;
using namespace std;

int main(){
    double e=0,ke=1,suma=0,sem=0;
    int n=1;
    while (abs(e-ke)>eps){
        ke=e;
        suma=suma+1/float(n);
        e=suma-log(n);
        n++;
        if (abs(e-ke)<eps) sem++; else sem=0;

    }
    cout << "Liczba Eulera to: " << setprecision(10) << e << endl;
return 0;}
