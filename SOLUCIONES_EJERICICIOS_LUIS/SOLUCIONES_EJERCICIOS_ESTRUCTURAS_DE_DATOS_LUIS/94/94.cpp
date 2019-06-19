//LUIS POZAS PALOMO - 94 - EDA
#include <iostream>
using namespace std;

#include "bintree_eda.h"	

int tramosNavegables(bintree<int> a, int& c){
	if(a.empty()) {
		c = 0;
		return 0;
	}
	else if (a.left().empty() && a.right().empty()){
		c = 1;
		return 0;
	}
	else{
		int tramos = 0, ci, cd;
		tramos += tramosNavegables(a.left(), ci);
		tramos += tramosNavegables(a.right(), cd);

		c = max(ci + cd - a.root(), 0);
		return tramos + (c >= 3);	
	}
}	

int tramosNavegablesG(bintree<int> a, int& c){
	int tramos = 0;
	tramos += tramosNavegables(a.left(), c);
	tramos += tramosNavegables(a.right(), c);
	return tramos;

}

void resuelveCaso(){
	bintree<int> a;
	int c = 1;
	a = leerArbol(-1);

	cout << tramosNavegablesG(a, c) << endl;
}

int main(){
	int numCasos;
	cin >> numCasos;
	for(int i = 0; i < numCasos; ++i){
		resuelveCaso();
	}
	return 0;
}