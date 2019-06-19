//LUIS POZAS PALOMO - 29 - EDA
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;


int seriesDistintas(vector<int> V){
	int max = 1;
	int ini = 0;
	unordered_map<int, int> m;

	for(int i = 0; i < V.size(); i++){
		auto it = m.find(V[i]);
		if(it != m.end() && it->second >= ini){ //Esta y pertenece a la secuencia, actualizo ini
			ini = it->second+1;
		}
		else{
			if(max <= i - ini + 1) max = i - ini + 1;
		}
		m[V[i]] = i;
	}
	return max;
}

void resuelveCaso(){
	int N, val;
	vector<int> v;
	cin >> N;
	for(int j = 0; j < N; j++){
		cin >> val;
		v.push_back(val);
	}
	cout << seriesDistintas(v) << endl;
}

int main() {
    
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin >> numCasos;
    for(int i = 0; i < numCasos; i++){
        resuelveCaso();
    }
    
    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}