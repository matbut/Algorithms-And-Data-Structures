#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
const int MAX=10;

int main(){
    int tab[MAX],s;
    srand(time(0));
    for(int i=0;i<MAX;i++){
        tab[i]=rand()%10+1;
        cout << tab[i] << " ";
    }

    cout << "Podaj liczbe: ";
    cin >> s;
    for(int i=0;i<MAX-1;i++){
        if(s%tab[i]==0){
            for(int j=i+1;j<MAX;j++){
                if(tab[i]*tab[j]==s){
                    cout << tab[i] << "*" << tab[j] << "=" << s << endl;
                }
            }
        }
    }
    return 0;
	getc();
}
