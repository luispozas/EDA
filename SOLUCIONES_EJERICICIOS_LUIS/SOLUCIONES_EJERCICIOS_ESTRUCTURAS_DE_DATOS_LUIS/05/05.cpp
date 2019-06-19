//LUIS POZAS PALOMO - EDA - 05
#include <iostream>
#include <fstream>
using namespace std;

#include "setMy.h"

void insertNumber(setMy<int> & set_enteros){
  int n;
  while(cin >> n && n != -1) set_enteros.insert(n);
}

void insertWord(setMy<string> & set_string){
  string s;
  while(cin >> s && s != "FIN") set_string.insert(s);
}

template <class T>
void printSol(setMy<T> & conj, int k){
  for(int i = 0; i < k; i++) cout << conj.value(i) << " ";
  cout << "\n";
}

int main() {
  char caso;
  while(cin>>caso){
    int k;
    cin >> k;
    setMy<int> set_enteros(k);
    setMy<string> set_string(k);
    
    if(caso == 'N'){
      insertNumber(set_enteros);
      printSol(set_enteros, k);
    }
    else if(caso == 'P'){
      insertWord(set_string);
      printSol(set_string, k);
    }
  }
  return 0;
}
