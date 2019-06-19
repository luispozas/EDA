#include <iostream>
#include <algorithm>
using namespace std;

const long int MAX = 1000;

int masCercano(int V[], int i, int j, int e) {
	int h = (i + j) / 2;

	if (j - i == 2) {
		if (abs(e - V[i]) <= abs(e - V[j])) return V[i];
		else return V[j];
	}
	else if (j - i == 1) return V[i];
	else if(e <= V[h]) masCercano(V, i, h, e);
	else if(e > V[h]) masCercano(V, h, j, e);
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		int e, N, V[MAX];
		cin >> e;
		cin >> N;
		for (int j = 0; j < N; j++) cin >> V[j];
		cout << masCercano(V, 0, N, e) << endl;
	}

	return 0;
}