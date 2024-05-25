#include <iostream>
#include <string>
using namespace std;

struct Contacto {
    string nombre;
    int numero_mensajes;
    string enviados[3];
};

void recibir(Contacto& contacto) {
    // Calcular el número de mensajes enviados
    int cont = 0;
    for (int i = 0; i < 3; i++) {
        if (!contacto.enviados[i].empty()) { //Comprobar si esta vacio
            cont++;
        }
    }
    contacto.numero_mensajes = cont;
}

int main() {
    Contacto Pedro;
    Contacto Juliana;

    Juliana.nombre = "Juliana";
    Pedro.nombre = "Pedro";
    Pedro.numero_mensajes = 0;
    Juliana.numero_mensajes = 0;

    Pedro.enviados[0] = "Hola Pedro como sigues?";
    Pedro.enviados[1] = "Pedro nos vemos para almorzar?";
    Juliana.enviados[0] = "Hola Juliana como estas?";
    Juliana.enviados[1] = "Juliana tienes listo el trabajo?";
    Juliana.enviados[2] = "Recuerda que es para hoy a las 9am";

    recibir(Juliana);
    recibir(Pedro);

    cout << "Juliana tiene " << Juliana.numero_mensajes << " mensajes" << endl;
    cout << "Pedro tiene " << Pedro.numero_mensajes << " mensajes" << endl;

    return 0;
}

