#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
const int N=17;

int main(){
    int data[N];

    srand(time(0));
    int x=rand()%(N*(N-1));
    for(int i=0;i<N;i++){
        data[i]=x+rand()%N;
        cout << data[i] << ' ';
    }
    cout << endl;

    int kopia[N];
    int ile[N];

    for(int i=0;i<N;i++){
        ile[i]=0;
    }
    for(int i=0;i<N;i++){
        ile[data[i]%N]++;
    }
    for(int i=1;i<N;i++){
        ile[i]+=ile[i-1];
    }
    for(int i=N-1;i>=0;i--){
        kopia[ile[data[i]%N]-1]=data[i];
        ile[data[i]%N]--;
    }
    for(int i=0;i<N;i++){
        cout << kopia[i] << ' ';
    }
    cout << endl;

    for(int i=0;i<N;i++){
        ile[i]=0;
    }
    for(int i=0;i<N;i++){
        ile[kopia[i]/N]++;
    }
    for(int i=1;i<N;i++){
        ile[i]+=ile[i-1];
    }
    for(int i=N-1;i>=0;i--){
        data[ile[kopia[i]/N]-1]=kopia[i];
        ile[kopia[i]/N]--;
    }
    for(int i=0;i<N;i++){
        cout << data[i] << ' ';
    }
    cout << endl;

    cout << endl;
    return 0;
}


