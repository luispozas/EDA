//LUIS POZAS PALOMO - EDA - 83
#include "deque_eda.h"
#include <iostream>
using namespace std;

template <class T>
class engorda : public deque<T> {

    using Nodo = typename deque<T>::Nodo; // Para poder usar Nodo aquí

public:
    void print(std::ostream & o = std::cout) const {
        Nodo * act = this->fantasma->sig;
        while(act != this->fantasma) {
            o << act->elem << " ";
            act = act->sig;
        }
   }

    void engordar(engorda<T> d){
        bool insert = true; //TRUE inserta por delante y FALSE por detras.
        Nodo * in = d.fantasma->sig;
        Nodo * aux;
        Nodo * siguiente;
        while (in != d.fantasma) {
            if(insert) aux = this->fantasma;
            else aux = this->fantasma->ant;

            siguiente = in->sig; //Guardo el siguiente para poder avanzar luego.

            in->sig = aux->sig; //intercambio los valores con aux que va alternandose
            aux->sig->ant = in;
            aux->sig = in;
            in->ant = aux;

            in = siguiente;
            insert = insert? false: true;
            this->nelems++;
        }
        d.nelems = 0; //Dejo la cola del parametro en condicciones optimas.
        d.fantasma->sig = d.fantasma->ant = d.fantasma;
    }

};

template <class T>
inline ostream & operator<<(ostream & salida, engorda<T> const& c) {
    c.print(salida);
    return salida;
}

