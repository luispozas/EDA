//LUIS POZAS PALOMO - EDA - 02
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#include "Horas.h"
#include "Peliculas.h"

bool resuelveCaso() {
	int npeliculas;
	cin >> npeliculas;
	if (npeliculas == 0) return false;

	vector<peliculas> pel(npeliculas);

	for (int i = 0; i < npeliculas; i++) {
		horas h_ini, h_duracion, h_fin;
		string titulo;
		try {
			cin >> h_ini;
			cin >> h_duracion;
			h_fin = h_ini + h_duracion;
			getline(cin, titulo);
			pel[i] = peliculas(h_fin, titulo); //por que aqui no hace falta poner *p = ...???
		}
		catch (invalid_argument & e) {
			cout << "ERROR\n";
		}
	}

	sort (pel.begin(), pel.end());

	for(int i = 0; i < npeliculas; i++){
		cout << pel[i].hora() << " " << pel[i].titulo() << endl;
	}

	cout << "---\n";
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}
