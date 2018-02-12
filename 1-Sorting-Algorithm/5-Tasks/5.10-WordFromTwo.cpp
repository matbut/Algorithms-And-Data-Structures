#include <iostream>
#include <string>
using namespace std;
const int N=20;
const int M=26;

int IleZnak(string a){
    int i=0;
    while(a[i]!='\0') i++;
    return i;
}

bool Possible(string a,string b,string c);

int main(){
    string a,b,c;
    cout << "Podaj napis:";
    cin >> a;
    cout << "Podaj napis:";
    cin >> b;
    cout << "Podaj napis:";
    cin >> c;

    if (Possible(a,b,c)){
        cout << "Da sie";
    }else{
        cout << "Nie da sie";
    }
    return 0;
}

bool Possible(string a,string b,string c){

    int ile[M];
    for(int i=0;i<M;i++){
        ile[i]=0;
    }
    for(int i=0;i<IleZnak(a);i++){
        ile[(int)a[i]-'a']++;
    }
    for(int i=0;i<IleZnak(b);i++){
        ile[(int)b[i]-'a']++;
    }
    for(int i=0;i<IleZnak(c);i++){
        ile[(int)c[i]-'a']--;
    }
    for(int i=0;i<M;i++){
        if(ile[i]<0) return false;
    }
    return true;

}

