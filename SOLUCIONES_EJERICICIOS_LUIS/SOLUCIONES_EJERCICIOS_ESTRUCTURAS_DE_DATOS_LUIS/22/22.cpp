//LUIS POZAS PALOMO - EDA - 22
#include <iostream>
using namespace std;

#include "bintree_eda_ext.h"

void resuelveCaso() {
	int casos;
	bintree_ext<char> a;

	cin >> casos;
	for (int i = 0; i < casos; i++) {
		a = leerArbol_ext('.');
		cout << a.diametro() << "\n";
	}
}

int main() {
	resuelveCaso();
	return 0;
}