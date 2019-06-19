//LUIS POZAS PALOMO - EDA - 07
#include <iostream>
using namespace std;

#include "stack_eda.h"

bool juegoLinterna(int v[], const int N){
	stack<int> pila;
	int mM, mm = -1;
	for(int i = N-1; i > 0; i--){
		if(v[i-1] < mm) return true;
		else{
			if(v[i] > v[i-1]) pila.push(v[i]);
			else if(v[i] < v[i-1]){
				mM = v[i-1];
				mm = v[i];
				if(!pila.empty()){
					while(!pila.empty() && pila.top() < mM){
						mm = pila.top();
						pila.pop();
					}
				}
				pila.push(mM);
			}
		}
	}
	return false;
}

bool resuelveCaso(){
	stack<int> pila;
	int N;
	cin >> N;
	int v[N];
	if(!cin) return false;
	for(int i = 0; i < N; i++) cin >> v[i];
	if(juegoLinterna(v, N)) cout << "ELEGIR OTRA\n";
	else cout << "SIEMPRE PREMIO\n";
	return true;
}

int main(){
	while(resuelveCaso());
}