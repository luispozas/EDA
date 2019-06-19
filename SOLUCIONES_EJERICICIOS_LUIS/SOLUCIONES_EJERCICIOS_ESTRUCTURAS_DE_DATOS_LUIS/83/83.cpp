//LUIS POZAS PALOMO - 83
#include <iostream>
#include <fstream>
using namespace std;

#include "engorda.h"

void resuelveCaso() {
	int n, data;
	engorda<int> dq, dq_insert;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> data;
		dq.push_back(data);
	}
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> data;
		dq_insert.push_back(data);
	}

	dq.engordar(dq_insert);
	//Comprueba que todo ha quedado correctamente-------
	for (int i = 0; i < dq.size() ; ++i) {
		int elem = dq.front(); dq.pop_front();
       	dq.push_back(elem);
	}
	for (int i = 0; i < dq.size() ; ++i) {
		int elem = dq.back(); dq.pop_back();
       	dq.push_front(elem);
	}
	//---------------------------------------------------
	cout << dq << endl;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	cin >> numCasos;
	for(int i = 0; i < numCasos; i++){
		resuelveCaso();
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}