//LUIS POZAS PALOMO - EDA - BACKTRACKING(C24).
#include <iostream>
#include <algorithm>
using namespace std;

//POR QUE SOLO SALe CON NUMEROS IMPARES????????

const int MAX = 100;

void printSol(int sol[], const int W){
  for(int i = 0; i < W; i++) cout << sol[i] << " ";
  cout << endl;
}

void domino(int sol[], int k, const int W, const int TAM, int marcar[][MAX/2], bool& stop){
  for(int i = 0; i < TAM && !stop; i++){
    if(!marcar[min(sol[k-1], i)][max(sol[k-1],i)]){
      sol[k] = i;
      if(k == (W-1)){
        stop = true;
        printSol(sol, W);
      }
      else{
        marcar[min(sol[k-1], i)][max(sol[k-1],i)] = true;
        domino(sol, k+1, W, TAM, marcar, stop);
        marcar[min(sol[k-1], i)][max(sol[k-1],i)] = false;
      }
    }
  }
}

void resuelveCaso(){
  int sol[MAX], numCasos, TAM, marcar[MAX/2][MAX/2], W;
  bool stop;
  cin >> numCasos;
  for(int i = 0; i < numCasos; i++){
    cin >> TAM;
    for(int j = 0; j < TAM; j++){
      for(int w = 0; w < TAM; w++) marcar[j][w] = false;
    }
    sol[0] = TAM -1;
    sol[1] = TAM -1;
    marcar[TAM-1][TAM-1] = true;
    stop = false;
    W = (((TAM*TAM) + TAM) / 2) + 1;
    domino(sol, 2, W, TAM, marcar, stop);
  }
}

int main(){
  resuelveCaso();
  return 0;
}
