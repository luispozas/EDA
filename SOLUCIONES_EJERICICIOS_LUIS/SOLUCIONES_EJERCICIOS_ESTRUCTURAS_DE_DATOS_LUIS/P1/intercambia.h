//LUIS POZAS PALOMO - EDA - 11
#include "queue_eda.h"
#include <iostream>
using namespace std;

template <class T>
class Intercambia : public queue<T> {

    using Nodo = typename queue<T>::Nodo; // Para poder usar Nodo aquí

public:

    void print(std::ostream & o = std::cout) const { 
        Nodo * act = this->prim;
        while(act != nullptr) {
            o << act->elem << " ";
            act = act->sig;
        }
    }

    // Intercambiar los nodos de una lista enlazada simple
    void intercambia(){
        if (this->nelems < 2) return;

        Nodo * a = this->prim;
        Nodo * prev = nullptr;

        while (a != nullptr && a->sig != nullptr) {
            Nodo * aux = a->sig;
            a->sig = aux->sig;
            aux->sig = a;
            if (prev == nullptr)
                this->prim = aux;
            else
                prev->sig = aux;
            prev = a;
            a = a->sig;
        }
        if(a != nullptr && a->sig == nullptr) this->ult = a;
        else this->ult = prev;
    }

};

template <class T>
inline ostream & operator<<(ostream & salida, Intercambia<T> const& c) {
    c.print(salida);
    return salida;
}

