//LUIS POZAS PALOMO - EDA - EF32 (LUCES_COLORES / BACKTRAKING) - MODO DEBUG.
#include <iostream>
using namespace std;

const long long int MAX = 10000;

void printSol(int sol[], int L) {
	for (int i = 0; i < L; i++) cout << sol[i];
	cout << endl;
}

bool valida(int sol[], int cont[], int WB[], int k, int TW, int C, int W, int& sumTot) {
	bool ok = true;
	cont[sol[k]]++; //MARCAJE
	sumTot++; //MARCAJE
	TW += WB[sol[k]]; //MARCAJE
	if (k > 1 && sol[k] == sol[k - 1] && sol[k] == sol[k - 2]) ok = false;
	if (cont[sol[k]] > sumTot - cont[sol[k]]+1) ok = false;
	if (TW > W) ok = false;
	cont[sol[k]]--; //DESMARCAJE
	sumTot--; //DESMARCAJE
	TW -= WB[sol[k]]; //DESMARCAJE
	return ok;
}

void lucesNavidad(int sol[], int k, int TW, int L, int C, int W, int WB[], int cont[], int& numSolPosibles, bool& existSol, int& sumTot) {
	for (int i = 0; i < C; i++) {
		sol[k] = i;
		if (valida(sol, cont, WB, k, TW, C, W, sumTot)) {
			if (k == L - 1) {
				numSolPosibles++;
				printSol(sol, L);
				existSol = true;
			}
			else {
				cont[sol[k]]++; //MARCAJE
				sumTot++; //MARCAJE
				TW += WB[sol[k]]; //MARCAJE
				lucesNavidad(sol, k+1, TW, L, C, W, WB, cont, numSolPosibles, existSol, sumTot);
				cont[sol[k]]--; //DESMARCAJE
				sumTot--; //DESMARCAJE
				TW -= WB[sol[k]]; //DESMARCAJE
			}
		}
	}
}

int main() {
	int L, C, W, WB[MAX], sol[MAX], cont[MAX], numSolPosibles, sumTot;
	bool existSol;
	while (cin >> L >> C >> W) {
		for (int i = 0; i < C; i++) {
			cin >> WB[i];
			cont[i] = 0;
		}
		numSolPosibles = 0;
		sumTot = 0;
		existSol = false;
		lucesNavidad(sol, 0, 0, L, C, W, WB, cont, numSolPosibles, existSol, sumTot);
		if (!existSol) cout << "SIN SOLUCION" << endl;
		else cout << numSolPosibles << endl;
	}
	return 0;
}
