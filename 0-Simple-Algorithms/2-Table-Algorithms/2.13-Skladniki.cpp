#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
using namespace std;

void wypisz(int biez[],int MAX){
    cout << MAX << " = ";
    if (biez[0]!=0){
        cout << biez[0];
    }
    for(int i=1;i<MAX;i++){
         if (biez[i]!=0){
            cout << " + " << biez[i];
         }
    }
    cout << endl;
}

void skladniki(int i,int suma,int biez[],int MAX){
    if(MAX==suma){
        wypisz(biez,MAX);
    }else
    for(int j=MAX-suma;j>0;j--){
        if(j<=biez[i-1] || i==0) {
            biez[i]=j;
            skladniki(i+1,suma+biez[i],biez,MAX);
        }
    }
    biez[i]=0;
}

int main(){
    int MAX;
    cout << "Podaj liczbe: ";
    cin >> MAX;
    int tab[MAX];
    int biez[MAX];
    for(int i=0;i<MAX;i++){
         biez[i]=0;
    }
    skladniki(0,0,biez,MAX);
return 0;
}
