//LUIS POZAS PALOMO  - EDA - ROTACIONES(C20)
#include <iostream>
using namespace std;

/*
{ P : V [0..N) ∧ W[0..N) ∧ N ≥ 0}
  fun rotate(int V,int W, int N) return b boolean
{Q : b = ∀i : 0 ≤ i < N : V [i] = W[(i + M)%N]}
where (0 ≤ M ≤ N) and (M < N → V [0] = W[M]))

I: Q[N/n] and 0 <= n <= N

C(n): N - i

/INIT/:
i = 0, M = (i : /forall i : 0 <= i < N: V[0] = V[i]);

/AVANCE/:
i = i + 1;
M = ++M % N;

/RESTAURE/:
if (V[i] != W[M]) return false;

*/

bool rotaciones(int V[], int W[], int N){
  int i = 0, M = 0;
  bool ok = false;

  while (M <= N && !ok){
    if (V[0] == W[M]) ok = true;
    else M++;
  }

  while (i < N){
    if (V[i] != W[M]) return false;
    i++;
    M = ++M % N;
  }
  return true;
}

void resuelveCaso(){
  int N;
  while(cin >> N){
    int V[N], W[N];
    for (int i = 0; i < N; i++) cin >> V[i];
    for (int j = 0; j < N; j++) cin >> W[j];
    if(N>0){
      if(rotaciones(V, W, N)) cout << "TRUE" << endl;
      else cout << "FALSE" << endl;
    }
    else if(N == 0) cout << "TRUE" << endl;
  }
}

int main(){
  resuelveCaso();
  return 0;
}
