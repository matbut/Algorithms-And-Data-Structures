#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N=4;
const int W=2;

struct wiez{
    int suma=0;
    int w=0;
    int k=0;
};

int szachuj(int tab[N][N],int w1,int k1,int w2,int k2,int suma_wier[],int suma_kol[]){
    int suma=0;
    if(w1!=w2 and k1!=k2){
        suma=suma_wier[w1]+suma_kol[k1]+suma_wier[w2]+suma_kol[k2];
        suma=suma-tab[w1][k2]-tab[w2][k1]-2*tab[w1][k1]-2*tab[w2][k2];
    }
    else if(w1==w2){
        suma=suma_wier[w1]+suma_kol[k1]+suma_kol[k2]-tab[w1][k1]-tab[w2][k2];
    }else if(k1==k2){
        suma=suma_wier[w1]+suma_wier[w2]+suma_kol[k1]-tab[w1][k1]-tab[w2][k2];
    }
    // cout << w1 << " " << k1 << "   " << w2 << " " << k2 << "  Suma to:" << suma << endl;
    return suma;
}

void wieze(int tab[N][N]){
    int suma_wier[N];
    int suma_kol[N];
    for (int i=0;i<N;i++){
        suma_wier[i]=0;
        suma_kol[i]=0;
    }
    for (int i=0;i<N*N;i++){
        suma_wier[i/N]+=tab[i/N][i%N];
        suma_kol[i/N]+=tab[i%N][i/N];
    }

    int maxsuma=0;
    int w1,k1,w2,k2;
    for (int i=0;i<N*N-1;i++){
        for(int j=i+1;j<N*N;j++){
            int suma=szachuj(tab,i/N,i%N,j/N,j%N,suma_wier,suma_kol);
            if(suma>maxsuma){
                maxsuma=suma;
                w1=i/N; k1=i%N; w2=j/N; k2=j%N;
            }
        }
    }
    cout << "Ustawienie to: " <<  w1 << " " << k1 << "   " << w2 << " " << k2 << endl;
    cout << "Max suma to: " << maxsuma;
}

void generuj(int tab[N][N]){
    srand(time(0));
    for(int i=0;i<N*N; i++){
        tab[i/N][i%N]=rand()%19-9;
        cout.width(2);
        cout << tab[i/N][i%N] << " ";
        if((i+1)%N==0) cout << endl;
    }
}

int main(){
    int tab[N][N];
    generuj(tab);
    wieze(tab);
}
