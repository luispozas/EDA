//LUIS POZAS PALOMO - EDA - 84
#include "queue_eda.h"
#include <iostream>
#include <stack>
using namespace std;

template <class T>
class invierte : public queue<T> {

    using Nodo = typename queue<T>::Nodo; // Para poder usar Nodo aquí

public:
    void print(std::ostream & o = std::cout) const {
        Nodo * act = this->prim;
        while(act != nullptr) {
            o << act->elem << " ";
            act = act->sig;
        }
    }
    /*OJO!:
        Quizas haya una manera mas generica de resolverlo.
        Codigo hecho a base de probar para ver todos los posibles casos -> MAL.
        Preguntar por el codigo del profesor.
    */
    void invertir(int idx, int lenght){
        Nodo * medio = nullptr;
        Nodo * siguiente = nullptr;
        Nodo * actual = this->prim;
        Nodo * aux;
        
        for(int i = 1; i < idx-1; i++){
            actual = actual->sig;
        }
        aux = actual; //'aux' apunta al anterior.
        // Inicializo los punteros correctamente.
        if(idx != 1) actual = actual->sig;//Si se cambia el primero no me adelanto mas.
        medio = actual->sig;

        int i = 0;
        while (i < lenght-1) {
            if(medio != nullptr) {
                siguiente = medio->sig;
                medio->sig = actual;       
            }
            actual = medio;
            medio = siguiente;
            i++;
        }
        //Ajusto los extremos...
        if(idx != 1){
            aux->sig->sig = medio;
            aux->sig = actual;
        }
        else{
            if(this->nelems+1 == idx+lenght){
                this->prim = actual;
                aux->sig = nullptr;
                this->ult = aux;
            }
            else {
                aux->sig = medio;
                this->prim = actual;
            }
        }
        
    }
};

template <class T>
inline ostream & operator<<(ostream & salida, invierte<T> const& c) {
    c.print(salida);
    return salida;
}

