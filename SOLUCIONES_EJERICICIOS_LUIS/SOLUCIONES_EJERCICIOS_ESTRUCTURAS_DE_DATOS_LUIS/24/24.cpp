//LUIS POZAS PALOMO - 24 - EDA
#include <iostream>
#include <sstream>
using namespace std;

#include "bintree_eda.h"

bintree<int> reconstruccion(vector<int> & preorden, vector<int> & inorden, int& pos, int izq, int dcha){
	if(izq > dcha){
		bintree<int> a1;
		return a1;
	}
	else if(izq == dcha){
		bintree<int> a2(preorden[pos]);
		++pos;
		return a2;
	}
	else{
		int i = izq;
		int val = preorden[pos];
		while(inorden[i] != val) ++i;
		++pos;
		bintree<int> _left = reconstruccion(preorden, inorden, pos, izq, i-1);
		bintree<int> _right = reconstruccion(preorden, inorden, pos, i+1, dcha);
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

    getline(cin, linea);
    stringstream s2(linea);
     while (s2 >> valor) {
    	inorden.push_back(valor);
    }

    int pos = 0;
    a = reconstruccion(preorden, inorden, pos, 0, preorden.size()-1);
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