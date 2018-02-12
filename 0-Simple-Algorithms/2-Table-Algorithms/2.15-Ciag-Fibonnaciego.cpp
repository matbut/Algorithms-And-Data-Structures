#include <iostream>
using namespace std;
const int MAX=30;
int tab[MAX];

int fib(int a)
{
    long long unsigned int koniec=0;
    for(int i=0;i<MAX-a;i++){
        cout << "   ";
    }
    cout << "Start " << a << " " << tab[a] << endl;

    if(a==1) koniec=1; else
    if(a==2) koniec=1;
    if(a>2) {
        if(tab[a-2]!=0){
            if (tab[a-1]!=0){
                koniec=tab[a-2]+tab[a-1];
            }else{
                koniec=fib(a-1)+tab[a-2];
            }
        }else{
            koniec=fib(a-1)+fib(a-2);
        }


    }

    for(int i=0;i<MAX-a;i++){
        cout << "   ";
    }
    tab[a]=koniec;
    cout << "Stop " << a << " " << tab[a] << endl;
    return koniec;
}

int main(){
    for(int i=2;i<MAX;i++){
    tab[i]=0;
    }
    cout << fib(MAX);
return 0;
}
