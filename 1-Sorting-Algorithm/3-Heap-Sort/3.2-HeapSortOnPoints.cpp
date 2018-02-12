#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int N=10;
const int R=20;

struct Point {
    double x,y;
};
int Left(int i){
    return 2*i+1;
}
int Right(int i){
    return 2*i+2;
}
int Parent(int i){
    return (i-1)/2;
}
double SqLen(Point p){
    return p.x*p.x+p.y*p.y;
}
void Swap(Point &a,Point &b){
    Point tmp=a; a=b; b=tmp;
}
void Heapify(Point heap[],int i,int n){
    int Max=i;
    int l=Left(i);
    int r=Right(i);
    if(l<n and SqLen(heap[l])>SqLen(heap[Max]))
        Max=Left(i);
    if(r<n and SqLen(heap[r])>SqLen(heap[Max]))
        Max=Right(i);
    if(Max!=i){
        Swap(heap[Max],heap[i]);
        Heapify(heap,Max,n);
    }
}
void BulidHeap(Point heap[],int n){
    for(int i=n/2;i>=0;i--)
        Heapify(heap,i,n);
}
void HeapSort(Point heap[],int n){
    BulidHeap(heap,n);
    for(int i=n-1;i>0;i--){
        Swap(heap[0],heap[i]);
        Heapify(heap,0,i);
    }
}
int main(){
    int n=10;
    double tab[2][n]={
    { 1.1 , 3.5 , 2.7 , 0.9 , 6.4 , 1.2 , 0.7 , 9.7 , 8.5 , 0.3 },
    { 4.5 , 0.8 , 1.5 , 1.2 , 7.7 , 2.1 , 2.3 , 8.4 , 2.2 , 0.9 },
    };
    Point heap[n];
    for(int i=0;i<n;i++){
        heap[i].x=tab[0][i];
        heap[i].y=tab[1][i];
        cout << "punkt ( " << heap[i].x << " , " << heap[i].y << " ) ma kwadrat dlugosci: " << SqLen(heap[i]) << endl;
    }
    HeapSort(heap,n);
    cout << endl << "Po posortowaniu: " << endl;
    for(int i=0;i<n;i++){
        cout << "punkt ( " << heap[i].x << " , " << heap[i].y << " ) ma kwadrat dlugosci: " << SqLen(heap[i]) << endl;
    }
    return 0;
}


