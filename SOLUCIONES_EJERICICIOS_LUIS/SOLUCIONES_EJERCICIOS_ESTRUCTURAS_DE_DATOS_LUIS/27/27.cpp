//LUIS POZAS PALOMO - 27 - EDA
#include <iostream>
#include <sstream>
using namespace std;

#include "bintree_eda.h"

bintree<int> reconstruccionArbolBusqueda(vector<int> & preorden, int izq, int dcha){
	if(izq > dcha){
		bintree<int> a1;
		return a1;
	}
	else if(izq == dcha){
		bintree<int> a2(preorden[izq]);
		++izq;
		return a2;
	}
	else{
		int i = izq + 1;
		int val = preorden[izq];
		while(i <= dcha && val > preorden[i]) ++i;
		
		bintree<int> _left = reconstruccionArbolBusqueda(preorden, izq+1, i-1);
		bintree<int> _right = reconstruccionArbolBusqueda(preorden, i, dcha);
		bintree<int> a3(_left, val, _right);
		return a3;
	}
}

bool resuelveCaso(){
	vector<int> preorden;
	vector<int> inorden;
	vector<int> postorder;
	bintree<int> a;
	int valor;
	string linea;

    getline(cin, linea);
    if(!cin) return false;
    stringstream s1(linea);
    while (s1 >> valor) {
    	preorden.push_back(valor);
    }

    int pos = 0;
    a = reconstruccionArbolBusqueda(preorden, 0, preorden.size()-1);
    postorder = a.postorder();
    
    int N = postorder.size();
    for(int i = 0; i < N; ++i){
    	cout << postorder[i] <<" ";
    }
    cout << endl;
    return true;
}

int main(){
	while(resuelveCaso());
	return 0;
}