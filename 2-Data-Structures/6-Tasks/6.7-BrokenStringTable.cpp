#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;
const int N=10;
const int SIZE=11;

struct HT{
    string*Key;
    int* Data;
    bool* Free;
    int Size;
};
int Hash(string key,int Size){
	int h=0;
	for (int i=0;i<key.length();i++)
		h+=i*key[i];
	return h%Size;
}
void InsertHashTab(HT ht,string key,int data){
    int idx=Hash(key,ht.Size);
    int licznik=0;
    while(licznik < ht.Size and !ht.Free[(idx+licznik)%ht.Size])
        licznik++;
    if(licznik == ht.Size){
        cout << "Przepolniona tablica ";
        return;
    }
    idx=(idx+licznik)%ht.Size;
    ht.Key[idx]=key;
    ht.Data[idx]=data;
    ht.Free[idx]=false;
}
HT GenHashTab(){
    HT ht;
    string Key[N]={"Ala","Ola","Ula","Ela","Ada","Ewa","Iga","Ida","Mia","Nel"};
    int Data[N]={101,102,103,104,105,106,107,108,109,110};
    ht.Size=SIZE;
    ht.Key=new string[ht.Size];
    ht.Data=new int[ht.Size];
    ht.Free=new bool[ht.Size];
    for(int i=0;i<ht.Size;i++)
        ht.Free[i]=true;
    for(int i=0;i<N;i++)
        InsertHashTab(ht,Key[i],Data[i]);

    return ht;
}
void PrintHashTab(HT ht){
    cout << endl;
    for(int i=0;i<ht.Size;i++)
        cout << "  " << i << "  |";
    cout << endl;
    for(int i=0;i<ht.Size;i++)
        if(ht.Free[i])
            cout << "     |";
        else
            cout << " " << ht.Key[i] << " |";
    cout << endl;
    for(int i=0;i<ht.Size;i++)
        if(ht.Free[i])
            cout << "  F  |";
        else
            cout << " [" << Hash(ht.Key[i],ht.Size) << "] |";
    cout << endl;
    for(int i=0;i<ht.Size;i++)
        if(ht.Free[i])
            cout << "     |";
        else
            cout << " " << ht.Data[i] << " |";
    cout << endl << endl;
}
bool CheckHashTab(HT ht){
    // KROK 1
    int i=0;
    while(i<ht.Size and !ht.Free[i])
        i++;
    if(i==ht.Size)
        return true;
    // KROK 2
    int j=0;
    while(j<ht.Size){
        int start_index;
        if(ht.Free[(i+j)%ht.Size])
            start_index=(i+j)%ht.Size;
        else{
            int h=Hash(ht.Key[(i+j)%ht.Size],ht.Size);
            if((i+j)<ht.Size)
                if(!(h>start_index and h<=i+j)){
                    cout << "Nie da sie odnalezc " << ht.Key[i+j] << endl;
                    return false;
                }
            else
                if(!((h>start_index and h<ht.Size) or (h>=0 and h<=(i+j)%ht.Size))){
                    cout << "Nie da sie odnalezc " << ht.Key[(i+j)%ht.Size] << endl;
                    return false;
                }
        }
        j++;
    }
    return true;
}
int main(){
    srand(time(0));
    HT ht=GenHashTab();
    PrintHashTab(ht);
    //ht.Free[1]=true;
    ht.Key[5]="Ula";
    PrintHashTab(ht);
    if (CheckHashTab(ht))
        cout << "Tablica jest poprawna";
    else
        cout << "Hash tablica jest uszkodzona";

    return 0;
}


