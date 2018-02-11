#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
using namespace std;
const int N=1;

struct ciag{
    int p_w; //poczatkowy wiesz
    int p_k; //  -||-     kolumna
    int dl;
};

bool czy_naturalna(double x){
    double y=int(x);
    return y==x;
}

bool szukaj_ciag(int t[N][N],int w,int k,ciag &maks){
    ciag biez;
    bool czy=false;
    biez.p_w=w; biez.p_k=k; biez.dl=2;
    while(biez.p_w<N-2 and biez.p_k<N-2){
        if(t[biez.p_w][biez.p_k]*t[biez.p_w+2][biez.p_k+2]==t[biez.p_w+1][biez.p_k+1]*t[biez.p_w+1][biez.p_k+1]){
            biez.dl++;
            czy=true;
            cout << "true " << biez.p_w << " " << biez.p_k << " dl:" << biez.dl << endl;
            if(biez.dl>maks.dl){
                maks=biez;
            }
        }
        biez.p_w++; biez.p_k++;
    }
    return czy;
}

void gen_szukaj(int t[N][N]){
    ciag maks;
    maks.dl=2;
    bool czy=szukaj_ciag(t,0,0,maks);
    for(int i=1;i<N-2;i++){
        bool czy2=szukaj_ciag(t,0,i,maks);
        bool czy3=szukaj_ciag(t,i,0,maks);
        czy=czy or czy2 or czy3;
    }
    if (czy) cout << "Da sie [" << maks.p_w << "][" << maks.p_k << "] a dlugos to " << maks.dl << endl; else cout << "Nie da sie";
}

void gen_tab(int t[N][N]){
    srand(time(0));

    for(int i=0;i<N*N;i++){
        t[i/N][i%N]=rand()%(N/2)+1;
        cout.width(2);
        cout << t[i/N][i%N] << " ";
        if((i+1)%N==0) cout << endl;
    }


}


int main(){
    int t[N][N];
    gen_tab(t);
    gen_szukaj(t);
    return 0;
}
