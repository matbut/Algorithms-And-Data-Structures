#include <iostream>
#include <string>
using namespace std;

const int MAX=5;

void podzbiory(int j,char tab[],string s){
    if(j<=MAX){
        if(s!="") cout << s << endl;
        for (int i=j;i<MAX;i++){
            podzbiory(i+1,tab,s+tab[i]);
        }
    }
}

int main(){
    char tab[MAX]={'A','B','C','D','E'};
    podzbiory(0,tab,"");

}
