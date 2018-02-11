#include <iostream>
#include <string>
using namespace std;
void rozklad(int x,int p,string s);
string intToStr(int n);

int main(){
    int x;
    cout << "Podaj liczbe:";
    cin >> x;
    rozklad(x,x-1,"");
    return 0;
}

void rozklad(int x,int p,string s){
    if(x==0) {
            cout << s <<endl;
    }
    for(int i=p;i>0;i--){
        if((x-i)>=0) rozklad(x-i,i,s+"+"+intToStr(i));
    }
}

string intToStr(int n)
{
     string tmp, ret;
     if(n < 0) {
      ret = "-";
      n = -n;
     }
     do {
      tmp += n % 10 + 48;
      n -= n % 10;
     }
     while(n /= 10);
     for(int i = tmp.size()-1; i >= 0; i--)
      ret += tmp[i];
     return ret;
}
