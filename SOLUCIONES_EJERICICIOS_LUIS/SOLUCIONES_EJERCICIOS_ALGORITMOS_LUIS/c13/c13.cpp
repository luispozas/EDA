//LUIS POZAS PALOMO - EDA - BANDERA_ARCOIRIS(C13)
#include <iostream>
using namespace std;

const int MAX = 6;

/*
P { V[0...N) = W[0...N) and N >= 0 }
proc banderaArcoiris(in out int V[], int N)
Q { \forall i : 0 <= i < N : sorted(W, N) and permut(V, W, N) } //CAMBIAR

where:
  Sorted(A, N) : \forall i : 0 <= i < N-1 : V[i] <= V[i+1]
  permut(V, W, N) : per(V, W, N) and per(W, V, N)
  per(V, W, N) : \forall i : 0 <= i < N : (Exist j : 0 <= j < N : V[i] = W[j])

I: Q[N\n] and 0 <= n < N

C(n): N - j >= 0

*/

void banderaArcoiris(int V[], int N){
  int i = 0, j = 0, var = 0;
  int A[MAX] = {0, 0, 0, 0, 0, 0};
  while (i < N){
    switch (V[i]){
      case 0: A[0]++; break;
      case 1: A[1]++; break;
      case 2: A[2]++; break;
      case 3: A[3]++; break;
      case 4: A[4]++; break;
      case 5: A[5]++; break;
    }
    i++;
  }
  while (j < N){
    if (A[var] > 0) {V[j] = var; j++; A[var]--;}
    else var++;
  }
}

void resuelveCaso(){
  int numCasos, N;
  cin >> numCasos;
  for (int i = 0; i < numCasos; i++){
    cin >> N;
    int V[N];
    for (int j = 0; j < N; j++) cin >> V[j];
    banderaArcoiris(V, N);
    for (int k = 0; k < N; k++) cout << V[k] << " ";
    cout << endl;
  }
}

int main(){
  resuelveCaso();
  return 0;
}
