#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
const int n=10;
const int ACTIVE=14;
const int VISITED=8; //153; //mielizna
const int NORMAL=7;

using namespace std;

int* guards(bool G[n][n], int n);
void put_guard(bool**watched,int n,int w,int *result,int &guard_number);
void PrintGraph(bool graph[n][n]);
int*guards_one_system(bool G[n][n],int n,int &guard_number);

void Color(int c);

void Swap(int &x,int &y){
    int tmp=x; x=y; y=tmp;
}

int main(){
    srand(time(0));
    bool graph[n][n]={
    //   A B C D E F G H I J
        {0,1,1,0,0,0,0,0,0,0}, //A
        {1,0,0,1,0,0,0,1,0,0}, //B
        {1,0,0,1,1,0,0,0,0,0}, //C
        {0,1,1,0,0,1,0,0,0,0}, //D
        {0,0,1,0,0,1,0,0,0,0}, //E
        {0,0,0,1,1,0,0,0,1,1}, //F
        {0,0,0,0,0,0,0,1,1,1}, //G
        {0,1,0,0,0,0,1,0,1,0}, //H
        {0,0,0,0,0,1,1,1,0,0}, //I
        {0,0,0,0,0,1,1,0,0,0}, //J
    };

    PrintGraph(graph);
    int* wariors=guards(graph,n);
    cout << "Rozmieszczenie kamer: ";
    for(int i=0;i<n;i++)
        if(wariors[i]>=0)
            cout << char(65+wariors[i]) << " ";

    return 0;
}
bool**watched_init(bool G[n][n],int n){
    bool**watched=new bool*[n];
    for(int i=0;i<n;i++){
        watched[i]=new bool[n];
        for(int j=0;j<n;j++)
            watched[i][j]=G[i][j];
    }
    return watched;
}
int*index_init(int n){
    int*index=new int[n];
    for(int i=0;i<n;i++){
        index[i]=i;
    }
    for(int i=0;i<n;i++)
        Swap(index[i],index[rand()%n]);
    return index;
}
int*result_init(int n){
    int*result=new int[n];
    for(int i=0;i<n;i++)
        result[i]=-1;
    return result;
}
int*guards_one_system(bool G[n][n],int n,int &guard_number){
    int*result=result_init(n);
    bool**watched=watched_init(G,n);
    int*index=index_init(n);            // losowa zamiana indeksow
    guard_number=0;

    for(int i=0;i<n;i++){
        int j=0;
        while(j<n and !watched[index[i]][index[j]])
            j++;
        if(j<n){
            put_guard(watched,n,index[i],result,guard_number);
            int k=0;
            while(k<n and !watched[index[j]][k])
                k++;
            if(k<n)
                put_guard(watched,n,index[j],result,guard_number);
        }
    }
    //for(int i=0;i<n;i++)
    //    if(result[i]>=0)
            //cout << char(65+result[i]) << " ";
    //cout << endl;
    for(int i=0;i<n;i++)
        delete [] watched[i];
    delete [] watched;
    delete [] index;
    return result;
}
int* guards(bool G[n][n],int n){
    int max_guard_number;
    int*max_result=guards_one_system(G,n,max_guard_number);

    for(int i=0;i<n*n*n;i++){
        int guard_number;
        int*result=guards_one_system(G,n,guard_number);

        if(guard_number<max_guard_number){
            max_guard_number=guard_number;
            delete [] max_result;
            max_result=result;
        }else
            delete [] result;
    }
    return max_result;
}
void put_guard(bool**watched,int n,int w,int *result,int &guard_number){
    for(int i=0;i<n;i++){
        watched[w][i]=false;
        watched[i][w]=false;
    }    result[guard_number]=w;
    guard_number++;
}
void PrintGraph(bool graph[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j])
                Color(NORMAL);
            else
                Color(VISITED);
            cout << " " << (int)graph[i][j];
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
