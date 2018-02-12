#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
using namespace std;
const int MAX=5;
int szachownica[MAX][MAX];

void kolor(int c) {
     //7 bialoszary 8 szary 15bialy 14 zolty
     HANDLE uchwyt;
     uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(uchwyt,c);
}

void drukuj(int w, int k){
    system( "cls" );
    for(int i=0;i<MAX*MAX;i++){
          if (szachownica[w][k]==MAX*MAX)     kolor(14);
          if (szachownica[i/MAX][i%MAX]==0)   kolor(8);
          if (i/MAX==w && i%MAX==k)           kolor(14);
        cout << char(254) << " ";
          kolor(7);
        if ((i+1)%MAX==0) cout << endl;
    }
    cout << endl;
    Sleep(200);
};

bool mozna(int w,int k,int i, int &w2, int &k2){
    int wiersz[8] {-2,-1,1,2, 2, 1,-1,-2};
    int kolumna[8]{ 1, 2,2,1,-1,-2,-2,-1};
    w2=w+wiersz[i];
    k2=k+kolumna[i];
    return w2>=0 && k2>=0 && w2<MAX && k2<MAX && szachownica[w2][k2]==0;
};

void skoczek(int w,int k,int n){
    szachownica[w][k]=n+1;
    drukuj(w,k);
    if(n==MAX*MAX-1){
        cout << "Znalazlem!" << endl << "Nacisnij jakis klawisz";
        getch();
    }else{
        int w2=w,k2=k;
        for(int i=0;i<8;i++){
            if (mozna(w,k,i,w2,k2)){
                skoczek(w2,k2,n+1);
            }
        }
    }
    drukuj(w,k);
    szachownica[w][k]=0;
};

int main(){
    for(int i=0;i<MAX*MAX;i++){
        szachownica[i/MAX][i%MAX]=0;
    }
    skoczek(0,0,0);
    return 0;
}
