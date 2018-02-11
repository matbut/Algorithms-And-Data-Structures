//PROGRAM WIEZE HANOI
#include <iostream>

using namespace std;

struct element{
    string zn;
    int ile;
};

void pal(element tab[], string s,int MAX);
void genpal(element tab[],int MAX);

int main(){
    int MAX;
    cout << "Podaj ile znakow palindromujesz: ";
    cin >> MAX;
    element tab[MAX];
    for(int i=0;i<MAX;i++){
        cout << "Podaj " << i+1 << " znak: ";
        cin >> tab[i].zn;
        cout << "    Podaj ile razy wystepuje: ";
        cin >> tab[i].ile;

    }
    genpal(tab,MAX);
    return 0;
}

void pal(element tab[], string s,int MAX){
    cout << s << endl;
    for(int i=0;i<MAX;i++){
        if(tab[i].ile>1){
            tab[i].ile-=2;
            pal(tab,tab[i].zn+s+tab[i].zn,MAX);
            tab[i].ile+=2;
        }
    }


}
void genpal(element tab[],int MAX){
    pal(tab,"",MAX);
    for(int i=0;i<MAX;i++){
        tab[i].ile-=1;
        pal(tab,tab[i].zn,MAX);
        tab[i].ile+=1;
    }
}
