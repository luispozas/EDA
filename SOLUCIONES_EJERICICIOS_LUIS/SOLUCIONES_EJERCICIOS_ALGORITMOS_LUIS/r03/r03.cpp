//LUIS POZAS PALOMO - EDA - (R03).
#include <iostream>
using namespace std;

long long int fibG (long long int n, long long int& cont){
	long long int fib, aux;
	if (n==0) return 0;
	else if (n == 1){
		cont = 0;
		return 1;
	}
	else if (n > 1){
		aux = fibG(n-1, cont);
		fib = cont + aux;
		cont = aux;
		return fib;
	}
}

/*
--------------  CON RECURSION MULTIPLE -> (TIME LIMIT) X  -------------

long long int fib(long long int n) {
	long long int num = 0;

	if (n == 0) return 0; //CASO BASE 1
	else if (n == 1) return 1; //CASO BASE 2
	else if (n > 1){
		num = fib (n-1) + fib (n-2);
		return num;
	}
}
*/

bool resuelveCaso() {
  long long int n, cont;
	cin >> n;
	if (!cin) return false;
	else {
		cout << fibG(n, cont) << endl;
		return true;
	}
}

int main() {
	while (resuelveCaso());
	return 0;
}
