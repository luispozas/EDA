// LUIS POZAS PALOMO - EDA - COLONES(A02)

#include <iostream>
#include <algorithm>
using namespace std;

/*		P{ V[0...N) and N >= 0 }
 			fun personasColadas(V[] de enteros, int N) retorna int p;
		Q{ p = #i: 0 <= i < N-1: V[i] > min(V, i+1, N) }

		Donde:
				min(V, t, N) -> { min k : t <= k < N : V[k] }


		I: { p = #i: 0 <= i < n-1: V[i] > min(V, i+1, n) }

		Init:
		-----
		i, p, m = N-1, 0, V[N-1];

		Step:
		-----
		i = i - 1;

		Quote:
		------
		C(n) = i >= 0

		Restore:
		--------
		if (V[i-1] > m) p++;
		m = min(V[i-1], m);

*/


int personasColadas(int V[], int N){
	int i = N-1, p = 0, m = V[N-1];
	while (i >= 0){
		if (V[i-1] > m) p++;
		m = min(V[i-1], m);
		i--;
	}
	return p;
}

void resuelveCaso(){
	int numCasos, N;
	cin >> numCasos;
	for(int i = 0; i < numCasos; i++){
		cin >> N;
		int V[N];
		for(int j = 0; j < N; j++){
			cin >> V[j];
		}
		cout << personasColadas(V, N) << endl;
	}
}

int main(){
	resuelveCaso();
	return 0;
}
