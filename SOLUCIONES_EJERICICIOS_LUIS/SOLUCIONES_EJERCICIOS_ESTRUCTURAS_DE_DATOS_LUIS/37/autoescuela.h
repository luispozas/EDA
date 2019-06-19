//LUIS POZAS PALOMO - 37
#ifndef autoescuela_h
#define autoescuela_h
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <utility>
#include <stdexcept>

class autoescuela {
private:
   std::map<std::string, std::pair<std::string, int>> info;

public:

   void alta(std::string A, std::string P){
      if(info.count(A)) info[A].first = P;
      else info[A] = std::make_pair(P, 0);
   }

   bool es_alumno(std::string A, std::string P){
      return (info[A].first == P);
   }

   int puntuacion(std::string A){
      if(!info.count(A)) throw std::domain_error("El alumno"+ A +"no esta matriculado");
      return (info[A].second);
   }

   void actualizar(std::string A, int N){
      if(!info.count(A)) throw std::domain_error("El alumno"+ A +"no esta matriculado");
      info[A].second += N;
   }

   std::vector<std::string> examen(std::string P, int N){
      std::vector<std::string> v;
      auto it = info.begin();
      while(it != info.end()){
         if(it->second.first == P && it->second.second >= N) v.push_back(it->first);
         ++it;
      }
      return v;
   }

   void aprobar(std::string A){
      if(!info.count(A)) throw std::domain_error("El alumno"+ A +"no esta matriculado");
      info.erase(A);
   }
};

#endif