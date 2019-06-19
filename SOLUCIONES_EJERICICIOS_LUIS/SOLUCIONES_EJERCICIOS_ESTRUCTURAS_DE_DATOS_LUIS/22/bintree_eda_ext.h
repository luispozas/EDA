#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"

template <class T>

class bintree_ext : public bintree<T> {

	using Link = typename bintree<T>::Link;

public:

	bintree_ext() : bintree<T>() {}

	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

	int diametro() const { //Funcion que calcula el diametro mayor de un arbol.
		int alt;
		return diam(this->raiz, alt); //"alt" es un parametro de salida.
	}


private:

	static int diam(Link r, int& alt) {
		if(r == nullptr) { 
			alt = 0;
			return 0; 
		}
		else {
			int altIZQ;
 			int izq = diam(r->left, altIZQ);
 			int altDCHA;
 			int dcha = diam(r->right, altDCHA);
			alt = 1 + max(altIZQ, altDCHA); //devuelvo el maximo de la altura de sus hijos, (+1) que es en el nivel actual.
			return max(altIZQ + 1 + altDCHA, max(izq, dcha)); // devuelvo el mayor diametro entre los hijos y el actual calculado.
		}
	}
};


template <typename T>

bintree_ext<T> leerArbol_ext(T vacio) {
	T raiz;
	cin >> raiz;

	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol_ext(vacio);
		auto dr = leerArbol_ext(vacio);
		return { iz, raiz, dr };
	}
}
