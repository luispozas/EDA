//LUIS POZAS PALOMO - EDA - EF32B (APARICIONES 2n POSICIONES / BACKTRACKING)
#include <iostream>
#include <algorithm>
using namespace std;

const long long int MAX = 10000;

bool valida(int sol[], int k, const int N, int aparece[]) {
	bool ok = true;

	if (k > 0 && aparece[sol[k]] != -1 && k - aparece[sol[k]] != sol[k] + 1) ok = false;

	return ok;
}

void funRellenarVector(int sol[], int k, const int N, int aparece[], int& countNumSol) {
	for (int i = 1; i <= N; i++) {
		sol[k] = i;
		if (valida(sol, k, N, aparece)) {
			if (k == (2 * N) - 1) {
				for (int i = 0; i < 2 * N; i++) cout << sol[i] << " ";
				cout << endl;
				countNumSol++;
			}
			else {
				if (aparece[sol[k]] == -1) aparece[sol[k]] = k; //MARCAJE

				funRellenarVector(sol, k+1, N, aparece, countNumSol);

				if (aparece[sol[k]] != -1 && k == aparece[sol[k]]) aparece[sol[k]] = -1; //DESMARCAJE
			}
		}
	}
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		int N, sol[2 * MAX], countNumSol = 0, aparece[MAX];
		cin >> N;
		for (int j = 0; j < N+1; j++) {
			aparece[j] = -1; //INICIALIZACION NUMERO DE APARICIONES DE CADA NUMERO
		}
		funRellenarVector(sol, 0, N, aparece, countNumSol);
		cout << "Soluciones: " << countNumSol << endl;
	}
	return 0;
}





















