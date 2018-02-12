#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
const int MAX1=3;
const int MAX2=5;
const int MAX3=MAX1+MAX2-2;
struct element{
    int suma;
    bool kier[MAX3]; //true prawo, false w dol
};
element najwiekszy;

void generuj(int tab[MAX1][MAX2]);
void drukuj(int tab[MAX1][MAX2]);
void drukujkolorowo(int tab[MAX1][MAX2]);
void sciezka(int tab[MAX1][MAX2],int x,int y,element &biez);
void gensciezka(int tab[MAX1][MAX2]);
void drukujsciezke(element jakis);
void kolor(int c);

int main(){
    int tab[MAX1][MAX2]={
    {1,2,1,1,1},
    {1,2,2,1,1},
    {1,1,2,2,2}
    };
    generuj(tab);
    drukuj(tab);
    gensciezka(tab);
    cout << "max suma: " << najwiekszy.suma <<  endl;
    drukujsciezke(najwiekszy);
    drukujkolorowo(tab);
    return 0;
}

void generuj(int tab[MAX1][MAX2]){
    srand(time(0));
    for(int i=0;i<MAX1*MAX2;i++){
        tab[i/MAX2][i%MAX2]=rand()%20;
    }
}
void drukujkolorowo(int tab[MAX1][MAX2]){
    int j=0;
    int kj=0;
    kolor(14);
    for(int i=0;i<MAX1*MAX2;i++){
        if(i==j){
            kolor(14);
            if(najwiekszy.kier[kj]){
                j++;
            } else {
                j+=MAX2;
            }
            kj++;
        }
        cout.width(2);
        cout << tab[i/MAX2][i%MAX2] << " ";
        kolor(7);
        if((i+1)%MAX2==0) cout << endl;
    }
}
void drukuj(int tab[MAX1][MAX2]){
    for(int i=0;i<MAX1*MAX2;i++){
        cout.width(2);
        cout << tab[i/MAX2][i%MAX2] << " ";
        if((i+1)%MAX2==0) cout << endl;
    }
}

void drukujsciezke(element jakis){
    for(int i=0;i<MAX3;i++){
        if (jakis.kier[i]) cout << "- w prawo ";
        else{
            cout << "- w dol ";
        }
    }
    cout << endl;
}

void gensciezka(int tab[MAX1][MAX2]){
    element biez;
    biez.suma=0;
    sciezka(tab,0,0,biez);
}

void sciezka(int tab[MAX1][MAX2],int x,int y,element &biez){
    biez.suma+=tab[x][y];
    if (x==MAX1-1 && y==MAX2-1){
        if(biez.suma>najwiekszy.suma) najwiekszy=biez;
        // cout << "suma: " << biez.suma <<  endl;
        //drukujsciezke(biez);
    }
    if (x<MAX1-1){
        biez.kier[x+y]=false;
        sciezka(tab,x+1,y,biez);
    }
    if (y<MAX2-1){
        biez.kier[x+y]=true;
        sciezka(tab,x,y+1,biez);
    }
    biez.suma-=tab[x][y];
}

void kolor(int c) {
     //7 bialoszary 8 szary 15bialy 14 zolty
     HANDLE uchwyt;
     uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(uchwyt,c);
}
