//LUIS POZAS PALOMO - 33
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <list>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <utility>
using namespace std;

void printSol(map<int, map<int, set<string>>> & sol){
    auto it1 = sol.rbegin();
    while(it1 != sol.rend()){
        auto it2 = it1->second.begin();
        while(it2 != it1->second.end()){
            auto it3 = it2->second.begin();
            while(it3 != it2->second.end()){
                cout << *it3 << " " << it1->first << " " << it2->first <<"\n";
                ++it3;
            }
            ++it2;
        }
        ++it1;
    }
    cout << "----\n";
}

void resuelveCaso() {
    string e, p, s;
    int t;
    unordered_map<string, pair<int , unordered_map<string, pair<bool,int>>>> equipos_prob;//equipo ->(#aciertos, problemas -> (acertado, tiempo))
    map<int, map<int, set<string>>> resultado;//aciertos ->(tiempo_resolver -> conjuntos_de_equipos)

    cin >> e;
    while(e != "FIN"){
        cin >> p >> t >> s;
        if(!equipos_prob.count(e)) equipos_prob[e].first = 0; //Si el equipo es nuevo, aun no tiene aciertos
        if(equipos_prob[e].second.count(p)){ //Si el equipo ya ha intentado el problema
            if(!equipos_prob[e].second[p].first){ //Miro si el problema aun no ha sido correcto
                if(s!="AC") equipos_prob[e].second[p].second += 20; //Si sigue sin ser correcto se penaliza con 20
                else{
                    equipos_prob[e].second[p].first = true; //Si es correcto se actualiza
                    equipos_prob[e].second[p].second += t;
                    equipos_prob[e].first++; //Aumento el numero de aciertos del equipo.
                }
            }
        }
        else{//Si es la primera vez que el equipo intenta el problema
            if(s == "AC") {//Si lo acierta a la primera se actualiza el numero de aciertos
                equipos_prob[e].second[p] = make_pair(true, t);
                equipos_prob[e].first++;
            }
            else {//Si es el primero y lo falla se penaliza con 20
                equipos_prob[e].second[p] = make_pair(false, 20);
            }
        }
        cin >> e;
    }

    /*
    Añado los datos a un mapa nuevo solo la informacion de los problemas acertados para poder mostrar 
    la salida correctamente ordenada.
    Uso un mapa que contiene como clave (X) los aciertos y como valor otro mapa con los distintos tiempos
    que se han tardado en resolver los problemas que han tenido (X) aciertos y este ultimo en cada tiempo 
    tiene como valor un conjunto de problemas ya que puede existir varios problemas resueltos en el mismo instante.
    */

    auto it_equipo = equipos_prob.begin();
    while(it_equipo != equipos_prob.end()){
        int tiempo_total = 0;
        auto it_problema = it_equipo->second.second.begin();
        while(it_problema != it_equipo->second.second.end()){
            if(it_problema->second.first) tiempo_total += it_problema->second.second;
            ++it_problema;
        }
        resultado[it_equipo->second.first][tiempo_total].insert(it_equipo->first);
        ++it_equipo;
    }

    printSol(resultado);
}

int main() {
    
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin>>numCasos;
    cin.ignore();

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