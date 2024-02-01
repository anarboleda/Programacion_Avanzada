#include <iostream>

using namespace std;

int main() {
    const int diasSemana = 7;
    int horasTrabajadas[diasSemana];

    // Solicita al usuario ingresar las horas trabajadas para cada día de la semana
    for (int i = 0; i < diasSemana; ++i) {
        cout << "Ingrese las horas trabajadas para el día " << i + 1 << ": ";
        cin >> horasTrabajadas[i];
    }

    // Calcula la suma de las horas trabajadas
    int sumaHoras = 0;
    for (int i = 0; i < diasSemana; ++i) {
        sumaHoras += horasTrabajadas[i];
    }

    // Calcula la media
    double media = static_cast<double>(sumaHoras) / diasSemana;

    // Muestra la media de las horas trabajadas
    cout << "La media de las horas trabajadas durante la semana es: " << media << " horas" << endl;

    return 0;
}
