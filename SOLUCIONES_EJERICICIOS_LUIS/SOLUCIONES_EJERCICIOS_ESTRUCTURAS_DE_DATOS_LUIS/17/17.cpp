//LUIS POZAS PALOMO - EDA - 17
#include <iostream>
using namespace std;

int alturaArbol() {
	int max = 0, val;
	cin >> val;
	if (val != 0) {
		for (int i = 0; i < val; i++) {
			int h = alturaArbol();
			if (max < h+1) max = h+1;
		}
		return max;
	}
	else return 1;
}

void resuelveCaso() {
	int numCasos;
	cin >> numCasos;
	for(int i = 0; i < numCasos; i++)
		cout << alturaArbol() << endl;
}

int main() {
	resuelveCaso();
	return 0;
}