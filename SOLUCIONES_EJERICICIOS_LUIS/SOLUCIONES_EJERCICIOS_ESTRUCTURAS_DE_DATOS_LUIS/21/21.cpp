//LUIS POZAS PALOMO - EDA - 21
#include <iostream>
#include <string>
using namespace std;

#include "bintree_eda_ext.h"

bool resuelveCaso() {
	bintree_ext<int> a1;
	bintree_ext<string> a2;
	string val = "#";

	char c;
	cin >> c;

	if (!cin) return false;
	if (c == 'N') {
		a1 = leerArbol_ext(-1);
		cout << a1.menorNodo() << "\n";
	}
	else {
		a2 = leerArbol_ext(val);
		cout << a2.menorNodo() << "\n";
	}
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}