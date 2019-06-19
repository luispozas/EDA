//LUIS POZAS PALOMO - 30
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

void actualizarDiccionario(map<string, int>& viejo, map<string, int>& nuevo,
        set<string> &add,  set<string> &less,  set<string> &change){

    auto it_v = viejo.begin();
    while(it_v != viejo.end()){
        if(nuevo.count(it_v->first)){
            if(it_v->second != nuevo[it_v->first]) change.insert(it_v->first);
        }
        else{
            less.insert(it_v->first);
        }
        ++it_v;
    }

    auto it_n = nuevo.begin();
    while(it_n != nuevo.end()){
        if(viejo.count(it_n->first)){
            if(it_n->second != viejo[it_n->first]) change.insert(it_n->first);
        }
        else{
            add.insert(it_n->first);
        }
        ++it_n;
    }
}

void resuelveCaso() {
    string linea, clave;
    int valor;
    map<string, int> viejo, nuevo;
    set<string> add, less, change;
    
    for(int i = 0; i < 2; i++){//Lectura del caso
        getline(cin, linea);
        stringstream str(linea);
        while(str >> clave >> valor){ //Recorro la linea por (clave, valor)
            i == 0? viejo[clave] = valor : nuevo[clave] = valor;
        }
    }
    actualizarDiccionario(viejo, nuevo, add, less, change);

    if(add.empty() && less.empty() && change.empty()) cout <<"Sin cambios\n";
    else{
        if(!add.empty()){
            auto it = add.begin();
            cout << "+";
            while(it != add.end()){
                cout << " " << *it;
                ++it;
            }
            cout <<"\n";
        }

        if(!less.empty()) {
            auto it1 = less.begin();
            cout << "-";
            while(it1 != less.end()){
                cout << " " << *it1;
                ++it1;
            }
            cout <<"\n";
        }
        
        if(!change.empty()){
            auto it2 = change.begin();
            cout << "*";
            while(it2 != change.end()){
                cout << " " << *it2;
                ++it2;
            }
            cout <<"\n";
        }
    }
    cout <<"----\n";
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