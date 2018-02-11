#include <iostream>

using namespace std;
struct ulamek{
    int licznik,mianownik;
};
void wczytaj(ulamek &u){
    cin >> u.licznik;
    cin >> u.mianownik;
};

void zliczdwojkipiatki(int kmianownik,int &dwojki,int &piatki){
    while (kmianownik%2==0){
        kmianownik=kmianownik/2;
        dwojki++;
    }
    while (kmianownik%5==0){
        kmianownik=kmianownik/5;
        piatki++;
    }
};
void wyswietl(ulamek u){
    int dwojki=0,piatki=0;
    zliczdwojkipiatki(u.mianownik,dwojki,piatki);

    cout << (u.licznik/u.mianownik);
    u.licznik=(u.licznik%u.mianownik)*10;
    cout << ".";
    for(int i=0;i<piatki || i<dwojki;i++){
        cout << (u.licznik/u.mianownik);
        u.licznik=(u.licznik%u.mianownik)*10;
    }
    if(u.licznik!=0){
        cout << "(";
        int reszta=u.licznik%u.mianownik*10;
        do {
            cout << (u.licznik/u.mianownik);
            u.licznik=(u.licznik%u.mianownik)*10;
        } while(reszta!=u.licznik%u.mianownik*10);

        cout << ")";
    }
};

int main(){
    ulamek a;
    wczytaj(a);
    wyswietl(a);
    return 0;
}
