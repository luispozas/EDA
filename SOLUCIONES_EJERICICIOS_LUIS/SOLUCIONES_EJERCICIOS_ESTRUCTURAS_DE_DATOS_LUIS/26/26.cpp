//LUIS POZAS PALOMO - EDA - 26
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#include "bintree_eda.h"

/* PROBAR HACIENDOLO DE OTRA MANERA SIN INT_MIN NI INT_MAX */


bool esArbolBusqueda(bintree<int> a, int min, int max){
	if(a.empty()) return true;
	return (a.root() < max && a.root() > min && esArbolBusqueda(a.left(), min, a.root()) 
		&& esArbolBusqueda(a.right(), a.root(), max));
}

void resuelveCaso() {
	int casos;
	bintree<int> a;

	cin >> casos;
	for (int i = 0; i < casos; i++) {
		a = leerArbol(-1);
		esArbolBusqueda(a, INT_MIN, INT_MAX)? cout << "SI" << endl : cout << "NO" << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}