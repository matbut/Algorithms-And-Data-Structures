// PROGRAM DNI GAJECKIEGO

#include <iostream>
using namespace std;

int main(){
    for (int i=0; i<9999; i++){ //i kolejne sprawdzane liczby
        int r=0, ki=i; //ki Kopia i, r rewers
        while (ki>0){
            r=r*10+ki%10;
            ki/=10;
        }
        if (r==i) cout << "Znalazlem liczbe: " << i << endl;
    }

    return 0;
}
