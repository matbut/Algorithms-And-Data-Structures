#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
const int INF=INT_MAX;

using namespace std;

struct matrix{
    string name;
    int cols;
    int rows;
};

matrix*GenMatrixTab(int &n);
void PrintMatrix(matrix*M,int n);
int MulMatrixOrder(matrix*M,int n);
int MulMatrix(matrix*M,int**F,int p,int k);

int Min(int a,int b){
    if(a<=b)
        return a;
    else
        return b;
}

int main(){
    int n;
    matrix*M=GenMatrixTab(n);
    PrintMatrix(M,n);
    cout << "Do wymnorzenia tych macierzy potrzeba " << MulMatrixOrder(M,n) << " mnozen"<< endl;
    return 0;
}
int MulMatrixOrder(matrix*M,int n){
    int*order=new int[n];
    int**F=new int*[n];
    for(int i=0;i<n;i++){
        F[i]=new int[n];
        for(int j=0;j<n;j++)
            F[i][j]=-1;
    }
    // ilosc mnozen macierzy z zakresu od [i,j]
    // F[i][i]=0;
    // F[i][j]=Min (F[i][k] + F[k+1][j] + koszt M[k]*M[k+1])

    for(int i=0;i<n;i++){
        F[i][i]=0;
    }
    return MulMatrix(M,F,0,n-1);
}
int MulMatrix(matrix*M,int**F,int p,int k){
    if(F[p][k]>=0)
        return F[p][k];

    F[p][k]=INF;
    for(int i=p;i<k;i++){
        if(F[p][k]>MulMatrix(M,F,p,i)+MulMatrix(M,F,i+1,k)+M[p].rows*M[i].cols*M[k].cols){
            F[p][k]=MulMatrix(M,F,p,i)+MulMatrix(M,F,i+1,k)+M[p].rows*M[i].cols*M[k].cols;
        }
    }
    cout << "Do wymnorzenia macierzy od " << p << " do " << k << " potrzeba " << F[p][k] << " mnozen"<< endl;
    return F[p][k];
}
matrix*GenMatrixTab(int &n){
    n=6;
    int tab[2][n]={
    {30,35,15,5 ,10,20},
    {35,15,5 ,10,20,25}
    };
    matrix*M=new matrix[n];
    for(int i=0;i<n;i++){
        M[i].rows=tab[0][i];
        M[i].cols=tab[1][i];
        M[i].name=(char)(i+'A');
    }
    return M;
}
void PrintMatrix(matrix*M,int n){
    for(int i=0;i<n;i++)
        cout << "Macierz " << M[i].name << " ma " << M[i].rows << " wierszy i " << M[i].cols << " kolumn" << endl;
}


