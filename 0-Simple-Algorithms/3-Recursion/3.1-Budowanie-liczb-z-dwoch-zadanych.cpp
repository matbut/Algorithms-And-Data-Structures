#include <iostream>
#include <string>
using namespace std;

string intToStr(int n);
void perm(int x,int y,string s){
    if(x==0 && y==0) cout << s << endl;
    if(y>0) perm(x,y/10,intToStr(y%10)+s);
    if(x>0) perm(x/10,y,intToStr(x%10)+s);
}


int main(){
    int x,y;
    cout << " Podaj 1 liczbe:";
    cin >> x;
    cout << " Podaj 2 liczbe:";
    cin >> y;
    perm(x,y,"");
    return 0;
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
