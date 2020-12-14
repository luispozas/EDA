#include <iostream>
#include <algorithm>
using namespace std;

const long int MAX = 1000;

/*
void positivosNegativos(int V[], int N, int& pos) {
	int i = 0, j = N - 1, aux;
	while (i != j) {
		if (V[i] >= 0) i++;
		else {
			aux = V[j];
			V[j] = V[i];
			V[i] = aux;
			j--;
		}
	}
	pos = j + 1;
}
*/

void positivosNegativos(int V[], int N, int& pos) {
	int i = 0, j = N - 1, aux, count = 0;
	while (i != j) {
		if (V[j] < 0) j--;
		else {
			aux = V[j];
			V[j] = V[i];
			V[i] = aux;
			i++;
		}
	}
	pos = j;
	//pos = N == 1 && V[0] < 0? i : i+1;
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		int N, V[MAX], pos;
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> V[j];
		}
		positivosNegativos(V, N, pos);
		for (int p = 0; p < N; p++) cout << V[p] << " ";
		cout << endl << pos << endl;
	}
	return 0;
}