//LUIS POZAS PALOMO - EDA - 14
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#include "deque_eda.h"
#include "stack_eda.h"

bool esVocal(char c){
	c = tolower(c);
	return (c == 'a' || c == 'e'|| c == 'i'|| c == 'o'|| c == 'u');
}

bool resuelveCaso(){
	deque<char> cola;
	stack<char> pila;
	string text;
	int start;

	if(!cin) return false; 
	getline(cin, text); //Leo la entrada en un string

	if(text.size()%2 == 0) start = 1; //inicializo "start" para empezar añadiendo a la cola por alante o por detras(impar vs par)
	else start = 0;

	for(int i = text.size()-1; i >= 0; i--){ // PRIMER paso del mensaje del codigo insertando en una cola por alante y por detras
		if(!start) cola.push_front(text[i]);
		else cola.push_back(text[i]);
		start = (start == 1) ? 0 : 1;
	}

	while(!cola.empty()){ //SEGUNDO paso usando una pila
		if(esVocal(cola.front())) {
			while(!pila.empty()){ // Si aparece una vocal vacio la pila (para dar la vuelta a las consonantes).
				cout << pila.top();
				pila.pop();
			}
			cout << cola.front();
		}
		else pila.push(cola.front()); // Si aparece una consonante la inserto en la pila.
		cola.pop_front();
	}

	while(!pila.empty()){ // vacio la pila por si queda algo.
		cout << pila.top();
		pila.pop();
	}

	cout << endl;
	return true;
}

int main(){
	while(resuelveCaso());
	return 0;
}