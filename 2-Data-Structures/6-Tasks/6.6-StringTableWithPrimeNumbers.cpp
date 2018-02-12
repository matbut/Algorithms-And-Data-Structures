#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
const int N=10;
using namespace std;

struct Set{
    string liczba;
};
string IntToString(int a);
int Hash(string x);

int main(){
    int Data[N]={641,193,859,997,521,601,659,743,941,701};
    string A[N];
    for(int i=0;i<N;i++){
        A[i]=IntToString(Data[i]);
        cout << A[i] << ' ' << Hash(A[i]) << endl;

    }
    return 0;
}
int Hash(string x){
    int i=0;
    int skladnik=1;
    int suma=0;
    while(x[i]!='\0'){
        if(x[i]=='1'){
            suma+=skladnik;
        }
        skladnik*=2;
        i++;
    }
    return suma;
}
string IntToString(int a){
    int ka=a;
    int licznik=0;
    while(ka>0){
        ka=ka/2;
        licznik++;
    }
    char* x=new char[licznik+1];
    x[licznik]='\0';
    for(licznik=licznik-1;licznik>=0;--licznik){
        if(a%2==0)
            x[licznik]='0';
        else
            x[licznik]='1';
        a=a/2;
    }
    return x;
}
