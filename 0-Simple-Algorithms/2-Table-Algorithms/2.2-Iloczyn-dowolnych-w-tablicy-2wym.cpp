#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
const int MAX1=2;
const int MAX2=4;


int main(){
    int tab[MAX1][MAX2],a;
    srand(time(0));
    for(int i=0;i<MAX1*MAX2;i++){
        tab[i/MAX2][i%MAX2]=rand()%10;
        cout << tab[i/MAX2][i%MAX2] << " ";
        if ((i+1)%MAX2==0) cout << endl;
    }
    cout << "Podaj liczbe: ";
    cin >> a;
    for(int i=0;i<MAX1*MAX2-1;i++){
        for(int j=i+1;j<MAX1*MAX2;j++){
            if(tab[i/MAX2][i%MAX2]*tab[j/MAX2][j%MAX2]==a){
                cout << tab[i/MAX2][i%MAX2] << "*" << tab[j/MAX2][j%MAX2] << "=" << a << endl;
            }
        }
    }



    return 0;
}
