#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
const int MAX=10;

void generuj(int tab[]){
    srand(time(0));
    for(int i=0;i<MAX;i++){
        tab[i]=rand()%8+2;
        cout << tab[i] << " ";
    }
    cout << endl;
}

bool skoki(int i,int tab[],int &droga){
    cout << i << endl;
    if (i>=MAX) return false;
    if (i==MAX-1) {

        return true;
    }

    int tmp=tab[i];
    for(int d=2;d<=tmp;d++){
        if(tmp%d==0){
            droga=10*droga+tab[i];
            if(skoki(i+d,tab,droga)) return true;
            while(tmp%d==0) tmp=tmp/d;
        }
    }
    return false;
}

int main(){
    int tab[MAX];
    generuj(tab);
    int droga=0;
    if (skoki(0,tab,droga)) cout << "Da sie, droga to: " << droga; else cout << "Nie da sie";
}
