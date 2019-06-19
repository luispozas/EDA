/* LUIS POZAS PALOMO - EDA - (C05).

-----------------------------------------------------------------------------------------------------------

P{ V[0...N) and N > 0 }
	fun solve (inout int V[], int N) retorna (p : entero).
Q{ Exist p : 0 <= p < N : (Forall i: 0 <= i < p: a[i] >= 0) and (forall w: p <= w < N: a[w] <= 0) }

I: Q[N\n] and 0 <= n < N

C(n) = c2 - c1

*/

#include <iostream>
using namespace std;

const int MAX = 10000;

int solve(int v[], int N) {
	int c1 = 0, c2 = N - 1, aux;
	while (N > 1 && c1 <= c2) {
		if (v[c1] >= 0)	c1++;
		else if (v[c1] < 0) {
			aux = v[c2];
			v[c2] = v[c1];
			v[c1] = aux;
			c2--;
		}
	}
	if (N == 1 && v[0] >= 0) c1 = 1;
	return c1;
}

void resuelveCaso() {
	int num, N, v[MAX], p;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) cin >> v[j];
		p = solve(v, N);
		for (int j = 0; j < N; j++)	cout << v[j] << " ";
		cout << endl << p << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}
