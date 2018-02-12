//PROGRAM WIEZE HANOI
#include <iostream>

using namespace std;

const char A='A',B='B';

void pal(int a,int b,char A, char B, string s);
void genpal(int a,int b);

int main(){
    int n;
    genpal(4,3);
return 0; }

void pal(int a,int b, string s){
    cout << s << endl;
    if(a>1){pal(a-2,b,A+s+A);
    }
    if(b>1){pal(a,b-2,B+s+B);
    }
}
void genpal(int a,int b){
    pal(a,b,"");
    pal(a-1,b,"A");
    pal(a,b-1,"B");
}
