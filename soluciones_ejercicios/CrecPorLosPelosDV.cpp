#include <iostream>
#include <algorithm>
using namespace std;

const long int MAX = 1000;

bool crecientePorLosPelos(int V[], int i, int j) {
	int h = (i + j) / 2;
	bool a, b;

	if (j - i == 1) return true;
	else if (j - i == 2) {
		if (V[i] != V[j - 1] && V[j - 1] - V[i] != 1) return false;
		else if (V[i] != V[j - 1] && V[j - 1] - V[i] == 1) return true;
		else if (V[i] == V[j - 1]) return true;
	}
	else {
		a = crecientePorLosPelos(V, i, h);
		b = crecientePorLosPelos(V, h, j);
		if (a && b) {
			if (V[h] == V[h - 1]) return true;
			else if (V[h] != V[h - 1] && V[h] - V[h - 1] != 1) return false;
			else if (V[h] != V[h - 1] && V[h] - V[h - 1] == 1) return true;
		}
		else return false;
	}
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		int N, V[MAX];
		cin >> N;
		for (int j = 0; j < N; j++) cin >> V[j];
		if (crecientePorLosPelos(V, 0, N)) cout << "SI" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}