#include <iostream>
#include <algorithm>
using namespace std;

/*

K -> NIVELES QUE CORRESPONEN A NUMERO DE FILA.
SOL[K] -> CORESPONDE A NUMERO DE COLUMNA (SE PRUEBA POR COLUMNA).

DD [DIAGONAL DESCENDENTE] -> NUMERADAS DESDE EL 0 TOMANDO COMO 1ª DIAGONAL LA DE ARRIBA A LA DERECHA.
DA [DIAGONAL ASCENDENTE]-> NUMERADAS DESDE EL 0 TOMANDO COMO 1ª DIAGONAL LA DE ARRIBA A LA IZQUIERDA.
*** DE ESTA FORMA RESULTA MAS FACIL MARCAR LAS DIAGONALES YA QUE DEPENDEN DE LAS FILAS Y COLUMNAS
*** DOS ARRAY DISTNTOS PARA CADA TIPO DE DIAGONALES.[mismo tamaño ocupado en memoria].

Q [COLUMNAS OCUPADAS]
COMO SOLO PERMITIMOS UNA REINA EN CADA FILA (NIVEL K) NO NECESITAMOS OTRO ARRAY DE FILAS;

*/

const int MAX = 1000;

bool valida(int sol[], int k, bool DD[], bool DA[], bool Q[], const int TAM){
  if(Q[sol[k]]) return false;
  if(DA[k + sol[k]]) return false;
  if(DD[k - sol[k] + TAM-1]) return false; //SUMO TAM-1 PARA QUE LAS DIAGONALES QUEDEN NUMERADAS DE [0...2*TAM-1]
  else return true;
}

// P : true
void reinas(int sol[], int k, const int TAM, int& cont, bool DD[], bool DA[], bool Q[]){
  for(int i = 0; i < TAM; i++){
    sol[k] = i;
    if(valida(sol, k, DD, DA, Q, TAM)){
      if(k == (TAM-1)) cont++;
      else{
        Q[sol[k]] = true; //MARCAJE
        DA[k + sol[k]] = true;
        DD[k - sol[k] + TAM-1] = true;
        reinas(sol, k+1, TAM, cont, DD, DA, Q);
        Q[sol[k]] = false; //DESMARCAJE
        DA[k + sol[k]] = false;
        DD[k - sol[k] + TAM-1] = false;
      }
    }
  }
}

void resuelveCaso(){
  int sol[MAX], numCasos, TAM, cont;
  bool DD[MAX], DA[MAX];
  cin >> numCasos;
  for(int i = 0; i < numCasos; i++){
    cin >> TAM;
    bool Q[TAM];
    for(int j = 0; j < 2*TAM - 1; j++) DD[j] = false;
    for(int w = 0; w < 2*TAM - 1; w++) DA[w] = false;
    for(int t = 0; t < TAM; t++) Q[t] = false;
    cont = 0;
    reinas(sol, 0, TAM, cont, DD, DA, Q);
    cout << cont << endl;
  }
}

int main(){
  resuelveCaso();
  return 0;
}
