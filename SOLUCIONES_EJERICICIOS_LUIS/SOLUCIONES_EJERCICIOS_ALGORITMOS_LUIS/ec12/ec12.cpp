//LUIS POZAS PALOMO - EDA - EC12
#include <iostream>
using namespace std;

int busElemPerdidoG(int A[], int B[], int i, int j) {
	int h = (j+i)/2;

	if (j - i == 1) {
		if (A[i] != B[i]) return A[i];
		if (A[i] == B[i]) return A[j];
	}
	else if (j - i == 0) return A[i];
	else if (A[h] == B[h]) busElemPerdidoG(A, B, h, j);
	else if (A[h] != B[h]) busElemPerdidoG(A, B, i, h);
}

void resuelveCaso() {
	int numCasos, N;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		cin >> N;
		int  A[N], B[N-1];
		for (int j = 0; j < N; j++) cin >> A[j];
		for (int k = 0; k < N-1; k++) cin >> B[k];
		cout << busElemPerdidoG(A, B, 0, N-1) << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}

/*
Como resolver DyV
1º Fijarse en las precondiciones del problema, son tus amigas, si son muy intensas -> trabajas muy poco -> O(log)N)).
DyV -> logN, nLogN ... Busqueda binaria, mergeShort...
Empezar siempre por el caso general.
Hacer muchos dibujitos.
Acuerdate de partir a la mitad y respetar las precondiciones.
*/
