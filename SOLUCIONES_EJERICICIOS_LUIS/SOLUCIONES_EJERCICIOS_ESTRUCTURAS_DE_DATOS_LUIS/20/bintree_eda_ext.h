//LUIS POZAS PALOMO - EDA - 20
#include <iostream>
#include <vector>
using namespace std;

#include "bintree_eda.h"

template <class T>

class bintree_ext : public bintree<T> {

	using Link = typename bintree<T>::Link;

public:

	bintree_ext() : bintree<T>() {}

	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

	vector<T> frontera() const { //Funcion que calcula la frontera y devuelve un vector
		vector<T> v;
		frontera(this->raiz, v); //El vector es un parametro de salida
		return v;
	}


private:

	static void frontera(Link r, vector<T> & v) {
		if (r == nullptr) {/* SKIP */} //Debo distinguir si el arbol es vacio antes de todo.
		else if (r->left == nullptr && r->right == nullptr) { //Una hoja tiene sus dos hijos a nullptr, entoces mi caso base añade el elemento;
			v.push_back(r->elem);
		}
		else { //Recorro mi arbol llamando a sus hijos.
			frontera(r->left, v);
			frontera(r->right, v);
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
