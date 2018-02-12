#include <iostream>
#include <cstdlib>
#include <ctime>

const int N=10;

using namespace std;

int refuels(int dist[N],int tank){
    int petrol=tank;
    int visited_petrol=1;
    int i=0;
    while(i<N){
        if(dist[i]<=petrol){
            petrol-=dist[i];
            i++;
        }else if(dist[i]<=tank){
            petrol=tank;
            visited_petrol++;
            cout << "odwiedzam " << i << " stacje" << endl;
        }else
            return -1;
    }
    return visited_petrol;
}
int main(){
    srand(time(0));
    int dist[N]={2,5,4,3,1,6,5,3,1,2};
    cout << "[START";
    for(int i=0;i<N;i++)
        cout << "]-" << dist[i] << "-[" << i+1;
    cout << "END]" << endl;
    int x;
    cout << "Podaj pojemnosc baku: ";
    cin >> x;
    if (refuels(dist,x)>=0)
        cout << "Dojechales! " << endl;
    else
        cout << "Po drodze braklo paliwa..." << endl;
    return 0;
}

