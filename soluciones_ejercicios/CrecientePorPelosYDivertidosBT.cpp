//LUIS POZAS PALOMO - EDA - EF32B (APARICIONES 2n POSICIONES / BACKTRACKING)
#include <iostream>
#include <algorithm>
using namespace std;

const long long int MAX = 10000;

bool valida(int sol[], int k, const int N, const int d, const int e, int count[]) {
	bool ok;
	count[sol[k]]++;

	if ((abs(sol[k]) - abs(sol[k - 1]) == 1 || abs(sol[k]) - abs(sol[k - 1]) == 0) && count[sol[k]] <= d && sol[k] >= sol[k - 1]) ok = true;
	else ok = false;

	count[sol[k]]--;
	return ok;
}

void funRellenarVector(int sol[], int k, const int N, const int d,  const int e, int count[]) {
	for (int i = e; i < e + N; i++) {
		sol[k] = i;
		if (valida(sol, k, N, d, e, count)) {
			if (k == N-1) {
				for (int i = 0; i < N; i++) cout << sol[i] << " ";
				cout << endl;
			}
			else {
				count[sol[k]]++; //MARCAJE
				funRellenarVector(sol, k+1, N, d, e, count);
				count[sol[k]]--; //DESMARCAJE
			}
		}
	}
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		int N, d, e, sol[2 * MAX], count[MAX];
		cin >> N >> d >> e;
		for (int j = 0; j < N+1; j++) {
			count[j] = 0; //INICIALIZACION NUMERO DE APARICIONES DE CADA NUMERO
		}
		sol[0] = e;
		count[e]++;
		funRellenarVector(sol, 1, N, d, e, count);
	}
	return 0;
}





















