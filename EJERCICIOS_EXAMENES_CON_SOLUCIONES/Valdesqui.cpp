#include <iostream>
using namespace std;

const long int MAX = 1000;

int funTram(int V[], int T) {
	int i = 0, c = 1;
	while (i < T) {
		int j = i, c1 = 1;
		while (j < T-1 && V[j] >= V[j + 1]) {
			c1++;
			j++;
		}
		if (c1 > c) c = c1;
		i = j+1;
	}
	return c;
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		int T, V[MAX];
		cin >> T;
		for (int j = 0; j < T; j++) {
			cin >> V[j];
		}
		cout << funTram(V, T) << endl;
	}

	return 0;
}