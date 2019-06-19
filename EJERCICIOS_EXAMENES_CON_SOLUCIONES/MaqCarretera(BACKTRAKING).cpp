//LUIS POZAS PALOMO - EDA - EF32B (CARRETERAS/MAQUINAS-NIEVE / BACKTRACKING)
#include <iostream>
#include <algorithm>
using namespace std;

const long long int MAX = 100;

bool valida(int sol[], int i, int j, int m[], int n[], int f[]) {
	bool ok = false;

	if (f[j] == -1 && m[i] <= n[j]) ok = true;

	return ok;
}

void calidadMaximaCarreteras(int sol[], int k, const int M, const int N, int m[], int n[], int c[MAX][MAX], int f[], int& countA, int & count) {

	for (int j = 0; j < N; j++) {
		sol[k] = c[k][j];
		if (valida(sol, k, j, m, n, f)) {
			if (k == M - 1) {
				for (int t = 0; t < M; t++) countA += sol[t];
				if (countA >= count) count = countA;
				countA = 0;
			}
			else {
				f[j] = 1;
				calidadMaximaCarreteras(sol, k + 1, M, N, m, n, c, f, countA, count);
				f[j] = -1;
			}
		}
	}
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		int sol[MAX], M, N, m[MAX], n[MAX], c[MAX][MAX], maximo = 0, maximoAux = 0;
		cin >> M >> N;
		for (int j = 0; j < M; j++) cin >> m[j];
		for (int j = 0; j < N; j++) cin >> n[j];
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) cin >> c[j][k];
		}
		int f[MAX], countA = 0, count = 0;
		for (int k = 0; k < N; k++) f[k] = -1;
		calidadMaximaCarreteras(sol, 0, M, N, m, n, c, f, countA, count);
		cout << count << endl;
	}
	return 0;
}
