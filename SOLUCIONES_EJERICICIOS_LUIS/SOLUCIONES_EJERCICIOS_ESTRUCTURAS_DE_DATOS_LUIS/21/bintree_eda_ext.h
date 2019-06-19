//LUIS POZAS PALOMO - EDA - 21
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

	T menorNodo() const { //Funcion que calcula el menor nodo de un arbol
		return menorNodo(this->raiz);
	}


private:

	static T menorNodo(Link r) {
		if (r->left == nullptr && r->right == nullptr) {
			return r->elem;
		}
		else if(r->left != nullptr && r->right == nullptr){
			return min(r->elem, menorNodo(r->left));
		}
		else if(r->left == nullptr && r->right != nullptr){
			return min(r->elem, menorNodo(r->right));
		}
		else { 
			return min(r->elem, min(menorNodo(r->left), menorNodo(r->right)));
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
