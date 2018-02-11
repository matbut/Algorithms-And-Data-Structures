#include <iostream>

using namespace std;
const int N=10;

struct stos{
    int*tab;
    int top; // wskaxnik na wierzcholek
    int len; // zarezerwowana pamiec
};
stos Init();
bool IsEmpty(stos s);
void Push(stos &s,int n);
int Pop(stos &s);

int main(){
    stos s=Init();
    if (IsEmpty(s)) cout << "stos pusty" << endl;
    else cout << "stos pelny" << endl;
    Push(s,5);
    for(int i=0;i<20;i++)
        Push(s,5);
    cout << "Pojemnosc stosu: " << s.len << endl;
    for(int i=0;i<20;i++)
        Pop(s);
    cout << "Pojemnosc stosu: " << s.len << endl;
    if (IsEmpty(s)) cout << "stos pusty" << endl;
    else cout << "stos pelny" << endl;
    cout << Pop(s) << endl;
    if (IsEmpty(s)) cout << "stos pusty" << endl;
    else cout << "stos pelny" << endl;

    return 0;
}
stos Init(){
    stos s;
    s.tab=new int [N];
    s.top=-1;
    s.len=N;
    return s;
}
bool IsEmpty(stos s){
    return s.top==-1;
}
void Push(stos &s,int n){
    s.top++;
    s.tab[s.top]=n;
    if(s.top==s.len-1){
        int*tab=new int [2*s.len];
        for(int i=0;i<=s.top;i++)
            tab[i]=s.tab[i];
        delete [] s.tab;
        s.tab=tab;
        s.len=2*s.len;
    }
}
int Pop(stos &s){
    s.top--;
    if(s.top<=s.len/2 and s.top>=N){
        int*tab=new int [s.len/2];
        for(int i=0;i<=s.top;i++)
            tab[i]=s.tab[i];
        delete [] s.tab;
        s.tab=tab;
        s.len=s.len/2;
    }
    return s.tab[s.top+1];
}
