// PROGRAM PIERWIASTEK METODA NEWTONA

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    float eps=1e-11;
    double s,a=1,ka=0;
    cout << "Podaj liczbe: ";
    cin >> s;
    while (abs(a-ka)>eps){
        ka=a;
        a=((s/ka)+ka)/2.0;
    }
    cout << "Pierwiastek z " << s << " to " << setprecision(11) << a << endl;


return 0;}
