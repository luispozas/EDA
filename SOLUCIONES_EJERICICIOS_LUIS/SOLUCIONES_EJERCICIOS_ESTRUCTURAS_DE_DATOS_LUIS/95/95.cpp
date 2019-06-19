//LUIS POZAS PALOMO - 95
#include <iostream>
#include <fstream>
#include <utility>
using namespace std;

#include "set_eda_mod.h"

int resuelveCaso() {
	int n, data;
	set<int> c;
	pair<bool, int> p;
	cin >> n;
	if(n == 0) return false;
	for(int i = 0; i < n; ++i){
		cin >> data;
		c.insert(data);
	}

	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> data;
		p = c.lower_bound(data);
		if(!p.first) cout << "NO HAY" << endl;
		else cout << p.second << endl;
	}
	cout << "---" << endl;
	return true;
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