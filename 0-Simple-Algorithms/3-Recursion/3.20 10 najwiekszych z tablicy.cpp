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
        tab[i]=rand()%10;
        cout << tab[i] << " ";
    }
    cout << endl;
}



int main(){
    int tab[MAX];
    generuj(tab);
    int naj[ILE];
    for(int i=0;i<ILE;i++){
        naj[i]=tab[i];
    }
    for(int i=ILE;i<MAX;i++){
        int minimum=0;
        for(int j=1;j<ILE;j++){
            if (naj[j]<naj[minimum]){
                minimum=j;
            }
        }
        if(tab[i]>naj[minimum]){
            naj[minimum]=tab[i];
        }
    }
    for(int i=0;i<ILE;i++){
        cout << naj[i] << " ";
    }

}
