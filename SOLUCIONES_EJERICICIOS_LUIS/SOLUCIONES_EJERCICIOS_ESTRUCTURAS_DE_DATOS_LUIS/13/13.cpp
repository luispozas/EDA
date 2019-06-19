//LUIS POZAS PALOMO - EDA - 13
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#include "queue_eda.h"

int pacticaEsteganografia(int const C, int const clave[], int const N, int const sec[]){
	vector<queue<int>> elems(C);
	int menor = N;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < C; j++) {
			if(sec[i] == clave[j]) elems[j].push(i);
		}
	}

	int i = 0;
	while (!elems[i].empty() && !elems[i+1].empty()){ 
		if(elems[i].front() > elems[i+1].front()){ elems[i+1].pop(); i = 0; } //si encuentro uno que no aparece en orden correcto lo saco.
		else {
			if(i == C-2) { //Como se garantiza que la clave aparece minimo una vez, "menor" va a tomar como minimo un valor.
				int newMenor = elems[C-1].front() - elems[0].front() + 1;
				if(menor > newMenor) menor = newMenor;
				elems[0].pop();
				i = 0;
			}
			else{
				++i;
			} 
		}
	}
	return menor;
}

bool resuelveCaso(){
	queue<int> cola;
	int C, N;
	cin >> C;
	if(!cin) return false;

	int clave[C];
	for(int i = 0; i < C; i++) cin >> clave[i];

	cin >> N;
	int sec[N];
	for(int i = 0; i < N; i++) cin >> sec[i];

	cout << pacticaEsteganografia(C, clave, N, sec) << endl;

	return true;
}

int main(){
	while(resuelveCaso());
	return 0;
}