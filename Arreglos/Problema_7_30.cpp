#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const int MAX_LONGITUD_CADENA = 100;
    char cadena[MAX_LONGITUD_CADENA];

    // Solicita al usuario ingresar una cadena
    cout << "Ingrese una cadena: ";
    cin.getline(cadena, MAX_LONGITUD_CADENA);

    int longitud = strlen(cadena);

    // Imprime la cadena en sentido inverso
    cout << "Cadena en sentido inverso: ";
    for (int i = longitud - 1; i >= 0; --i) {
        cout << cadena[i];
    }

    cout << endl;

    return 0;
}
