#include <iostream>
#include <iomanip>
using namespace std;
const double eps=1e-10;

int main(){
    double suma,wyraz,silnia=1;
    wyraz=1/silnia;
    suma=wyraz;
    for(int n=1;wyraz>eps;n++){
        silnia=silnia*n;
        wyraz=1/silnia;
        suma=suma+wyraz;
    }
    cout << setprecision(11) << suma;
    return 0;}
