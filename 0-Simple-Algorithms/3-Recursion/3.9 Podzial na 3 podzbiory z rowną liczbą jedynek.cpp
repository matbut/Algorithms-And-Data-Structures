#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
const int MAX=5;

struct zbior{
    int suma;
    int dec;
};

void generuj(int tab[]){
    srand(time(0));
    for(int i=0;i<MAX;i++){
        tab[i]=rand()%MAX;
        cout << tab[i] << " ";
    }
    cout << endl;
}

int jedynki(int x){
    int suma=0;
    while(x>0){
        suma+=x%2;
        x=x/2;
    }
    return suma;
}

bool podzial(int tab[],int i,zbior zb1,zbior zb2,zbior zb3){
    //cout << zb1.dec << " " << zb2.dec << " " << zb3.dec << endl;
    if(i==MAX){
        if (zb1.suma==zb2.suma && zb1.suma==zb3.suma){
            cout << "{" << zb1.dec << "} {" << zb2.dec << "} {" << zb3.dec << "}" << endl;
            return true;
        }
        return false;
    }
    zbior kzb1,kzb2,kzb3;
    kzb1.suma=zb1.suma+jedynki(tab[i]);
    kzb1.dec=zb1.dec*10+tab[i];
    kzb2.suma=zb2.suma+jedynki(tab[i]);
    kzb2.dec=zb2.dec*10+tab[i];
    kzb3.suma=zb3.suma+jedynki(tab[i]);
    kzb3.dec=zb3.dec*10+tab[i];
    return podzial(tab,i+1,kzb1,zb2,zb3) || podzial(tab,i+1,zb1,kzb2,zb3) || podzial(tab,i+1,zb1,zb2,kzb3);

}

int main(){
    int tab[MAX]={2,3,5,7,15} ;
    //generuj(tab);
    zbior kzb;
    kzb.suma=0;
    kzb.dec=0;
    if (podzial(tab,0,kzb,kzb,kzb)) cout << "Da sie"; else cout << "Nie da sie";
}
