#include <iostream>
#include <algorithm>
using namespace std;

const long int MAX = 1000;

void numDist(int V[], int i, int j, int& dist) {
	int h = (i + j) / 2, a, b;

	if (j - i == 1) dist += 1;
	else if (j - i == 2) {
		if (V[i] == V[j-1]) dist += 1;
		else if (V[i] != V[j-1]) dist += 2;
	}
	/*else if (j - i == 3) {
		if(V[i] != V[i+1] && V[i+1] != V[j-1]) dist += 3;
		else if((V[i] == V[i + 1] && V[i + 1] != V[j - 1]) || (V[i] != V[i + 1] && V[i + 1] == V[j - 1])) dist += 2;
		else if(V[i] == V[j - 1]) dist += 1;
	}*/
	else {
		numDist(V, i, h, dist);
		numDist(V, h, j, dist);
		if (V[h] == V[h-1]) dist--;
	}
}

int main() {
	int i =0, N, V[MAX];
	cin >> N;
	while (N != 0) {
		int dist = 0;
		for(int j = 0; j < N; j++) cin >> V[j];
		numDist(V, 0, N, dist);
		cout << dist << endl;
		cin >> N;
	}
	return 0;
}