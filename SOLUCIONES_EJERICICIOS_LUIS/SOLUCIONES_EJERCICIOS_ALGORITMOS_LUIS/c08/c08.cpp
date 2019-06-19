//LUIS POZAS PALOMO - EDA - C08(DIVIDE Y VENCERAS)
#include <iostream>
#include <algorithm>
using namespace std;

int unique(int V[], int i, int j){
  int h = (i+j)/2;

  if (j-i == 0) return h;
  else if (j-i == 2){
    if(V[h] != V[h+1] && V[h]==V[h-1]) return h+1;
    else if(V[h] != V[h-1] && V[h]==V[h+1]) return h-1;
    else return h;
  }
  else {
    if(V[h] != V[h-1] && V[h] != V[h+1]) return h;
    else if((h%2 == 0 && V[h] == V[h-1]) || (h%2 != 0 && V[h] != V[h-1])) unique(V, i, h);
    else if((h%2 == 0 && V[h] == V[h+1]) || (h%2 != 0 && V[h] != V[h+1])) unique(V, h, j);
  }
}

void resuelveCaso(){
  int numCasos, N;
  cin >> numCasos;
  for (int i = 0; i < numCasos; i++){
    cin >> N;
    int V[N];
    for (int j = 0; j < N; j++) cin >> V[j];
    cout << unique(V, 0, N-1) << endl;
  }
}

int main(){
  resuelveCaso();
  return 0;
}
