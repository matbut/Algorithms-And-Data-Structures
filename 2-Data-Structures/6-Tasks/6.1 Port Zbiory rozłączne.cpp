#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
const int MAXDEPTH=8;
const int SHALLOW=145; //153; //mielizna
const int DEEP=19; //17;
const int NORMAL=7;

using namespace std;

struct SetNode{
    int val;
    SetNode*parent;
    int rank;
};

SetNode* FindSet(SetNode*x);
void MakeSet(SetNode*x);
void Union(SetNode*x,SetNode*y);

SetNode***GenDepth(int n,int m);
void PrintColorBey(SetNode***Bey,int n,int m,int ship);
void Color(int c);
bool TrailToHarbor(SetNode***Bey,int n,int m,int ship);

int main(){
    srand(time(0));
    int n,m;
    cout << "Podaj wymiary zatoki:" << endl;
    cout << "wysokosc:";
    cin >> n;
    cout << "szerokosc:";
    cin >> m;
    SetNode***Bey=GenDepth(n,m);

    int ship;
    cout << "Podaj zanuzenie statku:";
    cin >> ship;

    PrintColorBey(Bey,n,m,ship);

    if(TrailToHarbor(Bey,n,m,ship))
        cout << "Statek dotoral do portu" << endl;
    else
        cout << "Statek osiadl na mieliznie..." << endl;
    return 0;
}
bool TrailToHarbor(SetNode***Bey,int n,int m,int ship){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(Bey[i][j]->val>=ship){
                if(i+1<n and Bey[i+1][j]->val>=ship)
                    Union(Bey[i+1][j],Bey[i][j]);
                if(j+1<m and Bey[i][j+1]->val>=ship)
                    Union(Bey[i][j+1],Bey[i][j]);
                if(i-1>=0 and Bey[i-1][j]->val>=ship)
                    Union(Bey[i-1][j],Bey[i][j]);
                if(j-1>=0 and Bey[i][j-1]->val>=ship)
                    Union(Bey[i][j-1],Bey[i][j]);
            }
    return (FindSet(Bey[0][0])==FindSet(Bey[n-1][m-1]));
}
void MakeSet(SetNode*x){
    x->parent=x;
    x->rank=0;
}
SetNode* FindSet(SetNode*x){
    //cout << " parent " << x->val << " to ";
    if(x!=x->parent)
        x->parent=FindSet(x->parent);
    return x->parent;
}
void Union(SetNode*x,SetNode*y){
    //cout << "Union: " << x->val << ' ' << y->val << endl;
    SetNode*s1=FindSet(x);
    SetNode*s2=FindSet(y);
    if(s1==s2)
        return;
    if(s1->rank < s2->rank){
        s1->parent=s2;
        //cout << s1->val << " parent na " << s1->parent->val << endl;
    }else{
        s2->parent=s1;
        //cout << s2->val << " parent na " << s2->parent->val << endl;
        if(s1->rank==s2->rank)
            s1->rank++;
    }
}
void Init(SetNode*data[],int n){
    data[0]=new SetNode;
    data[0]->val=5;
    MakeSet(data[0]);
    for(int i=1;i<n;i++){
        data[i]=new SetNode;
        data[i]->val=data[i-1]->val+rand()%n+1;
        MakeSet(data[i]);
    }
}
SetNode***GenDepth(int n,int m){
    SetNode***Bey;
    Bey=(SetNode***)calloc(n,sizeof(SetNode**));
    for(int i=0;i<n;i++)
        Bey[i]=(SetNode**)calloc(m,sizeof(SetNode*));
    for(int i=0;i<n*m;i++){
        Bey[i/m][i%m]=new SetNode;
        Bey[i/m][i%m]->val=rand()%MAXDEPTH+1;
        MakeSet(Bey[i/m][i%m]);
    }
    Bey[0][0]->val=MAXDEPTH;
    Bey[n-1][m-1]->val=MAXDEPTH;
    return Bey;
}
void PrintColorBey(SetNode***Bey,int n,int m,int ship){
    system("cls");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Bey[i][j]->val<ship)
                Color(SHALLOW);
            else
                Color(DEEP);
            cout.width(2);
            cout << Bey[i][j]->val << ' ';
        }
        Color(NORMAL);
        cout << endl;
    }
    Sleep(100);
}
void Color(int c) {
     //7 bialoszary 8 szary 15bialy 14 zolty
     HANDLE uchwyt;
     uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(uchwyt,c);
}
void PrintColor(){
    for(int i=0;i<256;i++){
        Color(i);
        cout << i << endl;
    }
}
