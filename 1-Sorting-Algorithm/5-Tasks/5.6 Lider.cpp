#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
const int N=6;
const int W=100;
const int R=2;

void GenTab(int tab[]);
int Lider(int tab[]);

int main(){
    int t[N];
    GenTab(t);
    int lider = Lider(t);
    if(lider<0) cout << "Nie ma lidera";
    else cout << "Lider to: " << lider;
    return 0;
}

void GenTab(int tab[]){
    srand(time(0));
    int x=rand()%W;
    for(int i=0;i<N;i++){
        tab[i]=x+rand()%R;
        cout << tab[i] << ' ';
    }
    cout << endl;
}

int Lider(int tab[]){
    int lider=tab[0];
    int ile=1;
    for(int i=1;i<N;i++){
        if(ile==0){
            lider=tab[i];
            ile=1;
        }else
            if(tab[i]==lider){
                ile++;
            }else{
                ile--;
            }
    }
    ile=0;
    for (int i=0;i<N;i++){
        if (tab[i]==lider)
            ile++;
    }
    if (ile>N/2)
        return lider;
    else
        return -1;
}
