//LUIS POZAS PALOMO - EDA - 05
#ifndef _SETMY
#define _SETMY

#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <algorithm>

template <class T>
class setMy {
public:
    setMy(int tam){
      contador = 0;
      capacidad = tam;
      datos = new T[tam];
    }

    ~setMy(){ libera(); }

    void insert(T e){
      if (!contains(e)) {
          if (contador < capacidad){
            datos[contador] = e;
            ++contador;
            sort(datos, datos+contador);
          }
          else {
            if(e > consultarMenor()){
              erase(consultarMenor());
              insert(e);
            }
          }
      }
    }

    bool contains(T e) const{
      int i = 0;
      while (i < contador && datos[i] != e) ++i;
      return i < contador;
    }

    void erase(T e){
      int i = 0;
      while (i < contador && datos[i] != e)
          ++i;
      if (i < contador) {
          datos[i] = datos[contador-1];
          --contador;
      } else
          throw std::domain_error("El elemento no esta");
    }

    bool empty() const{ return contador == 0; }

    int size() const{ return contador; }

    T value(int idx){return datos[idx];}

private:
    int contador;
    int capacidad;
    T * datos;

    T consultarMenor() const { return datos[0]; }

    void eliminarMenor() {
      for(int i = 0; i < capacidad-1; i++){
        datos[i] = datos[i+1];
        contador--;
      }
    }

    void libera(){delete[] datos;}
};

#endif
