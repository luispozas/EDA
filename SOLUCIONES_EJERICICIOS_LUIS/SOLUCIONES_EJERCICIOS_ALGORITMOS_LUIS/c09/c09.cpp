// LUIS POZAS PALOMO - EDA - CHASM(C09)
#include <iostream>
using namespace std;

/*
P{ V[0...N) and N >= 1 }
	fun chasm (V[0...N) de enteros, int N) retorna bool t.
Q{ t = EXIST p : 0 <= p < N: (forall i, j : 0 <= i <= p-1 < p <= j < N-1 : V[i] > V[i+1]) and V[j] < V[j+1]) }

I: Q[N\n] and 0 <= n < N

C(n) = N - i

*/

int chasm(int V[], long long int N) {
	int i = 0;
	if (N > 1) {
		while (i < N - 1 && (V[i] > V[i + 1])) i++;
		while (i < N - 1 && (V[i] < V[i + 1])) i++;
		return i >= N - 1;
	}
	else return 1;
}

void resuelveCaso() {
	long long int N;
	while (cin >> N) {
		int V[N];
		for (int i = 0; i < N; i++) {
			cin >> V[i];
		}
		cout << chasm(V, N) << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}
