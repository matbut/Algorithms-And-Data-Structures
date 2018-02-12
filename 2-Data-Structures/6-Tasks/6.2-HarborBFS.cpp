#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <queue>
#include <stack>
const int MAXDEPTH=8;
const int SHALLOW=145; //153; //mielizna
const int TEMPSHALLOW=158;
const int DEEP=19; //17;
const int TEMPDEEP=30;
const int FARWATER=177;
const int NORMAL=7;
int licznik;

using namespace std;

struct Pair{
    int x,y;
};

int**GenDepth(int n,int m);
void PrintColorTrail(int**Bey,int n,int m,Pair*trail,int ship);
void PrintColorBey(int**Bey,int n,int m,int ship,int x,int y);
void Color(int c);
void PrintColor();
Pair* TrailToHarbor(int**Bey,int n,int m,int ship);
Pair* TrailBack(Pair**trail,int n,int m);


int main(){
    int n,m;
    cout << "Podaj wymiary zatoki:" << endl;
    cout << "wysokosc:";
    cin >> n;
    cout << "szerokosc:";
    cin >> m;

    srand(time(0));
    int**Bey=GenDepth(n,m);

    int ship;
    cout << "Podaj zanuzenie statku:";
    cin >> ship;

    Pair*trail;
    trail=TrailToHarbor(Bey,n,m,ship);
    if(trail==NULL) cout <<"Statek osiadl na mieliznie...";
    else{
        cout << "Statek dotoral do portu po szlaku:";
        for(int i=0;i<licznik;i++){
            cout << '[' << trail[i].x << ',' << trail[i].y << "] -> ";
        }
        cout << "Tawerna!" << endl;
    }
    PrintColorTrail(Bey,n,m,trail,ship);
    return 0;
}
Pair* TrailToHarbor(int**Bey,int n,int m,int ship){
    queue < int > Q;

    Pair**trail;
    trail=(Pair**)calloc(n,sizeof(Pair*));
    for(int i=0;i<n;i++)
        trail[i]=(Pair*)calloc(m,sizeof(Pair));

    bool**visited;
    visited=(bool**)calloc(n,sizeof(bool*));
    for(int i=0;i<n;i++)
        visited[i]=(bool*)calloc(m,sizeof(bool));
    for(int i=0;i<n*m;i++)
        visited[i/m][i%m]=false;

    visited[0][0]=true;
    trail[0][0]={-1,-1};
    Q.push(0);
    Q.push(0);

    while(!Q.empty()){
        int x=Q.front(); Q.pop();
        int y=Q.front(); Q.pop();

        PrintColorBey(Bey,n,m,ship,x,y);
        if(x==n-1 and y==m-1)
            return TrailBack(trail,n,m);
        if(x<n-1 and !visited[x+1][y] and Bey[x+1][y]>=ship){
            Q.push(x+1);
            Q.push(y);
            visited[x+1][y]=true;
            trail[x+1][y]={x,y};
        }
        if(y<m-1 and !visited[x][y+1] and Bey[x][y+1]>=ship){
            Q.push(x);
            Q.push(y+1);
            visited[x][y+1]=true;
            trail[x][y+1]={x,y};
        }
        if(x>0 and !visited[x-1][y] and Bey[x-1][y]>=ship){
            Q.push(x-1);
            Q.push(y);
            visited[x-1][y]=true;
            trail[x-1][y]={x,y};
        }
        if(y>0 and !visited[x][y-1] and Bey[x][y-1]>=ship){
            Q.push(x);
            Q.push(y-1);
            visited[x][y-1]=true;
            trail[x][y-1]={x,y};
        }
    }
    return NULL;
}
Pair* TrailBack(Pair**trail,int n,int m){
    licznik=0;
    Pair w;
    w.x=n-1;
    w.y=m-1;
    while(w.x!=-1 and w.y!=-1){
        w=trail[w.x][w.y];
        licznik++;
    }
    Pair*way=new Pair[licznik];
    int i=licznik-1;
    w.x=n-1;
    w.y=m-1;
    while(w.x!=-1 and w.y!=-1){
        way[i]=w;
        w=trail[w.x][w.y];
        i--;
    }
    return way;
}
void PrintColorTrail(int**Bey,int n,int m,Pair*trail,int ship){
    system("cls");
    for(int i=0;i<licznik;i++)
        Bey[trail[i].x][trail[i].y]*=(-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Bey[i][j]<0){
                Color(FARWATER);
                Bey[i][j]*=(-1);
            }else
            if(Bey[i][j]<ship)
                Color(SHALLOW);
            else
                Color(DEEP);
            cout.width(2);
            cout << Bey[i][j] << ' ';
        }
        Color(NORMAL);
        cout << endl;
    }
}
void PrintColorBey(int**Bey,int n,int m,int ship,int x,int y){
    system("cls");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Bey[i][j]<ship){
                if(i==x and j==y)
                    Color(TEMPSHALLOW);
                else
                    Color(SHALLOW);
            }else
                if(i==x and j==y)
                    Color(TEMPDEEP);
                else
                    Color(DEEP);
            cout.width(2);
            cout << Bey[i][j] << ' ';
        }
        Color(NORMAL);
        cout << endl;
    }
    Sleep(100);
}
int**GenDepth(int n,int m){
    int**Bey;
    Bey=(int**)calloc(n,sizeof(int*));
    for(int i=0;i<n;i++)
        Bey[i]=(int*)calloc(m,sizeof(int));
    for(int i=0;i<n*m;i++)
        Bey[i/m][i%m]=rand()%MAXDEPTH+1;

    Bey[0][0]=MAXDEPTH;
    Bey[n-1][m-1]=MAXDEPTH;
    return Bey;
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


