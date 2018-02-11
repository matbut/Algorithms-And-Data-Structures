#include <iostream>
#include <cstdlib>
#include <ctime>
const int T=10;
const int W=5;
const int M=W+T;
using namespace std;

void qsort(void* base, size_t num, size_t size,int (*compar)(const void*,const void*));
struct result{
    int*tab;
    int cap;
};
struct subject{
    int start,finish;
};
int compar(const void*a,const void*b){
    subject sub_a=*(subject*)a;
    subject sub_b=*(subject*)b;
    return sub_a.finish-sub_b.finish;
}
subject* GenSubjects(int n){
    subject*s=new subject[n];
    for(int i=0;i<n;i++){
        s[i].start=rand()%T;
        s[i].finish=s[i].start+rand()%W+1;
    }
    return s;
}
void PrintSubjects(subject*s,int n){
    cout << "         ";
    for(int i=0;i<T+W;i++){
         cout.width(2);
         cout << i << " ";
    }
    cout << endl;
    for(int i=0;i<n;i++){
        cout << "Subject " << i << " ";
        for(int j=0;j<s[i].start;j++)
            cout << "   ";
        for(int j=0;j<s[i].finish-s[i].start;j++)
            cout << char(219) << char(219) << char(219);
        cout << endl;
    }
}
result ChooseSubjects(subject*s,int n){
    int time=0;
    int i=0;
    result r;
    r.tab=new int[n];
    r.cap=0;
    while(time<M and i<n){
        while(s[i].start<time and i<n)
            i++;
        if(i==n)
            break;
        r.tab[r.cap]=i;
        time=s[i].finish;
        r.cap++;
        i++;
    }
    return r;
}
int main(){
    srand(time(0));
    int n=10;
    subject*s=GenSubjects(n);
    PrintSubjects(s,n);
    qsort(s,n,sizeof(subject),&compar);
    PrintSubjects(s,n);
    result r=ChooseSubjects(s,n);
    cout << endl << "Take subjects: ";
    for(int i=0;i<r.cap;i++)
        cout << r.tab[i] << " ";
    cout << endl;
    return 0;
}
