//LUIS POZAS PALOMO - EDA - 10
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#include "inserta.h"

bool resuelveCaso(){
	ListaInserta<int> cola, cola2;
	int num, elem, p;
	if(cin >> num){
		for(int i = 0; i < num; i++) { cin >> elem; cola.push(elem); }
		cin >> num >> p;
		for(int i = 0; i < num; i++) { cin >> elem; cola2.push(elem); }

		cola.inserta(&cola2, p);

		for (int i = 0; i < cola.size() ; ++i) {
       	 int elem = cola.front(); cola.pop();
       	 cola.push(elem);
		}
		
		cout << cola << endl;
		return true;
	}
	else return false;
}

int main(){
	while(resuelveCaso());
	return 0;
}