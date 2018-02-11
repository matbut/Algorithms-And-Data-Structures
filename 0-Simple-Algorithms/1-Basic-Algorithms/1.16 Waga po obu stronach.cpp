#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
const int MAX=10;

bool waga(int w,int t[],int i){
    if(w==0) return true;
    if(i==MAX) return false;
    return waga(w,t,i+1) || waga(w-t[i],t,i+1) || waga(w+yt t[i],t,i+1);
;}

int main(){
    int odwazniki[MAX]={1,3,5};
    int w;
    cout << "Podaj mase: ";
    cin >> w;
    if (waga(w,odwazniki,0)) cout << "Tak"; else cout << "Nie";


    return 0;
}
