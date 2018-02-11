#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>

const int BLOCK_SIZE=3;
const int BLOCKS_NUM=6;
using namespace std;

struct tower{
    int*blocks;
    int num;
    int height;
};
void Color(int c) {
     //7 bialoszary 8 szary 15bialy 14 zolty
     HANDLE uchwyt;
     uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(uchwyt,c);
}
void Print(tower*t,int n){
    for(int i=0;i<n;i++){
        cout << "Child " << i << "  ";
        bool c=true;
        for(int j=0;j<t[i].num;j++){
            if (c) Color(8); else Color(15);
            c=!c;
            for(int k=0;k<t[i].blocks[j];k++)
                cout << char(219) << char(219);
        }
        Color(7);
        cout << endl << endl;
    }
}
tower* GenChild(int n){
    tower*t=new tower[n];
    for(int i=0;i<n;i++){
        t[i].num=rand()%BLOCKS_NUM+1;
        t[i].blocks=new int[BLOCKS_NUM+1];
        t[i].height=0;
        for(int j=0;j<t[i].num;j++){
            t[i].blocks[j]=rand()%BLOCK_SIZE+1;
            t[i].height+=t[i].blocks[j];
        }
    }
    return t;
}
tower GenTower(tower*t,int n){
    tower max_tower;
    max_tower.blocks=new int[(BLOCKS_NUM+1)*n];
    max_tower.num=0;
    max_tower.height=0;

    for(int level=1;level<(BLOCK_SIZE+1)*(BLOCKS_NUM+1);level++){
        tower biez_tower;
        biez_tower.blocks=new int[(BLOCKS_NUM+1)*n];
        biez_tower.num=0;
        biez_tower.height=0;
        // KROK 1
        for(int i=0;i<n;i++){
            cout << "LOL";
            while(t[i].height>=level){

                biez_tower.blocks[biez_tower.num]=t[i].blocks[t[i].num-1];
                t[i].blocks[t[i].num-1]=0;
                t[i].num--;
                biez_tower.num++;
            }
        }
        // KROK 2




        if(biez_tower.num<max_tower.num){
            max_tower=biez_tower;
        }
    }
    return max_tower;
}
int main(){
    srand(time(0));
    int n=10;
    tower*t=GenChild(n+1);
    Print(t,n);
    t[n]=GenTower(t,n);
    Print(t,n+1);
    return 0;
}

