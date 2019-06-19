//LUIS POZAS PALOMO - EDA - 10
#include "queue_eda.h"
#include <iostream>
using namespace std;

template <class T>
class ListaInserta : public queue<T> {

    using Nodo = typename queue<T>::Nodo; // Para poder usar Nodo aquí

public:

    void print(std::ostream & o = std::cout) const {
        Nodo * act = this->prim;
        while(act != nullptr) {
          o << act->elem << " ";
          act = act->sig;
        }
    }

    // insertar los nodos de una lista enlazada simple

    void inserta(ListaInserta<int> *list, int pos) {
        int cont = 1;
        Nodo * actual = this->prim;
        Nodo * aux = nullptr;

        if(pos == 0){ // si es la posicion es 0 asigno el puntero "prim" al de la nueva lista;
            aux = this->prim;
            this->prim = list->prim;
            list->ult->sig = aux;
        }
        else if(pos == this->nelems){ // si es la posicion es N asigno el puntero "ult" al de la nueva lista;
            this->ult->sig = list->prim;
            this->ult = list->ult;
        }
        else{
            while (cont != pos){ // recorro la cola hasta la posicion a insertar;
                actual = actual->sig;
                cont++;
            }
            aux = actual->sig; // intercambio punteros
            actual->sig = list->prim;
            list->ult->sig = aux;
        }
        this->nelems += list->nelems;
        list->prim = nullptr;
        list->ult = nullptr;
        list->nelems = 0;

    }

};

inline ostream & operator<<(ostream & salida, ListaInserta<int> const& c) {
    c.print(salida);
    return salida;
}

