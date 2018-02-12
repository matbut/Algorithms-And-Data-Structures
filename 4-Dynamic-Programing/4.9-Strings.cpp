#include <iostream>
#include <string>

const int K=5;
using namespace std;

int Max(int a,int b){
    if(a>=b)
        return a;
    return b;
}
bool conclusion(string t,int i,string k){
    int n=k.length();
    i++;
    //cout << endl << "Sprawdzam czy " << k << endl;
    for(int j=0;j<n;j++){
        //cout << t[i+j] << "!=" << k[j] << endl;
        if(t[i+j]!=k[j])
            return false;
    }
    //cout << "Rowne!" << endl;
    return true;
}


int main(){
    string S[K]={"ab","abab","ba","bab","b"};
    int LenS[K];
    for(int i=0;i<K;i++)
        LenS[i]=S[i].length();

    string t;
    cout << "Podaj napis: ";
    cin >> t;
    t="X"+t;

    int n=t.length();
    int F[n];
    for(int i=1;i<n;i++){
        F[i]=0;
        for(int j=0;j<K;j++){
            //cout << i << " " << j << endl;
            if(i-LenS[j]>=0)
                if(conclusion(t,i-LenS[j],S[j]))
                    F[i]=Max(F[i],LenS[j]);
        }
    }
    cout << F[n-1];

    return 0;
}


