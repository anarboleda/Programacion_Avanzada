#include <iostream>

using namespace std;

void mezclar_vectores(float* v1, int n, float* v2, int m, float* res) {
    float* ptr1 = v1; // Puntero para recorrer v1
    float* ptr2 = v2; // Puntero para recorrer v2
    float* ptr_res = res; // Puntero para recorrer res

    // Mezclar de manera ordenada los valores de v1 y v2 en res
    while (ptr1 - v1 < n && ptr2 - v2 < m) {
        if (*ptr1 < *ptr2) {
            *ptr_res = *ptr1;
            ptr1++;
        } else {
            *ptr_res = *ptr2;
            ptr2++;
        }
        ptr_res++;
    }

    // Agregar los elementos restantes de v1 a res
    while (ptr1 - v1 < n) {
        *ptr_res = *ptr1;
        ptr1++;
        ptr_res++;
    }

    // Agregar los elementos restantes de v2 a res
    while (ptr2 - v2 < m) {
        *ptr_res = *ptr2;
        ptr2++;
        ptr_res++;
    }
}

int main() {
    const int n = 5;
    const int m = 7;
    const int capacidad_res = n + m;

    float v1[n] = {1.2, 3.4, 5.6, 7.8, 9.0};
    float v2[m] = {2.1, 4.3, 6.5, 8.7, 10.9, 12.0, 14.2};
    float res[capacidad_res];

    // Llamada a la función para mezclar los vectores v1 y v2 en res
    mezclar_vectores(v1, n, v2, m, res);

    // Imprimir el vector mezclado
    cout << "Vector mezclado:" << endl;
    for (int i = 0; i < capacidad_res; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}

