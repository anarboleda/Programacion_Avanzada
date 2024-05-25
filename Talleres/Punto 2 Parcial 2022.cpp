#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

struct Pacientes {
    int cedula;
    int presion_sistolica;
    int presion_diastolica;
};

void extraer(vector<int>& datos) {
    ifstream medidas;
    medidas.open("medidas.txt");
    if (medidas.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    string linea;
    while (getline(medidas, linea)) {
        stringstream ss(linea);
        string token;

        // Extracci�n de la c�dula
        getline(ss, token, ';');
        datos.push_back(stoi(token));

        // Extracci�n de la presi�n sist�lica
        getline(ss, token, '-');
        datos.push_back(stoi(token));

        // Extracci�n de la presi�n diast�lica
        getline(ss, token, ';');
        datos.push_back(stoi(token));
    }

    medidas.close();
}

int main() {
    vector<int> datos;
    extraer(datos);

    // Mostrar solo los valores de los pacientes
    for (size_t i = 0; i < datos.size(); i += 3) {
        cout << "N�mero de c�dula: " << datos[i] << ", ";
        cout << "Presi�n sist�lica: " << datos[i + 1] << ", ";
        cout << "Presi�n diast�lica: " << datos[i + 2] << endl;
    }

    return 0;
}

