//LUIS POZAS PALOMO - EDA - 04
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#include "polinomio.h"
#include "monomio.h"


bool resuelveCaso() {
	int c, e, numVal;
	polinomio pol;
	vector <int> V;

	if(!(cin >> c >> e)) return false;
	while (c != 0 || e != 0) {
		monomio m(c, e);
		pol.add(m);
		cin >> c >> e;
	}
	//Leo los valores a evaluar por el polinomio
	cin >> numVal;
	int n;
	for (int i = 0; i < numVal; i++) {
		cin >> n;
		V.push_back(n);
	}

	for (int i = 0; i < numVal; i++) { // evaluo el polinomio por cada caso
		cout << pol.calculatePol(V[i]) << " ";
	}
	cout << "\n";
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}
