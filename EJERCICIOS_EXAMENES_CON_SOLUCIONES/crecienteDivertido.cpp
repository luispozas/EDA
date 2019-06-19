#include <iostream>
#include <algorithm>
using namespace std;

const long int MAX = 1000;

bool crecienteDivertido(int V[], int N, int d) {
	bool cre = true, div = true;
	int count = 1, countA = 1;

	for (int i = 0; i < N-1; i++) {
		if (V[i] > V[i + 1] || (V[i + 1] - V[i] != 1 && V[i + 1] - V[i] != 0)) return false;
		if (V[i] == V[i + 1] && count < countA+1) count = ++countA;
		else countA = 1;
	}
	if (count > d) return false;
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		int d, N, V[MAX];
		cin >> d;
		cin >> N;
		for (int j = 0; j < N; j++) cin >> V[j];
		if (crecienteDivertido(V, N, d)) cout << "SI" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}