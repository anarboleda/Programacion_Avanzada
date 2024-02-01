#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void imprimirHistograma(int contador[5]) {
    char vocales[] = {'a', 'e', 'i', 'o', 'u'};
    cout << "Histograma de vocales:" << endl;

    for (int i = 0; i < 5; ++i) {
        cout << vocales[i] << " (" << contador[i] << "): ";
        for (int j = 0; j < contador[i]; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    string texto;

    cout << "Ingrese una frase: ";
    getline(cin, texto);

    int contador[5] = {0};  // Un arreglo para contar cada vocal

    // Contar la cantidad de cada vocal
    for (int i = 0; i < texto.length(); ++i) {
        switch (tolower(texto[i])) {
            case 'a':
                contador[0]++;
                break;
            case 'e':
                contador[1]++;
                break;
            case 'i':
                contador[2]++;
                break;
            case 'o':
                contador[3]++;
                break;
            case 'u':
                contador[4]++;
                break;
        }
    }

    // Imprimir el histograma
    imprimirHistograma(contador);

    return 0;
}

