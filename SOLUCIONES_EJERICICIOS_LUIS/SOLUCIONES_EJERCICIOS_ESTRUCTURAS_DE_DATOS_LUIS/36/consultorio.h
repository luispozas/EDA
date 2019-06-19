//LUIS POZAS PALOMO - 36
#ifndef consultorio_h
#define consultorio_h
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <utility>
#include <stdexcept>

class fecha{
private:
   int _dia;
   int _hora;
   int _minuto;

public:
   fecha(int d = 0, int h = 0, int m = 0){
      _dia = d; _hora = h; _minuto = m;
   }
   // observadoras
   int hora() const { return _hora; }
   int minuto() const { return _minuto; }
   int dia() const { return _dia; }

   bool operator < (fecha const& f) const {
      return 24*60*_dia + 60* _hora + _minuto < 24*60*f._dia + 60 * f._hora + f._minuto;
   }
};

class consultorio {
private:

   std::unordered_map<std::string, std::map<fecha, std::string>> info;

public:

   void nuevoMedico(std::string medico){
      info[medico];
   }

   void pideConsulta(std::string paciente, std::string medico, fecha f){
      if(!info.count(medico)) throw std::domain_error("Medico no existente");
      if(info[medico].count(f)) throw std::domain_error("Fecha ocupada");
      info[medico][f] = paciente;
   }

   std::string siguientePaciente(std:: string medico){
      if(!info.count(medico)) throw std::domain_error("Medico no existente");
      if(info[medico].empty())throw std::domain_error("No hay pacientes");
      auto it = info[medico].begin();
      return it->second;
   }

   void atiendeConsulta(std::string medico){
      if(!info.count(medico)) throw std::domain_error("Medico no existente");
      if(info[medico].empty())throw std::domain_error("No hay pacientes");
      auto it = info[medico].begin();
      info[medico].erase(it);
   }

   std::vector<std::string> listaPacientes(std::string medico, int dia){
      if(!info.count(medico)) throw std::domain_error("Medico no existente");
      std::vector<std::string> v;
      auto it = info[medico].begin();
      while(it != info[medico].end()){
         if(it->first.dia() == dia) {
            v.push_back(it->second);
            v.push_back(std::to_string(it->first.hora()));
            v.push_back(std::to_string(it->first.minuto()));
         }
         ++it;
      }
      return v;
   }
};

#endif