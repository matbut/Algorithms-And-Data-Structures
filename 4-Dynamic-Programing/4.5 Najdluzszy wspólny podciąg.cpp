#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int N=10;
const int M=5;
const int W=5;
const int R=15;

void GenTab(int t[],int n);

int lcs(int A[],int n,int B[],int m);

int main(){
    srand(time(0));
    int A[N];
    GenTab(A,N);
    int B[M];
    GenTab(B,M);

    int x=lcs(A,N,B,M);
    cout << endl << "Najdluzszy wspolny podciag ma " << x << " elementow" << endl;
    return 0;
}
int lcs(int A[],int n,int B[],int m){
    int F[n+1][m+1];    // pole F[i][j] przechowuje dlugosc najdluzszego wspólnego ciagu do i-tego elementu w ciagu A i j-tego elementu w ciagu B
    for(int i=0;i<=n;i++)
        F[i][0]=0;
    for(int i=0;i<=m;i++)
        F[0][i]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(A[i-1]==B[j-1])
                F[i][j]=F[i-1][j-1]+1;
            else
                if(F[i-1][j]>F[i][j-1])
                    F[i][j]=F[i-1][j];
                else
                    F[i][j]=F[i][j-1];

    int i=0;
    cout << endl << "Najdluzszy wspolny podciag sklada sie z: ";
    while(i!=n){
        if(F[i+1][m]>F[i][m])
            cout << A[i] <<  " ";
        i++;
    }
    /*
    i=0;
    cout << endl << "Najdluzszy wspolny podciag sklada sie z: ";
    while(i!=m){
        if(F[n][i+1]>F[n][i])
            cout << B[i] <<  " ";
        i++;
    }
    */
    return F[n][m];
}

void GenTab(int t[],int n){
    int x=rand()%W;
    for(int i=0;i<n;i++){
        t[i]=x+rand()%R;
        cout.width(2);
        cout << t[i] << " ";
    }
    cout << endl;
}




