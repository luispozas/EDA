//LUIS POZAS PALOMO - 92 - EDA
#include <iostream>
#include <sstream>
using namespace std;

#include "bintree_eda.h"

bool esZurdo(bintree<char> a, int& n){
	if(a.empty()) {
		n = 0;
		return true;
	}
	else if(a.left().empty() && a.right().empty()){
		n = 1;
		return true;
	}
	else{
		bool izq, dcha;
		int ni, nd;
		izq = esZurdo(a.left(), n);
		ni = n;
		dcha = esZurdo(a.right(), n);
		nd = n;
		n = 1 + ni + nd;
		return (izq && dcha && ni > nd);
	}
}		

void resuelveCaso(){
	bintree<char> a;
	int nodos = 0;
	a = leerArbol('.');

	if(esZurdo(a, nodos)) cout << "SI" << endl;
	else cout << "NO" << endl;
}

int main(){
	int numCasos;
	cin >> numCasos;
	for(int i = 0; i < numCasos; ++i){
		resuelveCaso();
	}
	return 0;
}