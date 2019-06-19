//LUIS POZAS PALOMO - 39

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <stdexcept>
using namespace std;

#include "ventaLibros.h"

bool resuelveCaso() {
    std::string orden, x;
    int num, n;    
    ventaLibros c;

    cin >> num;
    if (!cin) return false;
    for (int i = 0; i < num; ++i) {
        cin >> orden;
        cin.ignore();
        try {
            if (orden == "nuevoLibro") {
                cin >> n;
                cin.ignore();
                getline(cin, x);
                c.nuevoLibro(n, x);
            } else if (orden == "comprar") {
                getline(cin, x);
                c.comprar(x);
            } else if (orden == "estaLibro") {
                getline(cin, x);
                if(c.estaLibro(x)) cout << "El libro " << x <<" esta en el sistema\n";
                else cout << "No existe el libro " << x <<" en el sistema\n";
                cout << "---\n";
            } else if (orden == "elimLibro") {
                getline(cin, x);
                c.elimLibro(x);
            } else if (orden == "numEjemplares") {
                getline(cin, x);
                try{
                    int m = c.numEjemplares(x);
                    cout << "Existen " << m <<" ejemplares del libro " << x << "\n";
                }catch(std::invalid_argument e){
                    cout << "No existe el libro " << x << " en el sistema\n";
                }
                cout << "---\n";
            } else if (orden == "top10") {
                auto const& list = c.top10();
                for(std::string s : list){
                    cout << s <<"\n";
                }
                cout << "---\n";
            } else cout << orden << "OPERACION DESCONOCIDA\n";
        } catch (invalid_argument e) {
            std::cout << e.what() << '\n';
            cout << "---\n";
        } catch (out_of_range e){
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