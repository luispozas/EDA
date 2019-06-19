//LUIS POZAS PALOMO - 32
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <utility>
using namespace std;

void printSol(map<int, set<string>> & sol){
    auto itN = sol.rbegin();
    while(itN != sol.rend()){
        auto itD = itN->second.begin();
        while(itD != itN->second.end()){
            cout << *itD <<" " << itN->first << "\n";
            ++itD;
        }
        ++itN;
    }
    cout << "***\n";
}

bool resuelveCaso() {
    string s, act_deporte;
    unordered_map<string, string> alumnos; //alumno -> deporte
    map<string, int> deportes; //deporte -> numAlumnos
    set<string> sancionados;
    map<int, set<string>> list_sort;

    cin >> s;
    if(!cin) return false;

    while(s!="_FIN_"){
        char c = s[0];
        if(s[0] == tolower(c)){ //s -> alumno
            if(alumnos.find(s) != alumnos.end()){
                if(alumnos[s] != act_deporte){//Si esta y se ha apuntado a dos deportes lo elimino
                    sancionados.insert(s);
                    deportes[alumnos[s]]--;
                    alumnos.erase(s);
                }
            }
            else{//Si no esta lo añado si no ha sido sancionado
                if(sancionados.find(s) == sancionados.end()) {
                    alumnos[s] = act_deporte;
                    deportes[act_deporte]++;
                }
            }
        }
        else{ //s -> deporte
            act_deporte = s;
            deportes[s] = 0;
        }
        cin >> s;
    }

    auto it = deportes.begin();
    while(it != deportes.end()){
        list_sort[it->second].insert(it->first);
        ++it;
    }

    printSol(list_sort);
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