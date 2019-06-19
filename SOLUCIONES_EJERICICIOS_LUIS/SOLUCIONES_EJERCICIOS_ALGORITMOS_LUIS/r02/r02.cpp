//LUIS POZAS PALOMO - EDA - (R02)
#include <iostream>
using namespace std;

long long int invertirDigitos(long long int n,  int& pot) {
	long long int num = 0;
	if (n < 10) { //CASO BASE
	    return n;
	}
	else {
		num = (invertirDigitos(n / 10, pot) + ((n % 10) * pot));
		pot *= 10;
		return num;
	}
}



bool resuelveCaso() {
	long long int n;
	int pot = 10;
	cin >> n;
	if (!cin) return false;
	else {
		cout << invertirDigitos(n, pot) << endl;
		return true;
	}
}

int main() {
	while (resuelveCaso());
	return 0;
}
