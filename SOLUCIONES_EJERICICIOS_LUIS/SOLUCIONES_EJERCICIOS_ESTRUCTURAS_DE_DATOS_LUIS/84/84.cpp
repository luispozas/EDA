//LUIS POZAS PALOMO - 84
#include <iostream>
#include <fstream>
using namespace std;

#include "invierte.h"

bool resuelveCaso() {
	int n,idx, length, data;
	invierte<int> dq;
	cin >> n >> idx >> length;
	if(!cin) return false;
	for(int i = 0; i < n; ++i){
		cin >> data;
		dq.push(data);
	}

	dq.invertir(idx, length);

	//Comprueba que todo ha quedado correctamente
	//for (int i = 0; i < dq.size() ; ++i) {
	//	int elem = dq.front(); dq.pop();
    //   	dq.push(elem);
	//}
	cout << dq << endl;
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