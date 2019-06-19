//LUIS POZAS PALOMO - 91 - EDA
#include <iostream>
#include <sstream>
using namespace std;

#include "bintree_eda.h"

bool esGenealogico(bintree<int> a, int& hout){
	if(a.empty()) {
		hout = 0;
		return true;
	}
	else if(a.left().empty() && a.right().empty()){
		hout = 1;
		return true;
	}
	else{
		bool izq, dcha;
		int hizq, hdcha;
		izq = esGenealogico(a.left(), hizq);
		dcha = esGenealogico(a.right(), hdcha);
		hout = hizq > hdcha? 1 + hizq : 1 + hdcha;

		if(!a.left().empty() && !a.right().empty()){
			return (izq && dcha && a.root() - a.left().root() >= 18 && a.root() - a.right().root() >= 18 &&
				a.left().root() - a.right().root() >= 2);
		}
		else if(!a.left().empty()){
			return (izq && dcha && a.root() - a.left().root() >= 18);
		}
		else {
			return false;
		}
	}
}						

void resuelveCaso(){
	bintree<int> a;
	int hout = 0;
	a = leerArbol(-1);

	bool is = esGenealogico(a, hout);

	if(is) cout << "SI " << hout << endl;
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