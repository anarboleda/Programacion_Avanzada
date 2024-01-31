#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Función para sustituir valores duplicados por -5
pair<vector<int>, int> sustituirDuplicados(vector<int>& arreglo) {
    unordered_map<int, int> contador;
    int entradasModificadas = 0;

    // Recorrer el arreglo y contar la frecuencia de cada elemento
    for (int i = 0; i < arreglo.size(); ++i) {
        if (contador.find(arreglo[i]) != contador.end()) {
            // Elemento duplicado encontrado, sustituir por -5
            arreglo[i] = -5;
            entradasModificadas++;
        }
        contador[arreglo[i]]++;
    }

    return {arreglo, entradasModificadas};
}

int main() {
    // Ejemplo de uso
    vector<int> arreglo = {1, 2, 3, 2, 4, 5, 3, 6, 7, 8, 4};
    
    cout << "Arreglo original: ";
    for (int num : arreglo) {
        cout << num << " ";
    }
    cout << endl;

    auto resultado = sustituirDuplicados(arreglo);

    cout << "Arreglo modificado: ";
    for (int num : resultado.first) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Entradas modificadas: " << resultado.second << endl;

    return 0;
}

