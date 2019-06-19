//LUIS POZAS PALOMO - EDA - 08
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#include "duplica.h"

bool resuelveCaso(){
	ListaDuplica<int> cola;
	int d;
	if(!cin) return false;
	while(cin >> d && d!=0){
		cola.push(d);
	}
	cola.duplica();
	for (int i = 0; i < cola.size() ; ++i) {
        int elem = cola.front(); cola.pop();
        cola.push(elem);
	}
	cout << cola << endl;
	return true;
}

int main(){
	while(resuelveCaso());
}