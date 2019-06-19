
// ALBERTO VERDEJO

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "autoescuela.h"


bool resuelveCaso() {
    std::string orden, alum, prof;
    int punt;
    std::cin >> orden;
    if (!std::cin)
        return false;
    
    autoescuela AE;
    
    while (orden != "FIN") {
        try {
            if (orden == "alta") {
                cin >> alum >> prof;
                AE.alta(alum, prof);
            } else if (orden == "es_alumno") {
                cin >> alum >> prof;
                if (AE.es_alumno(alum, prof))
                    cout << alum << " es alumno de " << prof << '\n';
                else
                    cout << alum << " no es alumno de " << prof << '\n';
            } else if (orden == "puntuacion") {
                cin >> alum;
                int puntos = AE.puntuacion(alum);
                cout << "Puntuacion de " << alum << ": " << puntos << '\n';
            } else if (orden == "actualizar") {
                cin >> alum >> punt;
                AE.actualizar(alum, punt);
            } else if (orden == "examen") {
                cin >> prof >> punt;
                cout << "Alumnos de " << prof << " a examen:\n";
                for (auto const& a : AE.examen(prof, punt)) {
                    cout << a << '\n';
                }
            } else if (orden == "aprobar") {
                cin >> alum;
                AE.aprobar(alum);
            }
        } catch (std::domain_error e) {
            std::cout << "ERROR\n";
        }
        std::cin >> orden;
    }
    std::cout << "------\n";
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
