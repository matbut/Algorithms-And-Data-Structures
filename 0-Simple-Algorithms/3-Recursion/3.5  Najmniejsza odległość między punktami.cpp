#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
const int MAX=2;

struct punkt{
    int x;
    int y;
};


void generuj(punkt tab[]){
    srand(time(0));
    for(int i=0;i<MAX;i++){
        tab[i].x=rand()%10;
        tab[i].y=rand()%10;
        cout << "(" << tab[i].x << "," << tab[i].y << ")" << endl;
    }
}

int dlugosc(punkt sr_1,punkt sr_2){
    return ((sr_1.x-sr_2.x)*(sr_1.x-sr_2.x)+(sr_1.y-sr_2.y)*(sr_1.y-sr_2.y));
}

void podzial(int i,punkt tab[],punkt sr_1, punkt sr_2,int &min_dl){
    if(i==MAX){
        int dl=dlugosc(sr_1,sr_2);
        if(dl>min_dl) min_dl=dl;
    }else{
        punkt sr_tmp;
        sr_tmp.x=(sr_1.x+tab[i].x)/2;
        sr_tmp.y=(sr_1.x+tab[i].y)/2;
        podzial(i+1,tab,sr_tmp,sr_2,min_dl);
        sr_tmp.x=(sr_2.y+tab[i].x)/2;
        sr_tmp.y=(sr_2.y+tab[i].y)/2;
        podzial(i+1,tab,sr_1,sr_tmp,min_dl);
    }
}

int min_dlugosc(punkt tab[]){
    int min_dl=0;
    punkt sr_tmp;
    sr_tmp.x=0;
    sr_tmp.y=0;
    podzial(0,tab,sr_tmp,sr_tmp,min_dl);
    return min_dl*2;
}

int main(){
    punkt tab[MAX];
    generuj(tab);
    cout << "Najmniejsza dlugosc to:" << min_dlugosc(tab);
}
