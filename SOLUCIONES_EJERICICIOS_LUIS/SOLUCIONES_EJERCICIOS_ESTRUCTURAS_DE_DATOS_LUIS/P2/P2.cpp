//LUIS POZAS PALOMO - Prueba de evaluacion 2
#include <iostream>
#include <fstream>
using namespace std;

#include "bintree_eda.h"

int acumuladores(bintree<int> a, int& sum) {
	if (a.empty()) {
		sum = 0;
		return 0;
	}
	else {
		int sumI, sumD;
		int acIzq = acumuladores(a.left(), sumI);
		int acDcha = acumuladores(a.right(), sumD);
		sum = sumI + sumD + a.root();
		return acIzq + acDcha + (sumI + sumD == a.root());
	}
}

void resuelveCaso() {
	int sum;
	auto arbol = leerArbol(-1);
	cout << acumuladores(arbol, sum) << '\n';
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}