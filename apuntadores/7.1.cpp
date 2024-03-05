#include <iostream>

using namespace std;

int main() {
    char cadena[100]; // Declara una cadena de 100 caracteres
    // Suponiendo que la cadena ha sido inicializada previamente...

    char *ptr = cadena; // Inicializa un puntero al inicio de la cadena

    // Encuentra la posición del primer carácter espacio
    while (*ptr != '\0') {
        if (*ptr == ' ') {
            cout << "La posición del primer espacio es: " << (ptr - cadena) << endl;
            break;
        }
        ptr++; // Avanza al siguiente caracter
    }

    return 0;
}

