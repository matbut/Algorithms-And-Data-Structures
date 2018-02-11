#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
const int MAX=5;

void generuj(int tab[]){
    srand(time(0));
    for(int i=0;i<MAX;i++){
        tab[i]=rand()%MAX;
        cout << tab[i] << " ";
    }
}

void podzbiory(int tab[],int i, int ile, int suma_el, int suma_i, int min_ile, int &min_suma){
    //cout << i << " " << suma_el << " " << suma_i << " " << endl;
    if(i==MAX){
        if(suma_el==suma_i && ile<min_ile && ile!=0){
            min_ile=ile;
            min_suma=suma_el;
        }
    }else{
        podzbiory(tab,i+1,ile+1,suma_el+tab[i],suma_i+i,min_ile,min_suma);
        podzbiory(tab,i+1,ile,suma_el,suma_i,min_ile,min_suma);
    }
}

int gen_podzbiory(int tab[]){
    int min_suma=0;
    podzbiory(tab,0,0,0,0,MAX,min_suma);
    return min_suma;
}

int main(){
    int tab[MAX];
    generuj(tab);
    cout << endl << "Trolo:" << gen_podzbiory(tab);
}
