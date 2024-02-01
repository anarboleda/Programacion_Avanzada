#include <iostream>
#include <sstream>
#include <string>
#include <array>

using namespace std;

// Función para convertir formato de fecha
string conversion(const string& fecha) {
    // Definir arrays para los nombres de los meses y días
    array<string, 12> meses = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
    
    // Utilizar un stringstream para facilitar la manipulación
    stringstream ss(fecha);
    string dia_str, mes_str, anio_str;

    // Leer el día, mes y año desde la cadena de texto
    getline(ss, dia_str, '/');
    getline(ss, mes_str, '/');
    getline(ss, anio_str);

    // Convertir a enteros
    int dia = stoi(dia_str);
    int mes = stoi(mes_str);
    int anio = stoi(anio_str);

    // Validar los valores
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || anio < 0) {
        return "Fecha no válida";
    }

    // Formatear la fecha en el nuevo formato
    return to_string(dia) + " de " + meses[mes - 1] + " de " + to_string(anio);
}

int main() {
    // funcion main para ejecutar el programa
    string fecha;
    
    cout << "Ingrese una fecha en formato dd/mm/aa: ";
    getline(cin, fecha);

    string resultado = conversion(fecha);

    cout << "Fecha convertida: " << resultado << endl;

    return 0;
}

