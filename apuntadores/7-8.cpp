#include <iostream>

const int n = 10; // Tamaño del vector

void dividir_vector(float v[], int n) {
    float* inicio = v; // Puntero al inicio del vector
    float* fin = v + n - 1; // Puntero al final del vector

    while (inicio < fin) {
        // Avanzar el puntero de inicio mientras el elemento apuntado sea menor o igual a v[0]
        while (inicio < fin && *inicio <= v[0]) {
            inicio++;
        }

        // Retroceder el puntero de fin mientras el elemento apuntado sea mayor que v[0]
        while (inicio < fin && *fin > v[0]) {
            fin--;
        }

        // Si los punteros no se han cruzado, intercambiar los elementos apuntados
        if (inicio < fin) {
            float temp = *inicio;
            *inicio = *fin;
            *fin = temp;
        }
    }
}

int main() {
    float v[n] = {3.5, 1.2, 4.7, 2.1, 6.9, 0.8, 3.3, 5.5, 2.8, 4.0};

    std::cout << "Vector original:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    dividir_vector(v, n);

    std::cout << "Vector dividido:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

