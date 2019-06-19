//LUIS POZAS PALOMO - 35
#ifndef carnet_puntos_h
#define carnet_puntos_h
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <utility>
#include <stdexcept>

class carnet_puntos {
private:
   std::unordered_map<std::string, std::pair<int, std::list<std::string>::iterator>> info_cond;
   std::vector<std::list<std::string>> cond_points;

public:

   carnet_puntos() {
      cond_points.assign(16, std::list<std::string>());
   }

   void nuevo(std::string dni){
      if(info_cond.count(dni)) throw std::domain_error("Conductor duplicado");
      info_cond[dni].first = 15;
      cond_points[15].push_front(dni);
      auto it1 = cond_points[15].begin();
      info_cond[dni].second = it1;
   }

   void quitar(std::string dni, int puntos){
      if(!info_cond.count(dni)) throw std::domain_error("Conductor inexistente");
      int t = info_cond[dni].first;
      info_cond[dni].first = (info_cond[dni].first - puntos) > 0? info_cond[dni].first - puntos : 0; //actualizo los datos;
      if(t != info_cond[dni].first){ //modifico la lista solo si se ha producido un cambio.
         modificoLista(dni);
      }
   }

   void recuperar(std::string dni, int puntos){
      if(!info_cond.count(dni)) throw std::domain_error("Conductor inexistente");
      int t = info_cond[dni].first;
      info_cond[dni].first = (info_cond[dni].first + puntos) <= 15? info_cond[dni].first + puntos : 15; //actualizo los datos
      if(t != info_cond[dni].first){ //modifico la lista solo si se ha producido un cambio.
         modificoLista(dni);
      }
   }

   void modificoLista(std::string dni){
      cond_points[info_cond[dni].first].erase(info_cond[dni].second);
      cond_points[info_cond[dni].first].push_front(dni);
      auto it1 = cond_points[info_cond[dni].first].begin();
      info_cond[dni].second = it1;
   }

   int consultar(std::string dni){
      if(!info_cond.count(dni)) throw std::domain_error("Conductor inexistente");
      return info_cond[dni].first;
   }

   int cuantos_con_puntos(int puntos){
      if(puntos < 0 || puntos > 15) throw std::domain_error("Puntos no validos");
      return cond_points[puntos].size();
   }

   std::vector<std::string> lista_por_puntos(int puntos){
      if(puntos < 0 || puntos > 15) throw std::domain_error("Puntos no validos");
      std::vector<std::string> v;
      for(std::string dni : cond_points[puntos]) v.push_back(dni);
      return v;
   }
};

#endif