#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
const int MAX1=3;
const int MAX2=3;

int main(){
    int tab[MAX1][MAX2],suma_wiersz=0, maxsuma_wiersz=0, suma_kolumn=0, maxsuma_kolumn=0,wsk_wiersz, wsk_kolumna;
    srand(time(0));
    for(int i=0;i<MAX1;i++){
        for(int j=0;j<MAX2;j++){
        tab[i][j]=rand()%20;
        cout << tab[i][j] << " ";
        }
    cout << endl;
    }

    for(int i=0;i<MAX1;i++){
        for(int j=0;j<MAX2;j++){
            suma_wiersz=suma_wiersz+tab[i][j];
            suma_kolumn=suma_kolumn+tab[j][i];
        }
        if (suma_wiersz>maxsuma_wiersz) {
                maxsuma_wiersz=suma_wiersz;
                wsk_wiersz=i;
        }
        if (suma_kolumn>maxsuma_kolumn) {
                maxsuma_kolumn=suma_kolumn;
                wsk_kolumna=i;
        }
        suma_kolumn=0;
        suma_wiersz=0;
    }
    cout << " " << wsk_wiersz+1 << " " <<wsk_kolumna+1;
    return 0;
}
