//LUIS POZAS PALOMO - EDA - 09
#include "queue_eda.h"
#include <iostream>
using namespace std;

template <class T>
class ListaInvierte : public queue<T> {

    using Nodo = typename queue<T>::Nodo; // Para poder usar Nodo aquí

public:

    void print(std::ostream & o = std::cout) const {
        Nodo * act = this->prim;
        while(act != nullptr) {
          o << act->elem << " ";
          act = act->sig;
        }
    }

    // Invertir los nodos de una lista enlazada simple

    void invierte() {
        Nodo * actual = this->prim;
        Nodo * medio = nullptr;
        Nodo * siguiente = nullptr;
        // Inicializo los punteros correctamente.
        this->ult = actual;
        if(actual != nullptr) medio = actual->sig;
        else { medio = nullptr; this->prim = nullptr; }

        while (actual != nullptr) {
            if(medio != nullptr) {
                siguiente = medio->sig;
                medio->sig = actual;       
            }
            this->prim = actual; //Voy asignando el puntero del primer nodo al ultimo que voy tratando. 
            actual = medio;
            medio = siguiente;
        }
    }

};

inline ostream & operator<<(ostream & salida, ListaInvierte<int> const& c) {
    c.print(salida);
    return salida;
}

