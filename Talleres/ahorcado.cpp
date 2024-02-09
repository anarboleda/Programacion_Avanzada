#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
using namespace std;

void escribirPalabrasEnArchivo(const string palabras[], int tam) {
    ofstream archivo("palabras.txt");
    if (archivo.is_open()) {
        for (int i = 0; i < tam; i++) {
            archivo << palabras[i] << endl;
        }
        archivo.close();
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

string seleccionarPalabraDesdeArchivo(const string& nombre_archivo) {
    ifstream archivo(nombre_archivo);
    if (archivo.is_open()) {
        string palabra;
        int total_palabras = 0;
        while (getline(archivo, palabra)) {
            total_palabras++;
        }
        archivo.clear(); // Limpiar el indicador de fin de archivo para volver a leer desde el principio
        archivo.seekg(0, ios::beg); // Mover el puntero de lectura al inicio del archivo

        srand(time(NULL)); // Sembrar el generador de números aleatorios
        int indice = rand() % total_palabras;
        for (int i = 0; i < indice; i++) {
            getline(archivo, palabra);
        }
        archivo.close();
        return palabra;
    } else {
        cout << "Error al abrir el archivo." << endl;
        return "";
    }
}

void mostrarTablero(int intentos, const string& letrasCorrectas, const string& palabra, const string fallos[]) {
    cout << fallos[intentos] << endl;

    string resultado;
    for (char letra : palabra) {
        if (letrasCorrectas.find(letra) != string::npos) {
            resultado += letra;
        } else {
            resultado += "_";
        }
        resultado += " ";
    }
    cout << "    " << resultado << endl;
}

char solicitarLetra(const string& letrasTodas) {
    while (true) {
        string input;
        cout << "Dime una letra: ";
        cin >> input;
        char letra = toupper(input[0]);
        if (input.size() != 1) {
            cout << "Por favor, introduce una sola letra." << endl;
        } else if (letrasTodas.find(letra) != string::npos) {
            cout << "Esa letra ya la has dicho." << endl;
        } else if (!isalpha(letra)) {
            cout << "Introduce una letra válida." << endl;
        } else {
            return letra;
        }
    }
}

void juegoDelAhorcado(const string palabras[], int tamPalabras, const string fallos[], int tamFallos) {
    string nombre_archivo = "palabras.txt";
    escribirPalabrasEnArchivo(palabras, tamPalabras);
    string palabra = seleccionarPalabraDesdeArchivo(nombre_archivo);
    string letrasCorrectas = "";
    string letrasTodas = "";
    int intentos = 0;

    while (intentos < tamFallos - 1) {
        mostrarTablero(intentos, letrasCorrectas, palabra, fallos);
        char letra = solicitarLetra(letrasTodas);
        letrasTodas += letra;

        if (palabra.find(letra) != string::npos) {
            letrasCorrectas += letra;
            if (palabra.find_first_not_of(letrasCorrectas) == string::npos) {
                mostrarTablero(intentos, letrasCorrectas, palabra, fallos);
                cout << "¡Has ganado! La palabra era: " << palabra << endl;
                return;
            }
        } else {
            intentos++;
        }
    }

    mostrarTablero(intentos, letrasCorrectas, palabra, fallos);
    cout << "Has perdido. La palabra era: " << palabra << endl;
}

int main() {
    const string palabras[] = {"SEQUENTIALACCESS", "BUFFER", "FILE"};
    const string fallos[] = {
        "   !===N\n"
        "       N\n"
        "       N\n"
        "       N\n"
        " =======\n",
        "   !===N\n"
        "       N\n"
        "       N\n"
        "       N\n"
        " =======\n"
        "   0   N\n"
        "       N\n"
        "       N\n",
        "   !===N\n"
        "  _0   N\n"
        "       N\n"
        "       N\n"
        " =======\n",
        "   !===N\n"
        "  _0_  N\n"
        "       N\n"
        "       N\n"
        " =======\n",
        "   !===N\n"
        "  _0_  N\n"
        "   |   N\n"
        "       N\n"
        " =======\n",
        "   !===N\n"
        "  _0_  N\n"
        "   |   N\n"
        "  /    N\n"
        " =======\n",
        "   !===N\n"
        "  _0_  N\n"
        "   |   N\n"
        "  / \\  N\n"
        " =======\n"
    };

    int tamPalabras = sizeof(palabras) / sizeof(palabras[0]);
    int tamFallos = sizeof(fallos) / sizeof(fallos[0]);

    juegoDelAhorcado(palabras, tamPalabras, fallos, tamFallos);

    return 0;
}
