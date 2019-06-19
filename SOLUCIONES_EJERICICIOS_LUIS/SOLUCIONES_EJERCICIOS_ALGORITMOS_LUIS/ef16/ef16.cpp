//LUIS POZAS PALOMO - EDA - EF16(DEGRADADO) - DIVIDE Y VENCERAS
#include <iostream>
using namespace std;


int degradadoG(int V[], int i, int j, bool& correct, int izq, int dcha){
  int h=(i+j)/2;

  if(j-i == 1) return V[i];
  else {
    if (correct){
      izq = degradadoG(V, i, h, correct, izq, dcha);
      dcha = degradadoG(V, h, j, correct,  izq, dcha);
      if(izq > dcha) correct = false;
      else return izq + dcha;
    }
    else return -1;
  }
}

void resuelveCaso(){
  int F, C;
  while(cin >> F >> C){
    int V[C];
    bool correct = true;
    for(int i = 0; i < F; i++){
      int izq = 0, dcha = 0;
      for(int j = 0; j < C; j++) cin >> V[j];
      degradadoG(V, 0, C, correct, izq, dcha);
    }
    if (!correct) cout << "NO" << endl;
    else cout << "SI" << endl;
  }
}

int main(){
  resuelveCaso();
  return 0;
}
