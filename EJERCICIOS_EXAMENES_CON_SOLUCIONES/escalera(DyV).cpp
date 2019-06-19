#include <iostream>
#include <algorithm>
using namespace std;

const long int MAX = 1000;

void escaleraG(int V[], const int N, int i, int j, int& longI, int& longD, int& maximo) {
	int a_longI, a_longD, a_maximo, b_longI, b_longD, b_maximo;
	int h = (i + j) / 2;

	if (j - i == 1) longI = longD = maximo = 1;
	else if (j - i == 2) {
		if (V[i] != V[j - 1]) longI = longD = maximo = 1;
		else if (V[i] == V[j - 1]) longI = longD = maximo = 2;
	}
	else {
		escaleraG(V, N, i, h, longI, longD, maximo); //1 LLAMADA RECURSIVA POR IZQ(a)
		a_longI = longI;
		a_longD = longD;
		a_maximo = maximo;
		escaleraG(V, N, h, j, longI, longD, maximo); //2 LLAMADA RECURSIVA POR DCHA(b)
		b_longI = longI;
		b_longD = longD;
		b_maximo = maximo;
		
		if (V[h] == V[h - 1]) {
			maximo = max(a_longD + b_longI, b_maximo);
			maximo = max(maximo, a_maximo);
			if (V[h] == V[i]) longI = a_longD + b_longI;
			else longI = a_longI;
			if (V[h-1] == V[j-1]) longD = b_longI + a_longD;
			else longD = b_longD;
		}
		else {
			maximo = max(a_maximo, b_maximo);
			longI = a_longI;
			longD = b_longD;
		}
	}
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		int N, V[MAX];
		cin >> N;
		for (int j = 0; j < N; j++) cin >> V[j];
		int longI = 1, longD = 1, max = 1;
		escaleraG(V, N, 0, N, longI, longD, max);
		cout << longI << " " << longD << " " << max << endl;
	}
	return 0;
}