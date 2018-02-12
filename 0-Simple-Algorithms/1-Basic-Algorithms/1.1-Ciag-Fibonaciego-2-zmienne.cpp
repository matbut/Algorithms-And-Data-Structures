#include <iostream>

int main(){
    using namespace std;
    int a=1,b=1;

    for (int i=0; i<20; i++){
        cout << a << endl;
        b = a+b;
        a = b-a;
    }

    return 0;
}
