//LUIS POZAS PALOMO - 36
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

#include "consultorio.h"


bool resuelveCaso() {
    std::string orden, medico, paciente;
    int num, d, h ,m;
    
    consultorio c;

    cin >> num;
    if (!cin) return false;
    for (int i = 0; i < num; ++i) {
        cin >> orden;
        try {
            if (orden == "nuevoMedico") {
                cin >> medico;
                c.nuevoMedico(medico);
            } else if (orden == "pideConsulta") {
                cin >> paciente >> medico >> d >> h >> m;
                fecha f(d, h, m);
                c.pideConsulta(paciente, medico, f);
            } else if (orden == "siguientePaciente") {
                cin >> medico;
                cout << "Siguiente paciente doctor " << medico << "\n" << 
                        c.siguientePaciente(medico) <<"\n";
                cout << "---\n";
            } else if (orden == "atiendeConsulta") {
                cin >> medico;
                c.atiendeConsulta(medico);
            } else if (orden == "listaPacientes") {
                cin >> medico >> d;
                auto const& lista = c.listaPacientes(medico, d);
                auto it = lista.begin();
                cout << "Doctor " << medico << " dia " << d << '\n';
                while(it != lista.end()){
                    cout << *it << " ";
                    ++it;
                    cout << setfill('0') << setw(2) << *it << ":";
                    ++it;
                    cout << setfill('0') << setw(2) << *it << "\n";
                    ++it;
                }
                cout << "---\n";
            } else cout << "OPERACION DESCONOCIDA\n";
        } catch (std::domain_error e) {
            std::cout << e.what() << '\n';
            cout << "---\n";
        }
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
