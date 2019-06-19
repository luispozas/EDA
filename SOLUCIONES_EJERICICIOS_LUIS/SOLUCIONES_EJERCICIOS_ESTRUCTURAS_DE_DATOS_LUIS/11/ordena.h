//LUIS POZAS PALOMO - EDA - 11
#include "queue_eda.h"
#include <iostream>
using namespace std;

template <class T>
class ListaOrdenada : public queue<T> {

    using Nodo = typename queue<T>::Nodo; // Para poder usar Nodo aquí

public:

    void print(std::ostream & o = std::cout) const {
        Nodo * act = this->prim;
        while(act != nullptr) {
          o << act->elem << " ";
          act = act->sig;
        }
    }

    void ordenar(ListaOrdenada<int> *c2){
       Nodo * antA = this->prim;
       Nodo * actA = this->prim;
       Nodo * actB = c2->prim;

        if(actA != nullptr && actB != nullptr){ // Resuelvo primer caso Ordenando los primeros elementos.
            if(actA->elem >= actB->elem){ //Pongo en su sitio correcto el anterior y el actual de A.
                this->prim = actB;
                actB = actB->sig;
                this->prim->sig = actA;
                antA = this->prim;
            }
            else {
                actA = actA->sig;
                antA = this->prim;
            }
        }
       
       while (actA != nullptr && actB != nullptr){ //Recorro haciendo intercambios los valores del medio de la lista
            if(actA->elem >= actB->elem){
                antA->sig = actB;
                actB = actB->sig;
                antA = antA->sig;
                antA->sig = actA;
            }
            else {
                actA = actA->sig;
                antA = antA->sig;
            }
       }

       if(actA == nullptr && actB != nullptr){ // Si se ha salido por que B tiene mas valores que A se los asigno a A.
            if(antA != nullptr) antA -> sig = actB; //Distingo el caso de que nos den una lista vacia, en este caso no ya que antA != null;
            else this->prim = actB; //Caso en el que la lista es vacia, añado el puntero de "prim" de B a A.
            this->ult = c2->ult;
       }

       this->nelems += c2->nelems; //Finalmente dejo todo en un estado coherente.
       c2->prim = nullptr;
       c2->ult = nullptr;
       c2->nelems = 0;

    }

};

inline ostream & operator<<(ostream & salida, ListaOrdenada<int> const& c) {
    c.print(salida);
    return salida;
}

