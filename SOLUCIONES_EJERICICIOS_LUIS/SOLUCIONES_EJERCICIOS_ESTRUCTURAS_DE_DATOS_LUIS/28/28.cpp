//LUIS POZAS PALOMO - 28 - EDA
#include <iostream>
#include <map>
#include <utility>
using namespace std;


bool resuelveCaso(){
	map<string, int> m;
	int N;
	string clave, valor;
	cin >> N;
	if(N == 0) return false;
	for(int i = 0; i < N; i++){
		cin.ignore();
		getline(cin, clave);
		cin >> valor;

		if(valor == "CORRECTO") m[clave]++;
		else m[clave]--;
	}
	
	auto it = m.begin();
	while(it != m.end()){
		if(it->second != 0) cout << it->first << ", " << it->second << endl;
		++it;
	}

	cout << "---" << endl;
	return true;
}

int main(){
	while(resuelveCaso());
	return 0;
}