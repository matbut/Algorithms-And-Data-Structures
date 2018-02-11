#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
using namespace std;

const int MAX=8;
int szachownica[MAX][MAX];
int hetmany[MAX/2][2];
int max_licznik=0;

void kolor(int c) {
        //7 bialoszary 8 szary 15bialy 14 zolty
        HANDLE uchwyt;
        uchwyt=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(uchwyt,c);
}

void czysc(){
    for(int i=0;i<MAX*MAX;i++)
            szachownica[i/MAX][i%MAX]=0;
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

void wypisz(){
    czysc();
    system("cls");
    int j=0;
    for(int i=0;i<MAX*MAX;i++) {
        if(i/MAX==hetmany[j][0] && i%MAX==hetmany[j][1]) {
            zajmuj(hetmany[j][0], i%MAX==hetmany[j][1]);
            szachownica[hetmany[j][0]][hetmany[j][1]]=1;
            j++;
        }
    }
    for(int i=0;i<MAX*MAX;i++) {
        if(szachownica[i/MAX][i%MAX]==1)    kolor(14); else
        if(szachownica[i/MAX][i%MAX]==0)    kolor(8); else
        kolor(15);
        cout << char(254) << " ";
        if((i+1)%MAX==0)cout << endl;
    }
    Sleep(100);
    //getch();
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

void zlicz(){
    int licznik=0;
    int j=0;
    for(int i=0;i<MAX*MAX;i++){
        if (szachownica[i/MAX][i%MAX]!=0){
            licznik++;
        }
        if (licznik>max_licznik) {
            wypisz();
            max_licznik=licznik;
            if (szachownica[i/MAX][i%MAX]==1){
                hetmany[j][0]=i/MAX;
                hetmany[j][1]=i%MAX;
                j++;
            }
        }
    }
}

void hetman(int w, int k, int h){
    zajmuj(w,k);
    szachownica[w][k]=1;
    if (h==MAX/2){
        zlicz();
    }else{
        for(int i=MAX*w+k+1;i<MAX*MAX;i++){
                if(szachownica[i/MAX][i%MAX]==0){
                    hetman(i/MAX,i%MAX,h+1);
                }
        }
        zwalniaj(w,k);
        szachownica[w][k]=0;
    }
}


int main(){
    for(int k=0;k<MAX;k++){
        czysc();
        hetman(0,k,1);
    }
    wypisz();
    cout << "Maksymalna liczba szachowanych pol przez " << MAX/2 << " hetmany to " << max_licznik;
return 0;
}
