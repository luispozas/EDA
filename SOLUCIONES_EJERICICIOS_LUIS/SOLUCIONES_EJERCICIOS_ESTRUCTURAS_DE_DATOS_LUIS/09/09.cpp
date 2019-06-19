//LUIS POZAS PALOMO - EDA - 09
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#include "invierte.h"

bool resuelveCaso(){
	ListaInvierte<int> cola;
	int d;
	if(!cin) return false;
	while(cin >> d && d!=0){
		cola.push(d);
	}
	cola.invierte();
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