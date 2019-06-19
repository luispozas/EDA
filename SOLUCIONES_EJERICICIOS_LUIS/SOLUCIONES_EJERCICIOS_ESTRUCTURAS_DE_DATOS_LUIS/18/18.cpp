//LUIS POZAS PALOMO - EDA - 18
#include <iostream>
using namespace std;

/*
//CODIGO CON PARAMETROS ACUMULADORES (NO USAR).

main: sum = 0, bec = 0;

void alturaArbol(int& sum, int& bec, int const jef) {
	int val;
	cin >> val;
	if (val != 0) {
		for (int i = 0; i < val; i++) {
			sum++; //marcaje
			alturaArbol(sum, bec, jef);
			sum--; //desmarcaje
		}
	}
	else {
		if (sum >= jef) bec++; //cuando llego a un becario pregunto si es precario.
	}
}
*/

int alturaArbol(int k, int const jef) {
	int val, num = 0;
	cin >> val;
	if (val != 0) {
		for (int i = 0; i < val; i++) {
			num += alturaArbol(k+1, jef);
		}
	}
	else {
		if (k >= jef) return 1;
	}
	return num;
}

bool resuelveCaso() {
	int jef;
	cin >> jef;
	if (!cin) return false;
	cout << alturaArbol(0, jef) << endl;
	return true;
}

int main() {
	while(resuelveCaso()){}
	return 0;
}