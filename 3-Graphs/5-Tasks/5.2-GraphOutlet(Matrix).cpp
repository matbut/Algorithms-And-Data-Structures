#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
const int N=6;
const int ACTIVE=14;
const int VISITED=8; //153; //mielizna
const int NORMAL=7;

using namespace std;

void Color(int c);
void PrintColor();

void PrintGraph(int graph[N][N]);

bool ujscie(int graph[N][N]);

int main(){
    int graph_skier[N][N]={
        {0,0,0,1,0,1}, //A
        {0,0,1,1,0,0}, //B
        {0,0,0,1,0,0}, //C
        {0,0,0,1,0,0}, //D
        {0,1,1,1,0,0}, //E
        {0,0,0,1,0,0}, //F
    };
    PrintGraph(graph_skier);
    if(ujscie(graph_skier))
        cout << "Graf ma ujscie.";
    else
        cout << "Graf nie ma ujscia.";
    return 0;
}

bool ujscie(int graph[N][N]){
    bool in=false;
    bool out=false;
    for(int i=0;i<N;i++){
        if(!in){
            in=true;
            for(int j=0;j<N and in;j++){
                if(i!=j and graph[j][i]!=1)
                    in=false;
            }
        }
        if(!out){
            out=true;
            for(int j=0;j<N and out;j++){
                if(i!=j and graph[i][j]!=0)
                    out=false;
            }
        }
    }
    return (in and out);
}

void PrintGraph(int graph[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(graph[i][j]==0)
                Color(VISITED);
            else
                Color(NORMAL);
            cout << " " << graph[i][j];
        }
        Color(NORMAL);
        cout << endl;
    }
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


