#include <iostream>
#include <cstdlib>
#include <ctime>
const int MAX_DEADLINE=10;
const int MAX_PROFIT=5;

using namespace std;

struct task{
    int deadline;
    int profit;
};
struct result{
    task*t;
    int n;
};
task*GenTask(int n){
    task*t=new task[n];
    for(int i=0;i<n;i++){
        t[i].deadline=rand()%MAX_DEADLINE;
        t[i].profit=rand()%MAX_PROFIT+2;
    }
    return t;
}
void PrintTask(task*t,int n){
    cout << "       ";
    for(int i=0;i<MAX_DEADLINE;i++){
         cout.width(2);
         cout << i << " ";
    }
    cout << endl;
    for(int i=0;i<n;i++){
        cout << "Task " << i << " ";
        for(int j=0;j<t[i].deadline;j++)
            cout << "   ";
        cout.width(2);
        cout << t[i].profit << " ";
        cout << endl;
    }
}
int compare(const void *a,const void *b){
    task t_a=*(task *)a;
    task t_b=*(task *)b;
    return t_a.deadline-t_b.deadline;
}
int* ChooseTaks(task*t,int n){
    qsort(t,n,sizeof(task),&compare);
    PrintTask(t,n);
    int time=t[n-1].deadline;
    result r;
    int*result=new int[n];
    for(int i=0;i<n;i++)
        result[i]=-1;
    int i=n-1;
    bool took[n];
    for(int i=0;i<n;i++)
        took[i]=false;
    while(i>=0){
        while(i>0 and t[i].deadline==t[i-1].deadline)
            i--;
        int pricest=i;
        for(int j=i+1;j<n;j++)
            if(!took[j] and t[j].profit>t[pricest].profit)
                pricest=j;
        result[time]=pricest;
        took[pricest]=true;
        i--;
        time--;
    }
    return result;
}
int main(){
    srand(time(0));
    int n=10;
    task*t=GenTask(n);
    PrintTask(t,n);
    int*result=ChooseTaks(t,n);
    cout << "Zadania ktore nalezy brac:";
    for(int i=0;i<n;i++)
        if(result[i]>=0)
            cout << " " << result[i];

    cout << endl;
    PrintTask(t,n);
    return 0;
}
