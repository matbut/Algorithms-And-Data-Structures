//PROGRAM WIEZE HANOI
#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;
void przekladanie(int x,char a,char b, char c);

int main(){
    int n;
    cout <<"Podaj iloma klockami sie bawisz: ";
    cin >> n;
    char a='A',b='B',c='C';
    przekladanie(n,a,b,c);
return 0; }

void przekladanie(int x,char a,char b, char c){
    if (x>1) {
        przekladanie(x-1,a,c,b);
        cout << "Przenies " << x << " z " << a << " na " << b << endl;
        przekladanie(x-1,c,b,a);
    }else cout << "Przenies " << x << " z " << a << " na " << b << endl;
}
