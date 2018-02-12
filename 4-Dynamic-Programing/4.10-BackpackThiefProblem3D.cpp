#include <iostream>
#include <cstdlib>
#include <ctime>
const int P=10;
const int W=5;
const int H=8;
using namespace std;

struct item{
    int price;
    int weight;
    int height;
};

item* GenItems(int n);
int knapsack(item*Items,int n,int T,int S);
int Max(int a,int b){
    if(a>=b)
        return a;
    return b;
}

int main(){
    srand(time(0));
    int n=5;
    item*Items=GenItems(n);
    int T,S;
    cout << "Podaj ile uniesie zlodziej: ";
    cin >> T;
    cout << "Podaj wysokosc plecaka: ";
    cin >> S;
    cout << endl << "Ich cena to: " << knapsack(Items,n,T,S) << endl;
    return 0;
}

int knapsack(item*Items,int n,int T,int S){
    int F[n][T+1][S+1];
    for(int t=0;t<=T;t++)
        for(int s=0;s<=S;s++)
            F[0][t][s]=0;
    for(int i=0;i<n;i++)
        for(int s=0;s<=S;s++)
            F[i][0][s]=0;
    for(int i=0;i<n;i++)
        for(int t=0;t<=T;t++)
            F[i][t][0]=0;
    // F[i][t][k]=maskymalna wartosc przedmiotow jesli do dyspozycji jest:
    // i przedmiotow
    // t wagi
    // k wysokosci

    for(int i=1;i<n;i++)
        for(int t=1;t<=T;t++){
            for(int h=1;h<=S;h++){
                //cout << " przedmiot " << i << " waga " << t << " wysokosc " << h;
                if(Items[i].weight > t or Items[i].height > h)
                    F[i][t][h]=F[i-1][t][h];
                else
                    if(F[i-1][t][h] > F[i-1][t-Items[i].weight][h-Items[i].height]+Items[i].price){
                        F[i][t][h]=F[i-1][t][h];
                    }else{
                        F[i][t][h]=F[i-1][t-Items[i].weight][h-Items[i].height]+Items[i].price;
                    }
                //cout << " suma " << F[i][t][h] << endl;
            }
        }
    cout << "Przedmioty ktore powinien zabrac zlodziej: ";
    int i=n-1,t=T,s=S;
    while(i!=0 and t!=0 and s!=0){
        if(F[i][t][s]>F[i-1][t][s]){
            cout << i << ", ";
            t-=Items[i].weight;
            s-=Items[i].height;
        }
        i--;
    }
    return F[n-1][T][S];
}
item* GenItems(int n){
    item*Items=new item[n];
    cout << "Przedmioty: " << endl;
    for(int i=1;i<n;i++){
        Items[i].price=rand()%P+1;
        Items[i].weight=rand()%W+1;
        Items[i].height=rand()%H+1;
        cout << i  << " waga: " << Items[i].weight << " wysokosc: " << Items[i].height << " cena: " << Items[i].price << endl;
    }
    return Items;
}
