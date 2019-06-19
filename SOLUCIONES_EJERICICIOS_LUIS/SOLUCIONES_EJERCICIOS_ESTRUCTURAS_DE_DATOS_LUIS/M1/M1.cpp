#include <iostream>
#include <list>
#include <string>
#include <utility>
using namespace std;


bool resuelveCaso(){
	int N, numAcc;
	string fecha;
	list<pair<string, int>> acc;

	cin >> N;
	if(!cin) return false;

	for(int i = 0; i < N; i++){
		cin >> fecha >> numAcc;
		
		if(acc.empty()) cout << "NO HAY" << endl;
		else{
			while(!acc.empty() && acc.back().second <= numAcc) acc.pop_back();
			if(acc.empty()) cout << "NO HAY" << endl;
			else cout << acc.back().first << endl;
		}
		acc.push_back(make_pair(fecha, numAcc));
	}
	cout << "---" << endl;

	return true;
}

int main(){
	while(resuelveCaso());
	return 0;
}