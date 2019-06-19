//LUIS POZAS PALOMO - EDA - 19
#include <iostream>
using namespace std;

#include "bintree_eda.h"

template <class T>

class bintree_ext : public bintree<T> {

	using Link = typename bintree<T>::Link;

public:

	bintree_ext() : bintree<T>() {}

	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}



	size_t altura() const {
		return altura(this->raiz);
	}

	size_t  nodos() const {
		return nodos(this->raiz);
	}

	size_t hojas() const {
		return hojas(this->raiz);
	}
	

private:

	static size_t hojas(Link r) {
		if (r == nullptr) return 0; //debo distinguir si el arbol es vacio antes de todo.
		else if (r->left == nullptr && r->right == nullptr) { //Una hoja tiene sus dos hijos a nullptr, entoces mi caso base retorna 1;
			return 1;
		}
		else {
			return hojas(r->left) + hojas(r->right); //Sumo las hojas de todas las ramas.
		}
	}

	static size_t nodos(Link r) {
		if (r == nullptr) {
			return 0;
		}
		else {
			return 1 + nodos(r->left) + nodos(r->right); //Por cada nodo, sumo los nodos de sus hijos mas el mismo.
		}
	}

	static size_t altura(Link r) {
		if (r == nullptr) {
			return 0;
		}
		else {
			return 1 + max(altura(r->left), altura(r->right));
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
