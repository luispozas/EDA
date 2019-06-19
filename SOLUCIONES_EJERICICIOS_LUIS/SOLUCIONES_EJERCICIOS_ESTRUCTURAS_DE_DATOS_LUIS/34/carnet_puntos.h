//LUIS POZAS PALOMO - 34
#ifndef carnet_puntos_h
#define carnet_puntos_h
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

class carnet_puntos {
private:

   std::vector<int> num_cond;
   std::unordered_map<std::string, int> info_cond;

public:
   carnet_puntos() {
      num_cond.assign(16,0);
   }

   void nuevo(std::string dni){
      if(info_cond.count(dni)) throw std::domain_error("Conductor duplicado");
      info_cond.insert(make_pair(dni, 15));
      num_cond[15]++;
   }

   void quitar(std::string dni, int puntos){
      if(!info_cond.count(dni)) throw std::domain_error("Conductor inexistente");
      num_cond[info_cond[dni]]--;
      if((info_cond[dni] - puntos) > 0) info_cond[dni] -= puntos;
      else info_cond[dni] = 0;
      num_cond[info_cond[dni]]++;
   }

   int consultar(std::string dni){
      if(!info_cond.count(dni)) throw std::domain_error("Conductor inexistente");
      return info_cond[dni];
   }

   int cuantos_con_puntos(int puntos){
      if(puntos < 0|| puntos > 15) throw std::domain_error("Puntos no validos");
      return num_cond[puntos];
   }
};

#endif