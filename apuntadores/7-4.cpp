#include <iostream>
#include <string>

using namespace std;

int main() {
    string cad;
    cout << "Ingrese una cadena de caracteres: ";
    getline(cin, cad); // Leemos la cadena completa con espacios incluidos

    // Encontrar la posición del primer espacio en blanco
    size_t pos = cad.find(' ');
    
    // Si hay un espacio en blanco, imprime la cadena a partir del siguiente caracter
    if (pos != string::npos) {
        cout << "La cadena, saltando la primera palabra, es: " << cad.substr(pos + 1) << endl;
    } else {
        cout << "No se encontró una segunda palabra." << endl;
    }

    return 0;
}

