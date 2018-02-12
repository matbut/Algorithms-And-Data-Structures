#include <iostream>
#include <string>
using namespace std;

int A(int x){
    return x+1;
}
int B(int x){
    return 3*x;
}
int C(int x){
    return x/2;
}
void dzialania(int x,int y,int n,string s){
    if(x==y) {
        cout  << s << endl;
    }else if(n>0){
        dzialania(A(x),y,n-1,s+"A ");
        dzialania(B(x),y,n-1,s+"B ");
        if (x%2==0) dzialania(C(x),y,n-1,s+"C ");
    }
}

int main(){
    int x,y,n;
    cin >> x;
    cin >> y;
    cin >> n;
    dzialania(x,y,n,"");
}
