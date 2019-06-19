//LUIS POZAS PALOMO - EDA - 03
#include <iostream>
#include <fstream>
using namespace std;

#include "complejo.h"


bool resuelveCaso() {
  float real, imaginaria;
  int numIt;
  cin >> real >> imaginaria >> numIt;

  complejo c_ant(0, 0), c_act, c(real, imaginaria);
  bool diverge = false;
  for (int i = 0; i < numIt && !diverge; i++){
    c_act = c_ant*c_ant + c;
    if(c_act.module() > 2) diverge = true;
    c_ant = c_act;
  }

  if(!diverge) cout <<"SI\n";
  else cout <<"NO\n";
	return true;
}

int main() {
  int casos;
  cin>> casos;
  for(int i = 0; i < casos; i++) resuelveCaso();
	return 0;
}
