//LUIS POZAS PALOMO - 25 - EDA
#include <iostream>
#include <fstream>
using namespace std;

#include "bintree_eda.h"

bool esPrimo(int n){
	int divisor = 1, divisores = 0;
	do{
		if(n % divisor == 0) divisores++;
		divisor++;
	}while(divisor <= n);

	if(divisores == 2) return true;
	return false;
}

int barreraDePrimos(bintree<int> a, int h, int& min){
	if(a.empty() || esPrimo(a.root())) {min = h; return 0;}
	else if(a.root()%7 == 0){
		min = h;
		return a.root();
	}
	else {
		int minI = -1, minD = -1;
		int iz = barreraDePrimos(a.left(), h+1, minI);
		int de = barreraDePrimos(a.right(), h+1, minD);
		if(iz != 0 && de != 0) {
			min = (minI <= minD)? minI : minD;
			return (minI <= minD)? iz : de;
		}
		else{
			if(iz != 0) {min = minI; return iz;}
			if(de != 0) {min = minD; return de;}
			else return 0;
		}
	}
	
}


void resuelveCaso(){
	bintree<int> a;
	int min = -1;
	a = leerArbol(-1);

	int val = barreraDePrimos(a, 1, min);
	if(val == 0) cout << "NO HAY" << endl;
	else cout << val << " " << min << endl;
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