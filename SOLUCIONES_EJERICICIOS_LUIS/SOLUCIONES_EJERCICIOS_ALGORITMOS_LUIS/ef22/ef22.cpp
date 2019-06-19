//LUIS POZAS PALOMO - EDA - EF22(DIVIDE Y VENCERAS)
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 10000;

int vectOrdParcialG(int V[], int i, int j, int maxim, bool& ok){
  int h=(i+j)/2, minI, maxD, maxI, minD;

  if(j-i == 1){
    maxim = V[i];
    return V[i];
  }
  else {
    if(ok){
      minI = vectOrdParcialG(V, i, h, maxim, ok);
      maxI = maxim; //SI HAGO COUT AQUI DE MAXIM POR QUE ME SALE UNA DIRECCION DE MEMORIA Y NO UN VALOR
      minD = vectOrdParcialG(V, h, j, maxim, ok);
      maxD = maxim;

      if(minI > minD || maxD < maxD) ok = false;
      else{
        maxim = max(maxI, maxD);
        return min(minI, minD);
      }
    }
  }
}

void resuelveCaso(){
  int V[MAX], e, end;
  while(cin>>end && end!=0){
    int i=0, maxim;
    V[i++] = end;
    while(cin >> e && e!=0){
      V[i]=e;
      i++;
    }
    bool ok = true;
    vectOrdParcialG(V, 0, i, maxim, ok);
    if (ok) cout << "SI" << endl;
    else cout << "NO" << endl;
  }
}

int main(){
  resuelveCaso();
  return 0;
}
