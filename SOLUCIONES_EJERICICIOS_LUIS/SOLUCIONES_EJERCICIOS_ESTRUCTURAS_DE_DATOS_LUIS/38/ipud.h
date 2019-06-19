//LUIS POZAS PALOMO - 38
#ifndef ipud_h
#define ipud_h
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <deque>
#include <set>
#include <list>
#include <utility>
#include <stdexcept>

class ipud {
private:
   using it = std::list<std::string>::iterator;
   std::unordered_map<std::string, std::pair<std::string, int>> info_ipud;
   std::unordered_map<std::string, it> info_playList;//para eliminar de la playList en O(1);
   std::unordered_map<std::string, it> info_reprod;//para eliminar de la reprod en O(1);
   std::list<std::string> playList;
   std::list<std::string> reprod;
   int time;

public: 
   ipud(){
      time = 0;
   }

   void addSong(std::string S, std::string A, int D){
      if(info_ipud.count(S)) throw std::domain_error("ERROR addSong");
      info_ipud[S] = std::make_pair(A, D);
   }

   void addToPlaylist(std::string S){
      if(!info_ipud.count(S)) throw std::domain_error("ERROR addToPlaylist");
      if(!info_playList.count(S)){
         auto it = playList.insert(playList.end(), S);
         info_playList[S] = it; //log(S) donde S -> num de canciones.
         time += info_ipud[S].second;
      }
   }

   std::string current(){
      if(playList.empty()) throw std::domain_error("ERROR current");
      return playList.front(); //O(1)
   }

   std::string play(){
      if(playList.empty()) throw std::domain_error("No hay canciones en la lista");;
      std::string c = playList.front();
      playList.pop_front();
      info_playList.erase(c);
      time -= info_ipud[c].second;
      if(info_reprod.count(c)) reprod.erase(info_reprod[c]); //para obtener la mas reciente si hay repetidas
      reprod.push_front(c);
      info_reprod[c] = reprod.begin();
      return c;
   }

   int totalTime(){
      return time;
   }

   std::vector<std::string> recent(int N){
      std::vector<std::string> v;
      auto it = reprod.begin();
      while(it != reprod.end() && v.size() < N){
         v.push_back(*it);
         ++it;
      }
      return v;
   }

   void deleteSong(std::string S){
      if(!info_ipud.count(S)) return;
      if(info_playList.count(S)){
         time -= info_ipud[S].second;
         playList.erase(info_playList[S]);
         info_playList.erase(S);
      }
      if(info_reprod.count(S)){
         reprod.erase(info_reprod[S]);
         info_reprod.erase(S);
      }
      info_ipud.erase(S);
   }
};

#endif