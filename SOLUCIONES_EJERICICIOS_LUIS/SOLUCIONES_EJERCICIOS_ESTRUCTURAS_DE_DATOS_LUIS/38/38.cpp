//LUIS POZAS PALOMO - 38

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "ipud.h"


bool resuelveCaso() {
    string orden, S, A;
    int D, N;
    cin >> orden;
    if (!std::cin)
        return false;
    
    ipud ip;
    
    while (orden != "FIN") {
        try {
            if (orden == "addSong") {
                cin >> S >> A >> D;
                ip.addSong(S,A,D);
            } else if (orden == "addToPlaylist") {
                cin >> S;
                ip.addToPlaylist(S);
            } else if (orden == "current") {
                ip.current();
            } else if (orden == "play") {
                cout << "Sonando " << ip.play() << "\n";
            } else if (orden == "totalTime") {
                cout << "Tiempo total " << ip.totalTime() <<"\n";
            } else if (orden == "recent") {
                cin >> N;
                auto const& lista = ip.recent(N);
                if(lista.empty()) cout << "No hay canciones recientes\n";
                else{
                    cout <<"Las " << lista.size() << " mas recientes\n";
                    auto it = lista.begin();
                    while(it != lista.end()){
                        cout << "    " << *it <<"\n";
                        ++it;
                    }
                }
            }
            else if(orden == "deleteSong"){
                cin >> S;
                ip.deleteSong(S);
            }
        } catch (std::domain_error e) {
            cout << e.what() << "\n";
        }
        cin >> orden;
    }
    cout << "----\n";
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
