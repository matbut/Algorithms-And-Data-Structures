#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
using namespace std;

const int MAX=8;
int szachownica[MAX][MAX];
int licznik=0;

void kolor(int c) {
        //7 bialoszary 8 szary 15bialy 14 zolty
        HANDLE uchwyt;
        uchwyt=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(uchwyt,c);
}

void wypisz(int w, int k){
    system("cls");
    for(int i=0;i<MAX*MAX;i++) {
            if(i/MAX==w && i%MAX==k)            kolor(12); else
            if(szachownica[i/MAX][i%MAX]==1)    kolor(14); else
            if(szachownica[i/MAX][i%MAX]==0)    kolor(8); else
            kolor(15);
            cout << char(254) << " ";

        if((i+1)%MAX==0)cout << endl;
    }
    Sleep(200);
    //getch();

}
void zajmuj(int w, int k){
    for(int i=0;i<MAX;i++) {
        szachownica[w][i] -= 1;
        szachownica[i][k] -= 1;
        for(int j=0;j<MAX;j++) {
            if(i+j==w+k || i-j==w-k) szachownica[i][j] -= 1;
        }
    }
}
void zwalniaj(int w, int k){
    for(int i=0;i<MAX;i++) {
        szachownica[w][i] += 1;
        szachownica[i][k] += 1;
        for(int j=0;j<MAX;j++) {
            if(i+j==w+k || i-j==w-k) szachownica[i][j] += 1;
        }
    }
}

void hetman(int w, int k, int h){
    zajmuj(w,k);
    szachownica[w][k]=1;
    //wypisz(w,k);
    if (h==MAX){
        wypisz(w,k);
        //cout << "Znalazlem!";
        //getch();
        licznik++;
        //system("cls");
    }
    for(int i=MAX*w+k+1;i<MAX*MAX;i++)
            if(szachownica[i/MAX][i%MAX]==0)
                hetman(i/MAX,i%MAX,h+1);

    zwalniaj(w,k);
    szachownica[w][k]=0;
}

void czysc(){
    for(int i=0;i<MAX*MAX;i++)
            szachownica[i/MAX][i%MAX]=0;
}
int main(){
    for(int k=0;k<MAX;k++){
        czysc();
        hetman(0,k,1);
    }
    //hetman(0,0,1);
    system("cls");
    cout << "Liczba roznych ustawien: " << licznik;
return 0;
}
