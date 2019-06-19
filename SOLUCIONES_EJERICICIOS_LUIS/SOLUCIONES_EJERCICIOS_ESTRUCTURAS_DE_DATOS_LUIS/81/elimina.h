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

   void eliminaPares(){
      Nodo * a = this->prim;
      Nodo * b = this->prim;
        
      while(a != nullptr){
         b = a->sig;
         if(b!=nullptr){
            a->sig = b->sig;
            delete b;
         }
         if(a->sig == nullptr){
            this->ult = a;
         }
         a = a->sig;
         this->nelems--;
      }
   }

};

template <class T>
inline ostream & operator<<(ostream & salida, elimina<T> const& c) {
    c.print(salida);
    return salida;
}

