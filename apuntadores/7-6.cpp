#include <iostream>

int* encontrar_maximo(int vector[], int longitud) {
    // Inicializar el puntero al elemento m�ximo
    int *max = vector;

    // Recorrer el vector para encontrar el elemento m�ximo
    for (int i = 1; i < longitud; ++i) {
        if (vector[i] > *max) {
            max = &vector[i];
        }
    }

    // Devolver el puntero al elemento m�ximo
    return max;
}

void encontrar_maximo_void(int vector[], int longitud, int*& max) {
    // Inicializar el puntero al elemento m�ximo
    max = vector;

    // Recorrer el vector para encontrar el elemento m�ximo
    for (int i = 1; i < longitud; ++i) {
        if (vector[i] > *max) {
            max = &vector[i];
        }
    }
}

int main() {
    int vector[] = {5, 10, 3, 8, 15, 12};
    int longitud = sizeof(vector) / sizeof(vector[0]);

    // Usando la funci�n que devuelve el puntero al elemento m�ximo a trav�s de return
    int* max1 = encontrar_maximo(vector, longitud);
    std::cout << "El valor m�ximo usando return es: " << *max1 << std::endl;

    // Usando la funci�n que devuelve el puntero al elemento m�ximo a trav�s de un par�metro void
    int* max2;
    encontrar_maximo_void(vector, longitud, max2);
    std::cout << "El valor m�ximo usando un par�metro void es: " << *max2 << std::endl;

    return 0;
}

