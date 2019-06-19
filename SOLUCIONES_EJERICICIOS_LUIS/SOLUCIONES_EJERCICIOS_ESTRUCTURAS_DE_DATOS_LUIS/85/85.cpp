//LUIS POZAS PALOMO - 85
#include <iostream>
#include <fstream>
using namespace std;

#include "deque_eda.h"
#include "stack_eda.h"

void ordenar(deque<int>& c){
	stack<int> p;
	for(int i = 0; i < c.size(); i++){
		if(c.front() < 0){
			int d = c.front();
			c.pop_front();
			c.push_back(d);
		}
		else{
			p.push(c.front());
			c.pop_front();
			i--;
		}
	}

	while(!p.empty()){
		c.push_back(p.top());
		p.pop();
	}
}

bool resuelveCaso() {
	int n, data;
	deque<int> c;

	cin >> n;
	if(n == 0) return false;

	for(int i = 0; i < n; ++i){
		cin >> data;
		c.push_front(data); //colocamos la cola al reves
	}

	ordenar(c);

	for(int i = 0; i < c.size(); i++){
		cout << c.front() << " ";
		c.push_back(c.front());
		c.pop_front();
	}
	cout << endl;

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}