#include <iostream>
#include <string>
using namespace std;

int A(int x){
    return x+3;
}
int B(int x){
    return 2*x;
}
int C(int x){
    return (x/100)*100+(10*(x%10))+(x/10)%10;
}

bool czypierwsza(int x){
    if(x%2==0) return false;
    for(int i=3;i<=x/2;i=i+2){
        if(x%i==0) return false;
    }
    cout << x;
    return true;
}

bool dzialania(int x,int n,string s,string &max_s){
    //cout << n << " " << x << " " << s << " " << max_s;
    if(czypierwsza(x)) {
        max_s=s;
        return true;
    }else if(n>0){
        if (dzialania(A(x),n-1,s+"A ",max_s)) return true;
        if (dzialania(B(x),n-1,s+"B ",max_s)) return true;
        if (x>11) if(dzialania(C(x),n-1,s+"C ",max_s)) return true;
    }else{
        return false;
    }
}



int main(){
    int x,n;
    cin >> x;
    cin >> n;
    string max_s="";
    if (dzialania(x,n,"",max_s)) cout << "Tak: " << max_s; else cout << "Nie";
}
