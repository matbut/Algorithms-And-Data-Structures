#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
const int MAX=10;

int nwd(int a,int b){
    if(b==0) return a;
    return nwd(b,a%b);

};

int main(){
    int x,y;
    cout << "Podaj liczbe: ";
    cin >> x;
    cout << "Podaj liczbe: ";
    cin >> y;
    cout << endl << "Nwd(" << x << "," << y << ")=" << nwd(x,y);
    return 0;
}
