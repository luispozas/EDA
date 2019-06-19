//LUIS POZAS PALOMO - EDA - EF24(BONGO) - DIVIDE Y VENCERAS
#include <iostream>
using namespace std;

int bongo(int V[], int i, int j, const int c, bool& ok){
  int h=(i+j)/2;

  if(j-i == 1){
    if (V[i] == c+h)  return V[i];
    else ok = false;
  }
  else {
    if(V[h] < c+h) return bongo(V, h, j, c, ok);
    else if (V[h] > c+h) return bongo(V, i, h, c, ok);
  }
}

void resuelveCaso(){
  int numCasos, N, cantado, tachado = 0;
  cin >> numCasos;
  for(int i = 0; i < numCasos; i++){
    cin >> N >> cantado;
    int V[N];
    bool ok = true;
    for(int j = 0; j < N; j++) cin >> V[j];
    tachado = bongo(V, 0, N, cantado, ok);
    if (ok) cout << tachado << endl;
    else cout << "NO" << endl;
  }
}

int main(){
  resuelveCaso();
  return 0;
}
