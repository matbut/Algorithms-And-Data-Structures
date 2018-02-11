#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
const int MAX=10;

int main(){
    srand(time(0));
    int tab[MAX],dl_ros=1, dl_mal=1, dl_max=0;
    for(int i=0; i< MAX; i++) {
        tab[i]=rand()%10;
        cout << tab[i] << " ";
    }
    for(int i=0;i<MAX-1;i++){
        if(tab[i+1]-tab[i]>0) {
            dl_ros++;
            dl_mal=1;
            if(dl_ros>dl_max) dl_max=dl_ros;
        }else if(tab[i+1]-tab[i]<0) {
            dl_mal++;
            dl_ros=1;
            if(dl_mal>dl_max) dl_max=dl_mal;
        }else{
            dl_ros=1;
            dl_mal=1;
        }
    }
    cout << endl << dl_max;
    return 0;
}
