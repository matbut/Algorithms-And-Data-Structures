#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

struct data{
    int key;
    string val;
};

const int N=47;
const int DELETED=-1;
const int EMPTY=0;
data Htab[N];

int HashMod(int key);
void Init();
void Print();
bool Insert(int key, string val);
string Search(int key);
bool Delete(int key);

int main(){
    Init();
    Print();
    int x;
    /*
    cout << "Podaj czego szukasz:";
    cin >> x;
    if(Search(x)!="")
        cout << "Element o indeksie " << x << " to " << Search(x) << endl;
    else
        cout << "Brak elementu o indeksie " << x << endl;

    data d;
    cout << "Podaj co wstawiasz:" << endl;
    cout << " klucz: ";
    cin >> d.key;
    cout << " warosc: ";
    cin >> d.val;
    if (Insert(d.key,d.val))
        cout << "Wstawianie sie powidolo. " << endl;
    else
        cout << "Tablica przepeniona!" << endl;
    Print();
    */
    cout << "Podaj co usuwasz:";
    cin >> x;
    if(Delete(x))
        cout << "Usuwanie sie powiodlo." << endl;
    else
        cout << "Brak elementu o indeksie " << x << endl;
    Print();
    cout << "Podaj czego szukasz:";
    cin >> x;
    if(Search(x)!="")
        cout << "Element o indeksie " << x << " to " << Search(x) << endl;
    else
        cout << "Brak elementu o indeksie " << x << endl;
    return 0;
}
int HashMod(int key){
    return key%N;
}
bool Insert(int key, string val){
    int index=HashMod(key);
    int licznik=0;
    while(licznik<N and Htab[(index+licznik)%N].key!=EMPTY and Htab[(index+licznik)%N].key!=DELETED){
        licznik++;
    }
    if(licznik!=N){
        Htab[(index+licznik)%N].key=key;
        Htab[(index+licznik)%N].val=val;
        return true;
    }else
        return false;
}
string Search(int key){
    int index=HashMod(key);
    int licznik=0;
    while(licznik<N and Htab[(index+licznik)%N].key!=EMPTY and Htab[(index+licznik)%N].key!=key){
        licznik++;
    }
    if(Htab[(index+licznik)%N].key==key){
        return Htab[(index+licznik)%N].val;
    }else{
        return "";
    }
}
bool Delete(int key){
    int index=HashMod(key);
    int licznik=0;
    while(licznik<N and Htab[(index+licznik)%N].key!=EMPTY and Htab[(index+licznik)%N].key!=key){
        licznik++;
    }
    if(Htab[(index+licznik)%N].key==key){
        Htab[(index+licznik)%N].key=DELETED;
        return true;
    }else{
        return false;
    }
}
void Init(){
    string Data[10]={"Ala","Ola","Ula","Ela","Ada","Ewa","Iga","Ida","Mia","Nel"};
    int Index[10]={3,17,211,319,429,531,637,47,94,141};

    for(int i=0;i<N;i++)
        Htab[i].key=0;
    data d;
    for(int i=0;i<10;i++)
        Insert(Index[i],Data[i]);
}
void Print(){
    for(int i=0;i<N;i++){
        if(Htab[i].key>EMPTY){
            if(Htab[i].key<100)
                cout << ' ';
            cout << ' ' << Htab[i].key << ' ';
            if(Htab[i].key<10)
                cout << ' ';
        }else
            if(Htab[i].key==DELETED)
                cout << "D";
            else
                cout << '*';

    }
    cout << endl;
    for(int i=0;i<N;i++){
        if(Htab[i].key>EMPTY)
            cout << ' ' << Htab[i].val << ' ';
        else
            cout << "*";
    }
    cout << endl;
}
