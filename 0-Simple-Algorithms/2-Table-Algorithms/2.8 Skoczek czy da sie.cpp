#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;
const int MAX=4;
int szachownica[MAX][MAX];

void drukuj(){
    for(int i=0;i<MAX*MAX;i++){
        cout.width(2);
        cout << szachownica[i/MAX][i%MAX] << " ";
        if ((i+1)%MAX==0) cout << endl;
    }
    cout << endl;
};

bool mozna(int w,int k,int i, int &w2, int &k2){
    int wiersz[8] {-2,-1,1,2, 2, 1,-1,-2};
    int kolumna[8]{ 1, 2,2,1,-1,-2,-2,-1};
    w2=w+wiersz[i];
    k2=k+kolumna[i];
    return w2>=0 && k2>=0 && w2<MAX && k2<MAX && szachownica[w2][k2]==0;
};

bool skoczek(int w,int k,int n){
    szachownica[w][k]=n+1;
    if(n==MAX*MAX-1){
        drukuj();
        return true;
    }
    int w2=w,k2=k;
    for(int i=0;i<8;i++){
        if (mozna(w,k,i,w2,k2)){
            if (skoczek(w2,k2,n+1)) return true;
        }
    }
    szachownica[w][k]=0;
    return false;
};

int main(){
    for(int i=0;i<MAX*MAX;i++){
        szachownica[i/MAX][i%MAX]=0;
    }
    if (skoczek(0,0,0)){
        cout << "Da sie";
    }else{
    cout << "Nie da sie";
    }
    return 0;
}
