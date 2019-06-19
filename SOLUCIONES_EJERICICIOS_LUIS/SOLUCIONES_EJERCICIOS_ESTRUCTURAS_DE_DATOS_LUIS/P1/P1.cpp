//LUIS POZAS PALOMO - Prueba de evaluacion 1
#include <iostream>
#include <fstream>
using namespace std;

#include "intercambia.h"

bool resuelveCaso() {
	int n, data;
	Intercambia<int> c;
	cin >> n;
	if(n == 0) return false;
	for(int i = 0; i < n; ++i){
		cin >> data;
		c.push(data);
	}

	c.intercambia(); //Llamo a la fucnion nueva.

	for(int i = 0; i < c.size(); i++){
		cout << c.front() << " ";
		c.push(c.front());
		c.pop();
	}
	cout << endl;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while(resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}