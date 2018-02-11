#include <iostream>
using namespace std;
const int MAX=200;

int main(){
    bool liczba[MAX];
    liczba[0]=false;
    liczba[1]=false;
    for(int i=2;i<MAX;i++){
        liczba[i]=true;
    }
    for(int i=2;i*i<MAX;i++){
        if (liczba[i]){
            for(int j=i*i;j<MAX;j=j+i){
                liczba[j]=false;
            }
        }
    }
    for(int i=2;i<MAX;i++){
        if (liczba[i]){
                cout << i << " ";
        }
    }

    return 0;}
