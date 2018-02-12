#include <iostream>
#include <string>
using namespace std;

void buduj(int A,int B,string s){
    if(A==0 && B==0) cout << s << endl;
    if(A>0) buduj(A-1,B,s+"1");
    if(B>0) buduj(A,B-1,s+"0");
}

void genbuduj(int A,int B){
    if(A>1) buduj(A-1,B,"1");
        else cout << "Nie da sie";
}

int main(){
    int A,B;
    cin >> A;
    cin >> B;
    genbuduj(A,B);

}
