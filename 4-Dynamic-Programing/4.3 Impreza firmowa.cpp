#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Employee{
    string surname;
    Employee**subordinate;
    int subordinates_num;
    int fun;
    int f;      // najlepsza impreza w poddrzewie
    int g;      // najlepsza impreza w poddrzewie gdy pracownika nie jest zaproszony ma impreze
};
Employee*GenCompany(int n);
void PrintCompany(Employee*E,int licznik);

int party(Employee*boss);
void reset(Employee*boss);
int f(Employee*boss);
int g(Employee*boss);
int Max(int a,int b){
    if(a>=b)
        return a;
    return b;
}

int main(){
    srand(time(0));
    int n=8;
    Employee*boss=GenCompany(n);
    PrintCompany(boss,0);
    cout << endl << "Impreza zbierze wtedy " << party(boss) << " punktow" << endl;
    return 0;
}
void PrintParty(Employee*boss,bool czy){
    if(czy)
        if(f(boss)>g(boss)){
            cout << boss ->surname << ", ";
            for(int i=0;i<boss->subordinates_num;i++)
                PrintParty(boss->subordinate[i],false);
            return;
        }
    for(int i=0;i<boss->subordinates_num;i++)
        PrintParty(boss->subordinate[i],true);
}
int party(Employee*boss){
    reset(boss);
    cout << endl << "Na impreze nalezy zaprosic: ";
    PrintParty(boss,true);
    return f(boss);
}
void reset(Employee*boss){
    boss->f=-1;
    boss->g=-1;
    for(int i=0;i<boss->subordinates_num;i++)
        reset(boss->subordinate[i]);
}
int f(Employee*boss){
    if(boss->f>=0)
        return boss->f;
    boss->f=boss->fun;
    for(int i=0;i<boss->subordinates_num;i++)
        boss->f+=g(boss->subordinate[i]);
    boss->f=Max(boss->f,g(boss));
    //cout << " najlepsza impreza w " << boss->surname << " to " << boss->f << endl;

    return boss->f;
}
int g(Employee*boss){
    if(boss->g>=0)
        return boss->g;
    boss->g=0;
    for(int i=0;i<boss->subordinates_num;i++)
        boss->g+=f(boss->subordinate[i]);
    return boss->g;
}
Employee*GenCompany(int n){
    Employee*E=new Employee[n];
    int N=7;
    int t[2][N]={
        {0,1,1,1,2,2,3},  // szefowie
        {1,2,3,4,5,6,7}   // podwladni
    };
    string s[8]={"Smith","Brown","Oldman","Winslet","White","Thomas","Jenkins","Henderson"};
    int idx[n];
    for(int i=0;i<n;i++){
        E[i].surname=s[i];
        E[i].subordinates_num=0;
        E[i].fun=rand()%5;
        idx[i]=0;
    }
    for(int i=0;i<N;i++)
        E[t[0][i]].subordinates_num++;
    for(int i=0;i<n;i++)
        E[i].subordinate=new Employee*[E[i].subordinates_num];
    for(int i=0;i<N;i++){
        E[t[0][i]].subordinate[idx[t[0][i]]]=&E[t[1][i]];
        idx[t[0][i]]++;
    }
    return &E[0];
}
void PrintCompany(Employee*E,int licznik){
    for(int i=0;i<licznik;i++)
        cout << "   ";
    cout << E->surname << "[" << E->fun << "]"<< endl;
    for(int i=0;i<E->subordinates_num;i++)
        PrintCompany(E->subordinate[i],licznik+1);
}

