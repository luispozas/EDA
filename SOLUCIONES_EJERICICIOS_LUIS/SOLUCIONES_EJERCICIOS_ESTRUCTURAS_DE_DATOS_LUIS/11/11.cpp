//LUIS POZAS PALOMO - EDA - 11
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#include "ordena.h"

void resuelveCaso(){
	ListaOrdenada<int> cola, cola2;
	int e;
	while(cin >> e && e!= 0) cola.push(e);
	while(cin >> e && e!= 0) cola2.push(e);
	cola.ordenar(&cola2);
	cout << cola << endl;
}

int main(){
	int num;
	cin>>num;
	for(int i = 0; i < num; i++){
		resuelveCaso();
	}
	return 0;
}