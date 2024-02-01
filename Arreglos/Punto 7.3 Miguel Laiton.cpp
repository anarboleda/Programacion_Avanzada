#include<iostream>
using namespace std;

// Función para obtener el número de días en un mes dado
int obtenerDiasEnMes(string mes) {
    if (mes == "enero" || mes == "marzo" || mes == "mayo" || mes == "julio" || mes == "agosto" || mes == "octubre" || mes == "diciembre") {
        return 31;
    } else if (mes == "abril" || mes == "junio" || mes == "septiembre" || mes == "noviembre") {
        return 30;
    } else if (mes == "febrero") {
        return 28; 
    } else {
        return -1; // Mes inválido
    }
}

// Función para sumar días a una fecha
void sumar_dias(int dia, string mes, int ano, int dias) {
    while (dias > 0) {
        int dias_en_mes = obtenerDiasEnMes(mes);

        // Verificar si el día actual es el último del mes
        if (dia == dias_en_mes) {
            // Verificar si el mes actual es diciembre
            if (mes == "diciembre") {
                // Incrementar el año y establecer el mes a enero
                ano++;
                mes = "enero";
            } else {
                // Avanzar al siguiente mes
                if (mes=="enero") mes="febrero";
                else if (mes == "febrero") mes = "marzo";
                else if (mes == "marzo") mes = "abril";
                else if (mes == "abril") mes = "mayo";
                else if (mes == "mayo") mes = "junio";
                else if (mes == "junio") mes = "julio";
                else if (mes == "julio") mes = "agosto";
                else if (mes == "agosto") mes = "septiembre";
                else if (mes == "septiembre") mes = "octubre";
                else if (mes == "octubre") mes = "noviembre";
                else if (mes == "noviembre") mes = "diciembre";
            }
            // Establecer el día al primero del siguiente mes
            dia = 1;
        } else {
            // Avanzar al siguiente día
            dia++;
        }
        dias--; // Decrementar los días restantes
    }

    // Mostrar la nueva fecha
    cout<<" La nueva fecha es: "<<dia<<"/"<<mes<<"/"<<ano<<endl;
}

int main() {
    cout<<" Punto 7.3 Anadir dias a una fecha ingresada"<<endl;
    int dia=0, ano=0, dias=0;
    string mes;

    cout<< " Digite la fecha inicial : " << endl;
    cout<< "- Dia: "; cin >> dia;
    cout<< "- Mes: "; cin >> mes;
    cout<< "- Ano: "; cin >> ano;
    cout<< " ¿Cuantos dias desea sumar? "; cin >> dias;

    sumar_dias(dia, mes, ano, dias);

    return 0;
}

