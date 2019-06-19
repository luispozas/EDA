//LUIS POZAS PALOMO - EDA - WORD_COUNT(C10)
#include <iostream>
#include <string>
using namespace std;

/*
	P{ char V[0...N) and  N>=0 }
		fun contarPalabras(char V[], N) return int c
  Q{ c = #t: 0 <= t < N : Exist i, j : 0 <= i <= j < N : (V[i] != ' ') and ...
      ... and (forall k : i <= k < j : V[k] != ' ') and  ((V[j] == ' ') or (j+1 == N)) }

    i                       j       N
+...+-----+-----+-----+-----+-----+
    |  H  |  O  |  L  |  A  |     |
+...+-----+-----+-----+-----+-----+

    i                 j       N
+...+-----+-----+-----+-----+
    |  H  |  O  |  L  |  A  |
+---+-----+-----+-----+-----+


	I: Q[N\n] and 0 <= n < N

	Q(n) = N - j

*/

int contarPalabras(string frase, long long int N){
  int j = 0, cont = 0;
  while(j < N){
    if(frase[j] != ' '){
      if ((j+1 < N && frase[j+1] == ' ') || j+1 == N) cont ++;
    }
    j++;
  }
  return cont;
}

void resuelveCaso(){
  string frase;
  long long int N;
  while (getline(cin, frase)){
		N = frase.length();
    cout << contarPalabras(frase, N) << endl;
  }
}

int main(){
  resuelveCaso();
  return 0;
}
