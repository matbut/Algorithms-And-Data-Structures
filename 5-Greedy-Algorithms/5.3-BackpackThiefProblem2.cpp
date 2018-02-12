#include <iostream>
#include <cstdlib>
#include <ctime>
const int P=10;
const int W=5;
using namespace std;

struct item{
    int price;
    int weight;
};

item* GenItems(int n);
int knapsack(item*Items,int n,int T);
int Max(int a,int b){
    if(a>=b)
        return a;
    return b;
}

int main(){
    srand(time(0));
    int n=5;
    item*Items=GenItems(n);
    int T;
    cout << "Podaj ile uniesie zlodziej: ";
    cin >> T;
    cout << endl << "Ich cena to: " << knapsack(Items,n,T) << endl;
    return 0;
}

int knapsack(item*Items,int n,int T){
    int F[n+1];
}
item* GenItems(int n){
    item*Items=new item[n];
    cout << "Przedmioty: " << endl;
    for(int i=1;i<n;i++){
        Items[i].price=rand()%P+1;
        Items[i].weight=rand()%W+1;
        cout << i << " cena: " << Items[i].price << " waga: " << Items[i].weight << endl;
    }
    return Items;
}
