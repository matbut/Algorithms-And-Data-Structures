#include <iostream>
#include <string>

const int N=5;
using namespace std;

struct pole{
    int val;
    bool calculated;
};
pole A[N][N];

int Advantage(int i,int j,int C[N]){
    if (A[i][j].calculated)
        return A[i][j].val;

    if(i==j){
        A[i][i].val=C[i];
        A[i][i].calculated=true;
        return A[i][i].val;
    }

    if(Advantage(i+1,j,C)<Advantage(i,j-1,C))
        A[i][j].val=-Advantage(i+1,j,C)+C[i];
    else
        A[i][j].val=-Advantage(i,j-1,C)+C[j];
    A[i][j].calculated=true;
    return A[i][j].val;
}
void Init(){
    for(int i=0;i<N*N;i++){
        A[i/N][i%N].calculated=false;
    }
}
int main(){
    int Cake[N]={1,7,2,8,3};
    for(int i=0;i<N;i++)
        cout << Cake[i] << " ";
    cout << endl;
    Init();

    int sum=0;
    for(int i=0;i<N;i++)
        sum+=Cake[i];

    cout << "Ala zje " <<  (sum+Advantage(0,N-1,Cake))/2 << " wisieniek" << endl;
    return 0;
}


