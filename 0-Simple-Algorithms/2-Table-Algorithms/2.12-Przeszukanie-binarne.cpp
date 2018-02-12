#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
const int MAX=9;

int bin(int t[],int a, int b, int x){
    if(a==b) {
        if (x==t[a]) return a;
            else
        return -1;
    } else
    if (x>t[(a+b)/2]){
        return bin(t,1+(a+b)/2,b,x);
    } else{
        return bin(t,a,(a+b)/2,x);
    }
}

void tablica(int tab[]){
    srand(time(0));
    tab[0]=rand()%10+1;
    cout << tab[0] << " ";
    for(int i=1;i<MAX;i++){
        tab[i]=tab[i-1]+rand()%10+1;
        cout << tab[i] << " ";
    }
}
int main(){
    int tab[MAX],s;
    tablica(tab);
    int x;
    cout << endl << "Podaj szukana liczbe: ";
    cin >> x;
    cout << x << " znajduje sie w tablicy pod indeksem " << bin(tab,0,MAX-1,x);

    return 0;
}
