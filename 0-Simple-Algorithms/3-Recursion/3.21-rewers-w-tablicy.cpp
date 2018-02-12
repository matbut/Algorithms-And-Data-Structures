#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
const int MAX=10;
const int ILE=5;

void generuj(int tab[]){
    srand(time(0));
    for(int i=0;i<MAX;i++){
        tab[i]=rand()%9+1;
        cout << tab[i] << " ";
    }
    cout << endl;
}

int rewers(int x){
    return (x%10)*10+(x/10)%10;
}

int main(){
    int tab[MAX];
    generuj(tab);
    int naj[ILE];
    for(int i=0;i<MAX;i++){
        int ciag=tab[i];
        for(int j=i+1;j<i+(MAX-i)/2+1;j++){
            ciag=10*ciag+tab[j];
            if(ciag==rewers(ciag)){
                cout << ciag << " " << rewers(ciag);
            }
        }
    }
}
