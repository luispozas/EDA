//LUIS POZAS PALOMO - 81
#include <iostream>
#include <fstream>
using namespace std;

#include "elimina.h"
#include "Horas.h"


bool resuelveCaso() {
	int n;
	horas data;
	elimina<horas> l;
	cin >> n;
	if(n == 0) return false;
	for(int i = 0; i < n; ++i){
		cin >> data;
		l.push(data);
	}
	l.eliminaPares();
	cout << l << endl;
	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}