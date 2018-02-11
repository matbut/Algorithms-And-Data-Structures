#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
const int UZYTKOWY=0;
const int NIEUZYTKOWY=1;
const int COLOR_UZYTKOWY=102;
const int COLOR_NIEUZYTKOWY=136;
const int COLOR_NORMAL=7;
const int COLOR_DZIALKA=238;

using namespace std;

struct dzialka{
    int x1,y1,x2,y2;
};
int** Init(int n);
void Print(int**t,int n);
int czy_uprawne(int**t,int n,dzialka d);
int max_pole(int**t,int n,dzialka &d);
int wyznacz_dzialke(int**t,int n,dzialka &d);
void Print_dzialke(int**t,int n,dzialka d);
int random();

void Color(int c);
void PrintColor();

int main(){
    srand(time(0));
    int n;
    cout << "Podaj wymiary pola:";
    cin >> n;
    int**t;
    t=Init(n);//inicjalizacja tablicy
    Print(t,n);
    dzialka d;
    cout << "Pole najwiekszej uzytkowej dzialki to :" << wyznacz_dzialke(t,n,d);
    Print_dzialke(t,n,d);

}
int** Init(int n){
    cout << "Podaj parametry pola:\n";
    int**t;
    t=(int**)calloc(n,sizeof(int*));
    for(int i=0;i<n;i++)
        t[i]=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n*n;i++){
        t[i/n][i%n]=random();
    }
    return t;
}
int random(){
    return (rand()%3)%2;
}
void Print(int**t,int n){
    cout << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(t[i][j]==UZYTKOWY)
                Color(COLOR_UZYTKOWY);
            else
                Color(COLOR_NIEUZYTKOWY);
            cout << "  ";
        }
        Color(COLOR_NORMAL);
        cout << endl;
    }
}
void Print_dzialke(int**t,int n,dzialka d){
    cout << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i>=d.x1 and i<=d.x2)and(j>=d.y1 and j<=d.y2))
                Color(COLOR_DZIALKA);
            else
            if(t[i][j]==UZYTKOWY)
                Color(COLOR_UZYTKOWY);
            else
                Color(COLOR_NIEUZYTKOWY);
            cout << "  ";
        }
        Color(COLOR_NORMAL);
        cout << endl;
    }
}
int czy_uprawne(int**t,int n,dzialka d){
    for(int i=d.x1;i<=d.x2;i++)
        for(int j=d.y1;j<=d.y2;j++)
            if(t[i][j]!=UZYTKOWY)
                return false;
    return true;
}
int max_pole(int**t,int n,dzialka &d){
    int max_p=1;
    dzialka max_d;
    for(d.x2=d.x1;d.x2<n;d.x2++)
        for(d.y2=d.y1;d.y2<n;d.y2++){
            if(czy_uprawne(t,n,d)){
                max_p=(d.x2-d.x1+1)*(d.y2-d.y1+1);
                max_d=d;
            }
        }
    d=max_d;

    return max_p;
}
int wyznacz_dzialke(int**t,int n,dzialka &d){
    int max_p=0;
    dzialka max_d;
    for(int i=0;i<n*n;i++){
        if(t[i/n][i%n]==UZYTKOWY){
            d.x1=i/n;
            d.y1=i%n;
            int tmp=max_pole(t,n,d);
            if(tmp>max_p){
                max_p=tmp;
                max_d=d;
            }
        }
    }
    d=max_d;
    return max_p;
}
void Color(int c) {
     //7 bialoszary 8 szary 15bialy 14 zolty
     HANDLE uchwyt;
     uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(uchwyt,c);
}
void PrintColor(){
    for(int i=0;i<256;i++){
        Color(i);
        cout << i << endl;
    }
}
