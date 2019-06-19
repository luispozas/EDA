//LUIS POZAS PALOMO - EDA - 23
#include <iostream>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"

int resc(bintree<int> a, int& m){
	if(a.empty()) { m = 0; return 0; }
	else {
		int maxi, maxd;
		int i = resc(a.left(), maxi);
		int d = resc(a.right(), maxd);

		m = max(maxi, maxd) + a.root();

		if(i != 0 || d != 0) return i + d;
		else return (a.root() != 0);

	}
}


void resuelveCaso() {
	int casos;
	bintree<int> a;

	cin >> casos;
	for (int i = 0; i < casos; i++) {
		a = leerArbol(-1);
		int max;
		int j = resc(a, max);
		cout << j << " " << max << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}