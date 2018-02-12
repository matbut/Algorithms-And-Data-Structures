#include <iostream>
using namespace std;

int main(){
    int n,i2,i3,i5,licznik=0;
    cout <<"Do jakiej wartosci: ";
    cin >> n;
    i2=1;
    while(i2<=n){
        i3=i2;
        while(i3<=n){
            i5=i3;
            while(i5<=n){
                cout << i5 << " ";
                i5=i5*5;
                licznik++;
            }
            i3=i3*3;
        }
        i2=i2*2;
    }
    cout << endl << licznik;
    return 0;}
