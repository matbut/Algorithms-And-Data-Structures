#include <iostream>
#include <string>
using namespace std;
const int N=20;
const int ASCI=97;
const int M=26;

bool Angram(string a,string b);
int IleZnak(string a){
    int i=0;
    while(a[i]!='\0') i++;
    return i;
}

int main(){
    string a,b;
    cout << "Podaj napis:";
    cin >> a;
    cout << "Podaj napis:";
    cin >> b;

    if(Angram(a,b)) cout << "To sa Angramy!";
    else cout << "To nie sa angramy!";

    return 0;
}

bool Angram(string a,string b){
    if(IleZnak(a)!=IleZnak(b)) return false;

    int ILE[M];
    int Max=IleZnak(a);

    for(int i=0;i<Max;i++) ILE[a[i]-ASCI]=0;
    for(int i=0;i<Max;i++) {
        ILE[a[i]-ASCI]++;
        ILE[b[i]-ASCI]--;
    }
    for(int i=0;i<Max;i++)
        if(ILE[a[i]-ASCI]!=0) return false;
    return true;
}
