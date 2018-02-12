#include <iostream>
using namespace std;
const int N=100;
int F[N];

int fib(int n){
    if(n<=2)
        return 1;
    return fib(n-1)+fib(n-2);
}
int fib_dyn_tab(int n){
    int F[n+1];
    if(n<=2)
        return 1;
    F[1]=1;
    F[2]=1;
    for(int i=3;i<=n;i++)
        F[i]=F[i-1]+F[i-2];
    return F[n];
}
int fib_dyn(int n){
    if(n<=2)
        return 1;
    int F=1;
    int F1=1;
    int F2;
    for(int i=3;i<=n;i++){
        F2=F1;
        F1=F;
        F=F1+F2;
    }
    return F;
}
void init_fib_mem(){
    for(int i=3;i<N;i++)
        F[i]=-1;
    F[1]=1;
    F[2]=1;
}
int fib_memorize(int n){
    if(F[n]>=0)
        return F[n];
    F[n]=fib_memorize(n-1)+fib_memorize(n-2);
    return F[n];
}
int main(){
    int n=10;
    init_fib_mem();
    for(int i=0;i<n;i++)
        cout << fib(i) << " " << fib_dyn_tab(i) << " " << fib_dyn(i) << " " << fib_memorize(i) << endl;
    return 0;
}






