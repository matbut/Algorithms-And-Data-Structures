#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct data{
	string first_name;
	string last_name;
	int age;
};

int Hash(data*x);

int main(){
    data*osoba=new data;
    osoba->first_name="Jan";
    osoba->last_name="Nowak";
    osoba->age=45;

    cout << Hash(osoba);

    return 0;
}

int Hash(data*x){
	int h;
	int i=0;
	int s=(x->first_name).length();
	for (i;i<s;i++)
		h+=i*(x->first_name[i]);

	s+=(x->last_name).length();
	for(i;i<s;i++)
		h+=i*x->last_name[i];

	h*=(x->age);
	return h;
}
