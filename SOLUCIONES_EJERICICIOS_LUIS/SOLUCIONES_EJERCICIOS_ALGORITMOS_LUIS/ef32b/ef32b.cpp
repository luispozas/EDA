//LUIS POZAS PALOMO - EDA - EF32B (TORRES / BACKTRACKING)
#include <iostream>
#include <algorithm>
using namespace std;

const long long int MAX = 10000;
const int P = 3;
typedef enum {azul, rojo, verde} tPiezas;

void printSol(int T, int cont[], tPiezas sol[]){
  for(int i = 0; i < T; i++){
    switch(sol[i]){
      case rojo: cout << "rojo"; break;
      case azul: cout << "azul"; break;
      case verde: cout << "verde"; break;
    }
    cout <<" ";
  }
  cout << endl;
}

bool valida(tPiezas sol[], int cont[], int k, int i, const int numCol[], const int T){
  bool ok = true;
  cont[i]++; //MARCAR
  if(sol[k-1] == verde && sol[k] == verde) ok = false;
  else if(cont[2] > cont[0]) ok = false;
  else if (cont[i] > numCol[i]) ok = false;
  else if (T%2 == 0 && (cont[0]+cont[2]) > (T/2)-1) ok = false;
  else if (T%2 != 0 && (cont[0]+cont[2]) > (T/2)) ok = false;
  cont[i]--; //DESMARCAR
  return ok;
}

void torresColores(tPiezas sol[], int k, const int T, const int numCol[], int cont[], bool& noSol){
  for(int i = 0; i < P; i++){
        sol[k] = static_cast<tPiezas>(i);
        if(valida(sol, cont, k, i, numCol, T)){
          if(k == T-1){
            printSol(T, cont, sol);
            noSol=true;
          }
          else{
            cont[i]++; //MARCAJE
            torresColores(sol, k+1, T, numCol, cont, noSol);
            cont[i]--; //DESMARCAJE
          }
        }
  }
}

void resuelveCaso(){
  int T, numCol[P];
  tPiezas sol[MAX];
  while(cin >> T >> numCol[0] >> numCol[1] >> numCol[2] && T!=0){
    int cont[P] = {0,0,0};
    bool noSol = false;
    sol[0]= static_cast<tPiezas>(1);
    cont[1]++;
    torresColores(sol, 1, T, numCol, cont, noSol);
    if(!noSol) cout << "SIN SOLUCION" << endl << endl;
    else cout << endl;
  }
}

int main(){
  resuelveCaso();
  return 0;
}
