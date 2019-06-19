//LUIS POZAS PALOMO - P3
#include <iostream>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * He utilizado un unordered_map para almacenar el numero y las posiciones en
 * las que va apareciendo.
 *    CLAVE -> valores de la secuencia.
 *    VALOR -> vector con las posiciones en las que ha aparecido la clave.
 *
 * El coste de la solucion es el MAX(O(N), O(M)).
 * Donde M es el numero de consultas y N el numero de valores a procesar.
*/

bool resuelveCaso() {
	int N, M, v, k, num;
	unordered_map<int, vector<int>> dic;
	cin >> N >> M;

	if (!cin)
		return false;
	
	for (int i = 0; i < N; i++) {
		cin >> num;
		dic[num].push_back(i + 1);
	}

	for (int i = 0; i < M; i++) {
		cin >> k >> v;
		auto it = dic.find(v);
		if(it != dic.end()){
			if(it->second.size() >= k){
				cout << dic[v][k-1] << endl;
			}
			else cout << "NO HAY" << endl;
		}
		else cout << "NO HAY" << endl;
	}

	cout << "---\n";
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