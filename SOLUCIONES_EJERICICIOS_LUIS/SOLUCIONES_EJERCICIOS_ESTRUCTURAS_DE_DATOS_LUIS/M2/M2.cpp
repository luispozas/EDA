#include <iostream>
using namespace std;

#include "bintree_eda.h"

int caminoPares(bintree<int> a, int& m){
	if(a.empty()){
		m = 0;
		return 0;
	}
	else{
		int iz, dr, maxi, maxd;
		iz = caminoPares(a.left(), maxi);
		dr = caminoPares(a.right(), maxd);
		if(a.root() % 2 == 0){
			m = max(iz + 1 + dr, max(maxi, maxd));
			return max(iz, dr) + 1;
		}
		else{
			m = max(maxi, maxd);
			return 0;
		}
	}
}

bool resuelveCaso(){
	auto a = leerArbol(-1);
	int max = 0;

	caminoPares(a, max);
	cout << max << endl;
	return true;
}

int main(){
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		resuelveCaso();
	}
	return 0;
}