//LUIS POZAS PALOMO - EDA - BANDERA_HOLANDESA(C12)
#include <iostream>
using namespace std;

/*

P{ char V[0...N) and N >= 0 }
proc banderaHolandesa(in/out char V[0...N), int N)
Q{ Exist w, b : 0 <= w <= b < N : (forall k, z, i : 0 <= k < w <= z <= b < i < N) : V[k] = 'r' and V[z] = 'w' and V[i] = 'b') }
where

I: Q[N\n] and 0 <= n < N.

C(n) = b - i;

*/

void banderaHolandesa(char V[], int N){
  int i = 0, b = N-1, w = 0;
  while (i <= b){
    if(V[i]=='w'){
      i++;
    }
    else if(V[i] == 'r'){
      V[i] = V[w];
      V[w]='r';
      w++;
      i++;
    }
    else if (V[i] == 'b'){
      V[i] = V[b];
      V[b] = 'b';
      b--;
    }
  }
}

void resuelveCaso(){
  int num, N;
  cin >> num;
  for (int i = 0; i < num; i++){
    cin >> N;
    char V[N];
    for (int j = 0; j < N; j++) cin >> V[j];
    banderaHolandesa(V, N);
    for (int k = 0; k < N; k++) cout << V[k];
    cout << endl;
  }
}

int main(){
  resuelveCaso();
  return 0;
}
