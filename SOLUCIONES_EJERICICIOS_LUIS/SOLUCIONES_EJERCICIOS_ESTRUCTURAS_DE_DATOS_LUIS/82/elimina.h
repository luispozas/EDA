//LUIS POZAS PALOMO - EDA - 81
#include "queue_eda.h"
#include <iostream>
using namespace std;

template <class T>
class elimina : public queue<T> {

    using Nodo = typename queue<T>::Nodo; // Para poder usar Nodo aquí

public:
   void print(std::ostream & o = std::cout) const {
      Nodo * act = this->prim;
      while(act != nullptr) {
         o << act->elem << " ";
         act = act->sig;
      }
   }

   void eliminaMenores(){
      Nodo * a = this->prim;
      Nodo * b = this->prim;
        
      while(a != nullptr){
         b = a->sig;
         if(b!=nullptr){
            if(a->elem > b->elem){ //Si es b es menor le quito
              a->sig = b->sig;
              delete b;
              this->nelems--;
              if(a->sig == nullptr){ //miro si acaba para poner todo correctamente.
                this->ult = a;
              }
            }
            else a = a->sig; // avanzo a si todo va bien para mirar el siguiente
         }   
         else a = a->sig; //si b es nullptr avanzo a para que acabe;  
      }
   }

};

template <class T>
inline ostream & operator<<(ostream & salida, elimina<T> const& c) {
    c.print(salida);
    return salida;
}

