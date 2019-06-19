//LUIS POZAS PALOMO - EDA - 16
#include <iostream>
#include <string>
using namespace std;

#include "extendList.h"
#include "persona.h"

bool resuelveCaso(){
	int num, min, max;
	persona p;
	extendsList<persona> list;
	if(cin >> num >> min >> max && num == 0 && min == 0 && max == 0) return false;

	for(int i = 0; i < num; i++){
		cin >> p;
		list.push_back(p);
	}

	predicado<int> pred(min, max);

	list.remove_if(pred);

	list.print();

	cout << "---" << endl;

	return true;
}

int main(){
	while(resuelveCaso());
	return 0;
}