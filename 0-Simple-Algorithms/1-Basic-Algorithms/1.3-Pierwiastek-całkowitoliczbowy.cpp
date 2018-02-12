#include <iostream>
#include <cmath>

using namespace std;

int IntEl(int liczba,int podstawa,int skladnik,int suma){
    if(liczba<skladnik+suma)
        return podstawa;
    return IntEl(liczba,podstawa+1,skladnik+2,suma+skladnik);
}
int IntElemnt(int liczba){
    return IntEl(liczba,0,1,0);
}

int main(){

    int a=1,n=0,k,suma=0;

    for(int k=0;k<200;k++)
        cout << k << " to " << IntElemnt(k) << "^2 "  << endl;


    /*

    cout << "Poddaj liczbe" << endl;
    cin >> k;
    while (k>=(suma+a)){
        suma+=a;
        a+=2;
        n++;
    }
    */
    return 0;
}


