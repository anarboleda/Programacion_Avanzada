#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string frase;

    // Pedir al usuario que ingrese una frase
    cout << "Ingrese una frase: ";
    getline(cin, frase);

    // Utilizar un stringstream para separar las palabras
    stringstream ss(frase);
    string palabra;

    // Imprimir cada palabra con un salto de línea
    while (ss >> palabra) {
        cout << palabra << endl;
    }

    return 0;
}

