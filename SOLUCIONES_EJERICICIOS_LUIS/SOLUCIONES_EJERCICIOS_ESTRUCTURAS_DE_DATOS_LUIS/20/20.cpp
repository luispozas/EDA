//LUIS POZAS PALOMO - EDA - 20
#include <iostream>
using namespace std;

#include "bintree_eda_ext.h"

void resuelveCaso() {
	int casos;
	bintree_ext<int> arbol;
	vector<int> v;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		arbol = leerArbol_ext(-1);
		v = arbol.frontera();
		for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
		cout << "\n";
	}
}

int main() {
	resuelveCaso();
	return 0;
}