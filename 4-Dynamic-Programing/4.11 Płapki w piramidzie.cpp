#include <iostream>
#include <string>

const int N=7;
using namespace std;

int main(){
    int corridor[N]={1,1,0,1,0,0,1};

    int F[N];
    F[0]=1;

    for(int i=1;i<N;i++){
        F[i]=0;
        for(int k=1;k<=6;k++)
            if(corridor[i] and i>=k)
                F[i]+=F[i-k];
    }
    cout << F[N-1];
    return 0;
}


