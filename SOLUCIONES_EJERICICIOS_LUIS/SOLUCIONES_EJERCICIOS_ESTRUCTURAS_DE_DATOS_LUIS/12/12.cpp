//LUIS POZAS PALOMO - EDA - 12
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#include "queue_eda.h"

bool resuelveCaso(){
	queue<int> cola;
	int alumnos, salto;
	if(cin >> alumnos >> salto && alumnos == 0 && salto == 0) return false;
	for(int i = 1; i <= alumnos; i++) cola.push(i);

	int cont = 0;

	while(cola.size() != 1){
		if(cont == salto){
			cola.pop();
			cont = 0;
		}
		else {
			cola.push(cola.front());
			cola.pop();
			cont++;
		}
	}

	cout << cola.front() <<"\n";

	return true;
}

int main(){
	while(resuelveCaso());
	return 0;
}