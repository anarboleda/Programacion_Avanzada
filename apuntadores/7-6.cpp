#include <iostream>

int* encontrar_maximo(int vector[], int longitud) {
    // Inicializar el puntero al elemento máximo
    int *max = vector;

    // Recorrer el vector para encontrar el elemento máximo
    for (int i = 1; i < longitud; ++i) {
        if (vector[i] > *max) {
            max = &vector[i];
        }
    }

    // Devolver el puntero al elemento máximo
    return max;
}

void encontrar_maximo_void(int vector[], int longitud, int*& max) {
    // Inicializar el puntero al elemento máximo
    max = vector;

    // Recorrer el vector para encontrar el elemento máximo
    for (int i = 1; i < longitud; ++i) {
        if (vector[i] > *max) {
            max = &vector[i];
        }
    }
}

int main() {
    int vector[] = {5, 10, 3, 8, 15, 12};
    int longitud = sizeof(vector) / sizeof(vector[0]);

    // Usando la función que devuelve el puntero al elemento máximo a través de return
    int* max1 = encontrar_maximo(vector, longitud);
    std::cout << "El valor máximo usando return es: " << *max1 << std::endl;

    // Usando la función que devuelve el puntero al elemento máximo a través de un parámetro void
    int* max2;
    encontrar_maximo_void(vector, longitud, max2);
    std::cout << "El valor máximo usando un parámetro void es: " << *max2 << std::endl;

    return 0;
}

