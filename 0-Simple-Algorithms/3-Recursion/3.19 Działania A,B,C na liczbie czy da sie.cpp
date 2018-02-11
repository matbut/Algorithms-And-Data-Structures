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
bool dzialania(int x,int y,int n,string s){
    if(x==y) {
        cout  << s << endl;
        return true;
    }
    if(n==0){
        return false;
    }
    if(x%2==0)
       return dzialania(A(x),y,n-1,s+"A ") || dzialania(B(x),y,n-1,s+"B ") || dzialania(C(x),y,n-1,s+"C ");
    else return dzialania(A(x),y,n-1,s+"A ") || dzialania(B(x),y,n-1,s+"B ");
}

int main(){
    int x,y,n;
    cin >> x;
    cin >> y;
    cin >> n;
    if (dzialania(x,y,n,"")) cout << "TAK"; else cout << "NIE";
}
