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

        // Extracción de la cédula
        getline(ss, token, ';');
        datos.push_back(stoi(token));

        // Extracción de la presión sistólica
        getline(ss, token, '-');
        datos.push_back(stoi(token));

        // Extracción de la presión diastólica
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
        cout << "Número de cédula: " << datos[i] << ", ";
        cout << "Presión sistólica: " << datos[i + 1] << ", ";
        cout << "Presión diastólica: " << datos[i + 2] << endl;
    }

    return 0;
}

