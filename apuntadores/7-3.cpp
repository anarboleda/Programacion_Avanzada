#include <iostream>

using namespace std;

int main() {
    const int tamano = 1000;
    int numeros[tamano]; // Declara un vector de 1000 enteros

    // Suponiendo que los enteros del vector han sido inicializados previamente...

    int *ptr = numeros; // Inicializa un puntero al inicio del vector
    int *fin = numeros + tamano; // Inicializa un puntero al final del vector

    // Recorre el vector y modifica los enteros negativos cambiando su signo
    while (ptr != fin) {
        if (*ptr < 0) {
            *ptr = -(*ptr); // Cambia el signo del entero negativo
        }
        ptr++; // Avanza al siguiente entero
    }

    // Imprime el vector modificado
    cout << "Vector modificado:" << endl;
    ptr = numeros; // Reinicializa el puntero al inicio del vector
    while (ptr != fin) {
        cout << *ptr << " ";
        ptr++; // Avanza al siguiente entero
    }
    cout << endl;

    return 0;
}

