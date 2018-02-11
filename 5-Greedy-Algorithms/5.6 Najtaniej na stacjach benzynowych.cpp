#include <iostream>
#include <cstdlib>
#include <ctime>

const int N=10;

using namespace std;

int refuels(int dist[N],int cost[N],int tank){
    int total_cost=0;
    int fuel=0;
    int temp_dist=0;
    while(temp_dist<N){
        int d=dist[temp_dist];
        int i=temp_dist+1;
        while(i<N and d+dist[i]<=tank and cost[i]>cost[temp_dist]){
            d+=dist[i];
            i++;
        }
        if(i>=N or cost[i]<=cost[temp_dist])
            if(d<fuel){
                cout << "Nie tankuje paliwa na stacji " << temp_dist << " i jade na stacje " << temp_dist+1 << endl;
                fuel=fuel-dist[temp_dist];
                temp_dist++;
                if(fuel<0)
                    return -1;
            }else{
                cout << "Tankuje " << d-fuel << " paliwa na stacji " << temp_dist << " i jade na stacje " << i << endl;
                total_cost+=(d-fuel)*cost[temp_dist];
                fuel=0;
                temp_dist=i;
        }else{
            cout << "Tankuje do pelna " << tank-fuel << " paliwa na stacji " << temp_dist << " i jade na stacje " << temp_dist+1 << endl;
            total_cost+=(tank-fuel)*cost[temp_dist];
            fuel=tank-dist[temp_dist];
            temp_dist++;
            if(fuel<0)
                return -1;
        }
        cout << "Po przejechaniu mam " << fuel << " paliwa" << endl;
    }
    return total_cost;
}
void Print(int dist[N],int cost[N]){
    cout << "[START:  ";
    for(int i=0;i<N;i++)
        cout  << i << " " << "]--->[ ";
    cout << "END]" << endl;

    cout << "[START: ";
    for(int i=0;i<N;i++)
        cout << cost[i] << "zl" << "]-" << dist[i] << "->[";
    cout << " END]" << endl;

}
int main(){
    srand(time(0));
    int dist[N]={2,3,4,5,2,3,4,1,4,3};
    int cost[N]={2,4,3,2,3,4,1,2,3,2};
    Print(dist,cost);

    int x;
    cout << "Podaj pojemnosc baku: ";
    cin >> x;
    if (refuels(dist,cost,x)>=0)
        cout << "Dojechales! " << endl;
    else
        cout << "Po drodze braklo paliwa..." << endl;
    return 0;
}

