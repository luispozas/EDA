//LUIS POZAS PALOMO - EDA - EF32 (LUCES_DE_COLORES / BACKTRACKING).
//EVALUACION CONTINUA.
#include <iostream>
using namespace std;

const int MAX = 1000;

bool valida(int sol[], int k, int contCol[], int WB[], int TW, int C, int W, int& sumTotCol) {
	bool ok = true;
	contCol[sol[k]]++; //MARCAJE
	sumTotCol++; //MARCAJE
	TW += WB[sol[k]]; //MARCAJE
	if (k > 1 && sol[k] == sol[k - 1] && sol[k] == sol[k - 2]) ok = false;
	if (contCol[sol[k]] > sumTotCol - contCol[sol[k]]+1) ok = false;
	if (TW > W) ok = false;
	contCol[sol[k]]--; //DESMARCAJE
	sumTotCol--; //DESMARCAJE
	TW -= WB[sol[k]]; //DESMARCAJE
	return ok;
}

void lucesNavidad(int sol[], int k, int TW, int L, int C, int W, int WB[], int contCol[], int& numSolPosibles, int& sumTotCol) {
	for (int i = 0; i < C; i++) {
		sol[k] = i;
		if (valida(sol, k, contCol, WB, TW, C, W, sumTotCol)) {
			if (k == L - 1) numSolPosibles++;
			else {
				contCol[sol[k]]++; //MARCAJE
				sumTotCol++; //MARCAJE
				TW += WB[sol[k]]; //MARCAJE
				lucesNavidad(sol, k+1, TW, L, C, W, WB, contCol, numSolPosibles, sumTotCol);
				contCol[sol[k]]--; //DESMARCAJE
				sumTotCol--; //DESMARCAJE
				TW -= WB[sol[k]]; //DESMARCAJE
			}
		}
	}
}

int main() {
	int L, C, W, WB[MAX], sol[MAX], contCol[MAX], numSolPosibles, sumTotCol;
	while (cin >> L >> C >> W) {
		for (int i = 0; i < C; i++) {
			cin >> WB[i];
			contCol[i] = 0;
		}
		numSolPosibles = 0;
		sumTotCol = 0;
		lucesNavidad(sol, 0, 0, L, C, W, WB, contCol, numSolPosibles, sumTotCol);
		cout << numSolPosibles << endl;
	}
	return 0;
}
