#include <iostream>

// Función para añadir una cadena de caracteres al final de otra
void encadenar_cadena(char* destino, const char* fuente) {
    // Mover el puntero al final de la cadena destino
    while (*destino != '\0') {
        destino++;
    }

    // Copiar la cadena fuente al final de la cadena destino
    while (*fuente != '\0') {
        *destino = *fuente;
        destino++;
        fuente++;
    }

    // Añadir el caracter nulo al final de la cadena destino
    *destino = '\0';
}

// Función para comparar dos cadenas de caracteres
int comparar_cadena(const char* cadena1, const char* cadena2) {
    // Recorrer ambas cadenas simultáneamente hasta que se encuentre un caracter diferente o ambas terminen
    while (*cadena1 != '\0' && *cadena2 != '\0') {
        if (*cadena1 < *cadena2) {
            return -1;
        } else if (*cadena1 > *cadena2) {
            return 1;
        }
        cadena1++;
        cadena2++;
    }

    // Verificar si una cadena es más larga que la otra
    if (*cadena1 == '\0' && *cadena2 == '\0') {
        return 0; // Las cadenas son iguales
    } else if (*cadena1 == '\0') {
        return -1; // La primera cadena es más corta
    } else {
        return 1; // La segunda cadena es más corta
    }
}

int main() {
    char cadena1[100] = "Hola";
    char cadena2[] = " Mundo";

    // Encadenar la segunda cadena a la primera
    encadenar_cadena(cadena1, cadena2);

    std::cout << "Cadena encadenada: " << cadena1 << std::endl;

    // Comparar las cadenas
    int resultado = comparar_cadena(cadena1, "Hola Mundo");
    if (resultado == 0) {
        std::cout << "Las cadenas son iguales." << std::endl;
    } else if (resultado == -1) {
        std::cout << "La primera cadena es más pequeña." << std::endl;
    } else {
        std::cout << "La primera cadena es más grande." << std::endl;
    }

    return 0;
}

