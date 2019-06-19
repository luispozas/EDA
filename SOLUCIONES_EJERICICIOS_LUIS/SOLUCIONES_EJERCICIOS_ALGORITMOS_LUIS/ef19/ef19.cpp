//LUIS POZAS PALOMO - EDA - "La casita de Heidi" (EF19)
#include <iostream>
#include <algorithm>
using namespace std;

/*

  { V[0...N) de naturales and l > 1 and A[0...N) }
    proc buscarLlano(int V[], int N, int l, inout int secMax, inout int numTram, inout int A[])
  { [secMax = max i,j : 0 <= i < j < N and tramo(V, N, l, i, j) : (j+1)-i] and ...
      ...and [ numTram = #t : 0 <= t < N : (Exist i, j : 0 <= i < j < N : tramo(V, N, l, i, j)) ] and ...
      ...and [ A[n] = max k : (Exist i, j : 0 <= i < k <= j < N : tramo(V, N, l, i, j)) : V[k]) }

  Donde:
      equals(V, i, j) = { \forall k : i <= k < j : V[k] = V[k+1] }
      mayordcha(V, N, j) = { \forall w : j < w < N : V[j] > V[w] }
      tramo(V, N, l, i, j) = { equals(V, i, j) and mayordcha(V, N, j) and (j+1)-i >= l }


  I = Q[n\N] and 0 <= n < N


  C(n) = i >= 0


  Init:
  -----
  i, c, aux = N-1, 1, 0;

  Step:
  -----
  i = i - 1;

  Restore:
  --------
  aux = max(V[i], aux);
  if (V[i] == V[i-1] && aux <= V[i] && i>0)
      c++
  else
    if (c >= secMax && c >= l)
        secMax = c;
    if (c >= l)
        A[numTram++] = (i+(c-1));

    c = 1;

*/

void buscarLlano(int V[], int N, int l, int& secMax, int& numTram, int A[]) {
  int i = N-1, c = 1, aux = 0;
  while(i >= 0){
    aux = max(V[i], aux);
    if(i>0 && V[i] == V[i-1] && aux <= V[i]) c++;
    else {
      if (c >= secMax && c >= l) secMax = c;
      if (c >= l) A[numTram++] = (i+(c-1));
      c = 1;
    }
    i--;
  }
}

void resuelveCaso(){
  int N, l;
  while (cin >> N >> l){
    int V[N], A[N], secMax = 0, numTram = 0;
    for (int i = 0; i < N; i++) cin >> V[i];
    buscarLlano(V, N, l, secMax, numTram, A);
    cout << secMax << " " << numTram << " ";
    for (int j = 0; j < numTram; j++) cout << A[j] << " ";
    cout << endl;
  }
}

int main(){
  resuelveCaso();
  return 0;
}
