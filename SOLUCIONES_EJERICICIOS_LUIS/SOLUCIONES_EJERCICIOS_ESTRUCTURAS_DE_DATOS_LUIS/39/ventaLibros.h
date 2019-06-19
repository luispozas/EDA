/*
LUIS POZAS PALOMO - 39

Todas las operaciones tienen como coste peor LOG(N) ya que como
maximo hay que buscar en el mapa donde esta la clave para operar
con el valor.

La operacion top10 puedo decir que es constante ya que solo
recorre 10 elementos.

*/
#ifndef ventaLibros_h
#define ventaLibros_h
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <deque>
#include <set>
#include <list>
#include <utility>
#include <stdexcept>

class ventaLibros {
private:
   //libro -> ((ejemplares, ventas), it);
   //ventas -> list(libros);
   using it = std::list<std::string>::iterator;
   std::map<std::string, std::pair<std::pair<int, int>, it>> sistema;
   std::map<int, std::list<std::string>> top;


public:

   void nuevoLibro(int n, std::string x){
      if(n==0) sistema[x].first.first = 0;
      else if(sistema.count(x)){
         sistema[x].first.first += n;
      }
      else sistema[x].first = std::make_pair(n, 0);
   }

   bool estaLibro(std::string x){
      return sistema.count(x);
   }

   void comprar(std::string x){
      if(!sistema.count(x)) throw std::invalid_argument("Libro no existente");
      if(sistema[x].first.first == 0) throw std::out_of_range("No hay ejemplares");
      sistema[x].first.first--;
      if(sistema[x].first.second > 0){ //Esta en la lista de comprados y lo actualizo.
         top[sistema[x].first.second].erase(sistema[x].second);
      }
      sistema[x].first.second++;
      top[sistema[x].first.second].push_front(x);
      sistema[x].second = top[sistema[x].first.second].begin();//Actualizo puntero a la nueva posicion.
   }

   void elimLibro(std::string x){
      if(sistema.count(x)){
         if(sistema[x].first.second > 0){ //Esta en la lista de comprados y lo borro.
            top[sistema[x].first.second].erase(sistema[x].second);
            if(top[sistema[x].first.second].empty()) {
               top.erase(sistema[x].first.second);
            }
         }
         sistema.erase(x);
      }
   }

   int numEjemplares(std::string x){
      if(!sistema.count(x)) throw std::invalid_argument("Libro no existente");
      return sistema[x].first.first;
   }

   std::vector<std::string> top10(){
      std::vector<std::string> v;
      int i = 0;
      auto it = top.rbegin(); //Recorro el mapa al reves.
      while(it != top.rend() && i < 10){//Tomo todos los elementos o solo 10.
         auto itList = it->second.begin();
         while(itList != it->second.end() && i < 10){//Recorro la lista asociada a cada clave del mapa.
            v.push_back(*itList);
            i++;
            ++itList;
         }
         ++it;
      }
      return v;
   }
};

#endif