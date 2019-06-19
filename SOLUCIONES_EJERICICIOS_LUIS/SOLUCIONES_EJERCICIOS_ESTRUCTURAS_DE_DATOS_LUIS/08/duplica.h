//LUIS POZAS PALOMO - EDA - 08
#include "queue_eda.h"
#include <iostream>
using namespace std;

template <class T>
class ListaDuplica : public queue<T> {

    using Nodo = typename queue<T>::Nodo; // Para poder usar Nodo aquí

public:

    void print(std::ostream & o = std::cout) const {
    	Nodo * act = this->prim;
    	while(act != nullptr) {
    	  o << act->elem << " ";
    	  act = act->sig;
    	}
    }

    // Duplicar los nodos de una lista enlazada simple

    void duplica() {
    	Nodo * aux = this->prim;
    	Nodo * nuevo = nullptr;
    	while (aux != nullptr) {
    		nuevo = new Nodo(aux->elem, aux->sig);
    		aux->sig = nuevo;
    		aux = nuevo->sig;
    	}
    	this->ult = nuevo;
    	this->nelems = 2*this->nelems;
	}

};

inline ostream & operator<<(ostream & salida, ListaDuplica<int> const& c) {
	c.print(salida);
	return salida;
}



