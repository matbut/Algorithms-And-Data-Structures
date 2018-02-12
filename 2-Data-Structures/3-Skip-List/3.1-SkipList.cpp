#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
const int N=10;
const int MIN=-1;
const int MAX=100;
const int MAXLEVEL=20;

using namespace std;

struct SLNode{
    int key;
    string val;
    SLNode**next;
};
struct SkipList{
    SLNode*first,*last;
    int level,maxlevel;
};

int Potega_2(int i);
int RandLevel();

int Max(int x,int y){
    if(x>=y)
        return x;
    return y;
}

SkipList GenSkipList(string t[],int indeks[],int n);
void PrintSkipList(SkipList s);
SLNode* SkipListSearch(SkipList s,int key);
void SkipListInsert(SkipList &s,SLNode*w);
SLNode*SkipListRemove(SkipList &s,int key);

SkipList Init(int level);
SkipList MergeTwoList(SkipList l1,SkipList l2);
SkipList BetterMergeTwoList(SkipList l1,SkipList l2);

SLNode* CutFirstSLNode(SkipList s,int &level);
void InserSLNode(SLNode**biez,SLNode*q,int level);

int main(){
    srand(time(0));
    string TabList1[10]={"Ala","Ola","Ula","Ela","Ada","Ewa","Iga","Ida","Mia","Nel"};
    int IndexList1[10]={2,3,11,19,29,31,37,39,41,47};
    SkipList List1=GenSkipList(TabList1,IndexList1,10);
    PrintSkipList(List1);

    string TabList2[6]={"jan","Iwo","Kaj","Lew","Noe","Wit"};
    int IndexList2[6]={5,7,13,17,23,43};
    SkipList List2=GenSkipList(TabList2,IndexList2,6);
    PrintSkipList(List2);

    SkipList Sum=BetterMergeTwoList(List1,List2);

    PrintSkipList(Sum);


    int x;
    cout << "\nWyszukiwanie:\nCzego szukasz:";
    cin >> x;
    SLNode*q=SkipListSearch(Sum,x);
    if(q!=NULL) cout << "Znalazlem: " << q->key << '.'<< q->val << endl;
    else cout << "Nie znalazlem" << endl;


    q=new SLNode;
    cout << "\nWstawianie:\nPodaj klucz:";
    cin >> q->key;
    cout << "Podaj wartosc:";
    cin >> q->val;
    SkipListInsert(Sum,q);
    PrintSkipList(Sum);

    cout << "\nUsuwanie:\nPodaj klucz:";
    cin >> x;
    q=SkipListRemove(Sum,x);
    if(q!=NULL) cout << "Znalazlem i wycialem: " << q->key << '.'<< q->val << endl;
    else cout << "Nie znalazlem wiec nie wyciolem" << endl;
    PrintSkipList(Sum);
    return 0;
}
SkipList Init(int level){
    SkipList s;
    s.level=level;
    s.maxlevel=MAXLEVEL;

    s.first=new SLNode;
    s.first->key=MIN;
    s.first->next=new SLNode*[s.maxlevel];

    s.last=new SLNode;
    s.last->key=MAX;
    s.last->next=(SLNode**)calloc(s.maxlevel,sizeof(SLNode*));
    for(int i=0;i<s.maxlevel;i++){
        s.first->next[i]=s.last;
        s.last->next[i]=NULL;
    }
    return s;
}
SkipList BetterMergeTwoList(SkipList l1,SkipList l2){
    // Wstawienie z l2 do l1;
    l1.level=Max(l1.level,l2.level);
    SLNode**biez_l1 = new SLNode*[l1.maxlevel];
    SLNode**biez_l2 = new SLNode*[l1.maxlevel];
    SLNode*tmp;

    for(int i=0;i<l1.maxlevel;i++){
        biez_l1[i]=l1.first;
        biez_l2[i]=l2.first;
    }
    while(biez_l1[0]->next[0]!=l1.last and biez_l2[0]->next[0]!=l2.last){
        // przebieganie po l1
        int MinInsert=l2.first->next[0]->key;
        for(int i=l1.level-1;i>=0;i--){
            while(biez_l1[i]->next[i]!=NULL and biez_l1[i]->next[i]->key < MinInsert)
                biez_l1[i]=biez_l1[i]->next[i];
        }
        // przebieganie po l2
        int MaxInsert=biez_l1[0]->next[0]->key;
        for(int i=l1.level-1;i>=0;i--){
            while(biez_l2[i]->next[i]!=NULL and biez_l2[i]->next[i]->key < MaxInsert)
                biez_l2[i]=biez_l2[i]->next[i];
        }
        //dopianie
        for(int i=0;i<l1.maxlevel;i++){
            if(l2.first->next[i]->key < MaxInsert){
                tmp=biez_l1[i]->next[i];
                biez_l1[i]->next[i]=l2.first->next[i];
                l2.first->next[i]=biez_l2[i]->next[i];
                biez_l2[i]->next[i]=tmp;
                biez_l2[i]=l2.first;
            }
        }
    }
    delete l2.first;
    delete l2.last;
    return l1;
}
SLNode*SkipListRemove(SkipList &s,int key){
    SLNode*q=s.first;
    SLNode*w=s.first;
    for(int i=s.level-1;i>=0;i--){
        while(q->next[i]->key < key)
            q=q->next[i];
        if(q->next[i]->key==key){
            w=q->next[i];
            q->next[i]=q->next[i]->next[i];
        }
    }
    if(w->key!=key) return NULL;
    delete w->next;
    return w;
}
SLNode* SkipListSearch(SkipList s,int key){
    SLNode*q=s.first;
    for(int i=s.level-1;i>=0;i--){
        while(q->next[i]!=NULL and q->next[i]->key < key)
            q=q->next[i];
        if(q->next[i]->key==key) return q->next[i];
    }
    return NULL;
}
SkipList MergeTwoList(SkipList l1,SkipList l2){
    SkipList s=Init(Max(l1.level,l2.level));
    SLNode**biez = new SLNode*[s.maxlevel];
    for(int i=0;i<s.maxlevel;i++)
        biez[i]=s.first;

    while(l1.first->next[0]->key<MAX and l2.first->next[0]->key<MAX){
        SLNode*q;
        int level;
        if(l1.first->next[0]->key<l2.first->next[0]->key)
            q=CutFirstSLNode(l1,level);
        else
            q=CutFirstSLNode(l2,level);
        InserSLNode(biez,q,level);
    }
    while(l1.first->next[0]->key<MAX){
        int level;
        SLNode*q=CutFirstSLNode(l1,level);
        InserSLNode(biez,q,level);
    }
    while(l2.first->next[0]->key<MAX){
        int level;
        SLNode*q=CutFirstSLNode(l2,level);
        InserSLNode(biez,q,level);
    }
    for(int i=0;i<s.maxlevel;i++)
        biez[i]->next[i]=s.last;
    delete [] biez;
    return s;
}
SLNode* CutFirstSLNode(SkipList s,int &level){
    SLNode*q=s.first->next[0];
    level=0;
    while(s.first->next[level]==q)
        level++;
    for(int i=0;i<level;i++){
        s.first->next[i]=s.first->next[i]->next[i];
        q->next[i]=NULL;
    }
    return q;
}
void InserSLNode(SLNode**biez,SLNode*q,int level){
    for(int i=0;i<level;i++){
        biez[i]->next[i]=q;
        biez[i]=q;
    }
}
SkipList GenSkipList(string t[],int indeks[],int n){
    SkipList s=Init(log(n)+2);

    SLNode**biez = new SLNode*[s.maxlevel];
    for(int i=0;i<s.maxlevel;i++)
        biez[i]=s.last;


    for(int i=n-1;i>=0;i--){
        SLNode*q=new SLNode;
        q->next=(SLNode**)calloc(Potega_2(i+1),sizeof(SLNode*));
        q->key=indeks[i];
        q->val=t[i];
        for(int j=0;j<Potega_2(i+1);j++){
            q->next[j]=biez[j];
            biez[j]=q;
        }
    }
    for(int i=0;i<s.maxlevel;i++)
        s.first->next[i]=biez[i];
    return s;
}
void PrintSkipList(SkipList s){
    cout << "Skip lista: " << endl;
    for(int i=s.level-1;i>=0;i--){
        SLNode*q=s.first;
        if(q!=s.last){
            cout << i << "." << s.first->key << "";
            q=q->next[i];
        }
        while(q!=s.last){
            cout << "----" << q->key << '.'<< q->val << "";
            q=q->next[i];
        }
        cout << "----" << s.last->key << endl;
    }
}
void SkipListInsert(SkipList &s,SLNode*w){
    SLNode*q=s.first;

    int level=RandLevel();
    if(level>s.level) s.level=level;
    w->next=(SLNode**)calloc(level,sizeof(SLNode*));

    for(int i=s.level-1;i>=0;i--){
        while(q->next[i]->key < w->key)
            q=q->next[i];
        if (i<=level-1){
            w->next[i]=q->next[i];
            q->next[i]=w;
        }
    }
}
int Potega_2(int i){
    int licznik=1;
    while(i%2==0){
        licznik++;
        i=i/2;
    }
    return licznik;
}
int RandLevel(){
    int licznik=1;
    while(rand()%2 and licznik<MAXLEVEL)
        licznik++;
    return licznik;
}


