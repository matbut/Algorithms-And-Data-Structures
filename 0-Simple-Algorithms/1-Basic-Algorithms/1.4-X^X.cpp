#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double eps=1e-10;

int main(){
    double a,b,x,y,liczba;
    cout << "Podaj liczbe: ";
    cin >> liczba;
    b=liczba;
    a=1;
    while(b-a>eps){
        x=(b+a)/2;
        y=exp(x*log(x));
        if (y<liczba){
            a=x;
        }else{
            b=x;
        }
    }
    cout << setprecision(10) << x << "^" << x << "=" << liczba;
    return 0;}
