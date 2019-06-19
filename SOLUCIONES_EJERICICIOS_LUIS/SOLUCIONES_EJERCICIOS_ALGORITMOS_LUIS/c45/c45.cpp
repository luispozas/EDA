// LUIS POZAS PALOMO - EDA - CAMINANDO_VOY (C45).
#include <iostream>
#include <string>
using namespace std;

/*
  P{ V[0...N) and 0 <= D <= 1000000  }
    fun caminandoVoy(int V[], int D, int N) retorna (bool p)
  Q{ p = Exist i,j : 0 <= i < j < N : (forall k : i <= k < j : V[k] < V[k+1] and V[j] - V[i] <= D ) }

  I: Q[N\n] and 0 < n < N

  C(n) = N-1 - i

*/

int caminandoVoy(int V[], long long int D, long long int N){
  int i = 0;
  long long int aux = 0;
  bool fin = false;

  while (i < N-1 && !fin){
    if (V[i] < V[i+1]){
      aux = aux + (V[i+1] - V[i]);
      if (aux > D) fin = true;
    }
    else {aux = 0;}
    i++;
  }
  if (fin) return 0;
  else return 1;
}

void resuelveCaso(){
  long long int D, N;
  while (cin >> D >> N){
    int V[N];
    for (int i = 0; i < N; i++){
      cin >> V[i];
    }
    if(caminandoVoy(V, D, N) == 1) cout << "APTA" << endl;
    else cout << "NO APTA" << endl;
  }
}

int main(){
  resuelveCaso();
  return 0;
}
