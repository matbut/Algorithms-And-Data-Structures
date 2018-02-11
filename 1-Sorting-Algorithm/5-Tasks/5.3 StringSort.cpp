#include <iostream>
#include <string>

using namespace std;
const int N=7;
const int K=10;
const int ILE_LITER=26;

void PrintString(string napisy[N]);
void StringSort(string napisy[N]);
int StringLen(string napis);
void StringSort_byLen(string napisy[N]);
void StringSort_SameLen(string napisy[N],int p,int k);

int main(){
    string napisy[N]={"ala","alb","aaa","f","piec","pies","aaaaa"};
    PrintString(napisy);
    StringSort(napisy);
    PrintString(napisy);

    return 0;
}
void PrintString(string napisy[N]){
    for(int i=0;i<N;i++){
        cout << napisy[i] << ' ';
    }
    cout << endl;
}
int StringLen(string napis){
    int i=0;
    while(napis[i]!='\0')
        i++;

    return i;
}
void StringSort(string napisy[N]){
    StringSort_byLen(napisy);
    int i=0;
    while(i<N){
        int ile=0;
        int Napis_Len=StringLen(napisy[i]);

        bool SameLen=true;
        while(i+ile+1<N and SameLen){
            SameLen=StringLen(napisy[i+ile+1])==Napis_Len;
            if(SameLen)ile++;
        }
        if(ile>0) StringSort_SameLen(napisy,i,i+ile);
        i=i+ile+1;
    }
}
void StringSort_SameLen(string napisy[N],int p,int k){
    for(int c=StringLen(napisy[p])-1;c>=0;c--)
        for(int j=p;j<k;j++)
            for(int i=p;i<k;i++)
                if(napisy[i][c]>napisy[i+1][c]){
                    string tmp=napisy[i]; napisy[i]=napisy[i+1]; napisy[i+1]=tmp;
                }
}

void StringSort_byLen(string napisy[N]){
    int Len[K];
    string kopia[N];
    for(int i=0;i<K;i++)
        Len[i]=0;

    for(int i=0;i<N;i++)
        Len[StringLen(napisy[i])]++;

    for(int i=1;i<K;i++)
        Len[i]+=Len[i-1];

    for(int i=N-1;i>=0;i--){
        kopia[Len[StringLen(napisy[i])]-1]=napisy[i];
        Len[StringLen(napisy[i])]--;
    }
    for(int i=0;i<N;i++)
        napisy[i]=kopia[i];

}

