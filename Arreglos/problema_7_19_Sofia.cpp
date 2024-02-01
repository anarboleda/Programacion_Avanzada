#include <iostream>
#include <string>

using namespace std;

// Función para eliminar secuencias de dos espacios o más
string eliminarEspaciosRepetidos(const string& frase) {
    string resultado;
    char espacioAnterior = '\0';

    for (char caracter : frase) {
        if (!(espacioAnterior == ' ' && caracter == ' ')) {
            resultado += caracter;
        }
        espacioAnterior = caracter;
    }

    return resultado;
}

int main() {
    // Solicitar y leer la frase
    cout << "Ingrese una frase: ";
    string frase;
    getline(cin, frase);

    // Eliminar secuencias de dos espacios o más
    string fraseModificada = eliminarEspaciosRepetidos(frase);

    // Mostrar la frase original y la modificada
    cout << "Frase original: " << frase << endl;
    cout << "Frase modificada: " << fraseModificada << endl;

    return 0;
}

