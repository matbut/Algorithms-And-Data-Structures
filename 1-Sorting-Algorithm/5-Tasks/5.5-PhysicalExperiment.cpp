#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
const int N=20;
const int W=1000000;
const int R=10;

int main(){

    bool val[W];
    for(int i=0;i<W;i++) val[i]=false;
    int data[N];
    srand(time(0));


    int x=rand()%W;
    for(int i=0;i<N;i++){
        data[i]=x+rand()%R;
        cout << data[i] << endl;
    }

    int licznik=0;
    for(int i=0;i<N;i++){
        if(!val[data[i]]){
            licznik++;
            val[data[i]]=true;
        }
    }
    for(int i=0;i<N;i++){
        val[data[i]]=false;
    }

    cout << "Dane zawieraja " << licznik << " roznych wartosci";

    return 0;
}


