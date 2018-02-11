#include <iostream>
#include <string>

const int R=3;
const int C=4;
using namespace std;

int Max(int a,int b){
    if(a>=b)
        return a;
    return b;
}

int main(){
    int board[R][C]={
        {0,1,0,1},
        {0,1,1,1},
        {1,0,0,0},
    };
    int F[R][C];
    F[0][0]=board[0][0];

    for(int i=1;i<R*C;i++){
        F[i/C][i%C]=0;
        if(i/C-1>=0)
            F[i/C][i%C]=F[i/C-1][i%C]+board[i/C][i%C];
        if(i%C-1>=0)
            F[i/C][i%C]=Max(F[i/C][i%C],F[i/C][i%C-1]+board[i/C][i%C]);
    }
    cout << "Najwiecej diamencikow: " << F[R-1][C-1] << endl << "Droga:";
    int i=R-1;
    int j=C-1;
    while(i!=0 or j!=0)
        if(!(i==0 and j>0) and ((i>0 and j==0) or F[i-1][j]>F[i][j-1])){
            cout << " gora ";
            i--;
        }else{
            cout << " lewo ";
            j--;
        }
    return 0;
}


