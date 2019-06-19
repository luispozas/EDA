//LUIS POZAS PALOMO - 93 - EDA
#include <iostream>
#include <sstream>
using namespace std;

#include "bintree_eda.h"

bool esSimetrico(bintree<char> a, bintree<char> b){
	if(a.empty()){
		return (b.empty());
	}
	else if(b.empty()){
		return (a.empty());
	}
	else {
		return (esSimetrico(a.left(), b.right()) && esSimetrico(a.right(), b.left()));
	}
}	

void resuelveCaso(){
	bintree<char> a;
	a = leerArbol('.');

	if(esSimetrico(a.left(), a.right())) cout << "SI" << endl;
	else cout << "NO" << endl;
}

int main(){
	int numCasos;
	cin >> numCasos;
	for(int i = 0; i < numCasos; ++i){
		resuelveCaso();
	}
	return 0;
}