#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 10000;


void llanoHeidiG(int V[], int A[], int N, int l, int &secMax, int &num, int i, int c, int aux) {
	aux = max(V[i], aux);
	if (i > 0 && V[i] == V[i - 1] && aux <= V[i]) {
		c++;
		llanoHeidiG(V, A, N, l, secMax, num, i - 1, c, aux);
	}
	else {
		if (c >= secMax && c >= l) secMax = c;
		if (c >= l) A[num++] = (i + (c - 1));
		c = 1;
		if (i >= 0) llanoHeidiG(V, A, N, l, secMax, num, i - 1, c, aux);
	}
}

void llanoHeidi(int V[], int A[], int N, int l, int &secMax, int &num) {
	int i = N - 1, c = 1, aux = 0;
	llanoHeidiG(V, A, N, l, secMax, num, i, c, aux);
}


int main() {
	int N, l, V[MAX], A[MAX];
	while (cin >> N >> l) {
		int secMax = 0, num = 0;
		for (int i = 0; i < N; i++) cin >> V[i];
		llanoHeidi(V, A, N, l, secMax, num);
		cout << secMax << " " << num;
		for (int j = 0; j < num; j++) cout <<" "<< A[j];
		cout << endl;
	}
	return 0;
}
