#include <iostream>

using namespace std;
const int N=10;

struct Queue{
    int*tab;
    int head; // wskaxnik na wierzcholek
    int tail; // zarezerwowana pamiec
};

Queue Init();
bool IsEmpty(Queue Q);
void Enqueue(Queue &Q,int n);
int Dequeue(Queue &Q);


int main(){
    Queue Q=Init();
    if(IsEmpty(Q))
        cout << "Kolejka jest pusta. " << endl;
    else
        cout << "Kolejka nie jest pusta" << endl;
    cout << "Wsadzam do kolejki: " << 1 << endl;
    cout << "Wsadzam do kolejki: " << 2 << endl;
    Enqueue(Q,1);
    Enqueue(Q,2);
    if(IsEmpty(Q))
        cout << "Kolejka jest pusta. " << endl;
    else
        cout << "Kolejka nie jest pusta" << endl;
    cout << "Pobralem z kolejki: " << Dequeue(Q) << endl;
    cout << "Pobralem z kolejki: " << Dequeue(Q) << endl;
    if(IsEmpty(Q))
        cout << "Kolejka jest pusta. " << endl;
    else
        cout << "Kolejka nie jest pusta" << endl;
    return 0;
}
Queue Init(){
    Queue Q;
    Q.head=0;
    Q.tail=0;
    Q.tab=new int[N];
    return Q;
}
bool IsEmpty(Queue Q){
    return Q.head==Q.tail;
}
void Enqueue(Queue &Q,int n){
    Q.tab[Q.tail%N]=n;
    Q.tail++;

}
int Dequeue(Queue &Q){
    Q.head++;
    return Q.tab[(Q.head-1)%N];
}
