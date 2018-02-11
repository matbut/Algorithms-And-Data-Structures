// OSTATNIA CYFRA SILNI

#include <iostream>
#include <cmath>
const int MAX=100000;

using namespace std;

int main(){
    int i,j,ki,x;
    int silnia[MAX];
    int cyfra,dwojki,piatki,nadmiar;

    while (true){
        silnia[0]=1;
        for (j=1 ; j<MAX ; j++){
            silnia[j]=0;
        }
        dwojki=0;
        cyfra=1;
        piatki=0;

        cout << "Podaj liczbe" << endl;
        cin >> x;


        for (i=1;i<=x;i++){
            ki=i;

            nadmiar=0;
            for (j=0;j<MAX;j++){
                silnia[j]=silnia[j]*i+nadmiar;
                nadmiar=silnia[j]/10;
                silnia[j]=silnia[j]%10;
            }
            if (nadmiar>0) cout << "Tablica sie skonczyla";

            while (ki%5==0){
                    ki=ki/5;
                    piatki++;
            }
            while (ki%2==0) {
                ki=ki/2;
                dwojki++;
            }
            cyfra=((cyfra*ki))%10;

        }
        dwojki=dwojki-piatki;
        for (dwojki;dwojki>0;dwojki--){
            cyfra=(cyfra*2)%10;
        }
        cout << x << "! = ";
        j=MAX-1;
        while (silnia[j]==0) j--;
        for (j;j>=0;j--) cout << silnia[j];
        cout << ", a ostatnia cyfra to " << cyfra << endl;
    }
return 0;
}
