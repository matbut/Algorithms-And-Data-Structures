#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
using namespace std;

const int MAX=8;
int szachownica[MAX][MAX];
bool znalazlem=false;

void kolor(int c) {
        //7 bialoszary 8 szary 15bialy 14 zolty
        HANDLE uchwyt;
        uchwyt=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(uchwyt,c);
}
void wypisz(){
    system("cls");
    for(int i=0;i<MAX*MAX;i++) {
        if(szachownica[i/MAX][i%MAX]==1) kolor(15); else kolor(8);
        cout << char(254) << " ";
        if((i+1)%MAX==0) cout << endl;
    }
    kolor(7);
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

bool hetman(int w, int k, int h){
    zajmuj(w,k);
    szachownica[w][k]=1;
    if (h==MAX){
        wypisz();
        znalazlem=true;
        return true;
    }
    for(int i=MAX*w+1+k+1;i<MAX*MAX;i++)
            if(szachownica[i/MAX][i%MAX]==0)
                if (hetman(i/MAX,i%MAX,h+1)) return true;

    zwalniaj(w,k);
    szachownica[w][k]=0;
    return false;
}

void czysc(){
    for(int i=0;i<MAX*MAX;i++)
            szachownica[i/MAX][i%MAX]=0;
}

int main(){
    for(int k=0;k<MAX &&!znalazlem;k++){
        czysc();
        if(hetman(0,k,1)) cout << "Da sie";
    }
    if (!znalazlem) cout << "Nie da sie";
    //if (hetman(0,0,1)) cout << "Da sie"; else cout << "Nie da sie";
return 0;
}
