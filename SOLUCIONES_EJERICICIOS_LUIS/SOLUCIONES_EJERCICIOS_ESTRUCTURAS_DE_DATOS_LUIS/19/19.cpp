//LUIS POZAS PALOMO - EDA - 19
#include <iostream>
using namespace std;

#include "bintree_eda_ext.h"

void resuelveCaso() {
	int casos;
	bintree_ext<char> arbol;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		arbol = leerArbol_ext('.');
		cout << arbol.nodos() << " " << arbol.hojas() << " " << arbol.altura() << "\n"; 
	}
}

int main() {
	resuelveCaso();
	return 0;
}