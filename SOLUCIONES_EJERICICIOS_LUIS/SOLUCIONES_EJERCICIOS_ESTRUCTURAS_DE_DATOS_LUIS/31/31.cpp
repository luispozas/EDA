//LUIS POZAS PALOMO - 31
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;

void printSol(map<string, list<int>> & sol){
    auto it = sol.begin();
    while(it != sol.end()){
        cout << it->first;
        auto list = it->second.begin();
        while(list != it->second.end()){
            cout << " " << *list;
            ++list;
        }
        cout <<'\n';
        ++it;
    }
    cout << "----\n";
}

string my_tolower(string & s){
    for(auto& c : s){
        c = tolower(c);
    }
    return s;
}

bool resuelveCaso() {
    int n;
    string linea, val;
    map<string, list<int>> words;

    cin >> n;
    if(n==0) return false;
    cin.ignore();

    for(int i = 1; i <= n; i++){
        getline(cin, linea); //Leo linea
        linea = my_tolower(linea); //Paso a minuscula
        stringstream str(linea);
        while(str >> val){ //Recorro la linea por palabras
            if(val.length() > 2){
                auto it = words.find(val);
                if(it == words.end() || it != words.end() && it->second.back() != i){
                    words[val].push_back(i);
                }
            }
        }
    }
    printSol(words);
    return true;
}

int main() {
    
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());
    
    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}