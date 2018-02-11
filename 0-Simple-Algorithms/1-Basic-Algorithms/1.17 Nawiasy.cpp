#include <iostream>

using namespace std;

bool test_nawiasy(string a);

int main(){
    string a;
    cout << "Podaj napis: ";
    cin >> a;
    if (test_nawiasy(a)) cout << "Nawiasy sie zgadzaja";
    else cout << "Nawiasy sa zle";

    return 0;
}
bool test_nawiasy(string a){
    int i=0;
    int nawiasy=0;
    while(a[i]!='\0' and nawiasy>=0){
        if(a[i]=='(')
            nawiasy++;
        else if(a[i]==')')
            nawiasy--;
        i++;
    }
    return nawiasy==0;
}


