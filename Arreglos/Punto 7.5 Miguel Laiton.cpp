#include<iostream>
using namespace std;

void adivinar(char palabras[], char letra, char respuestas[]){
    int intentos=0;
    bool adivinado=false;

    // Inicializar respuestas con guiones bajos para cada letra de la palabra
    for (int i=0; palabras[i]!='\0'; i++) {
        respuestas[i]='_';
    }

    while (!adivinado&&intentos<6) {
        cout<<"Ingrese una letra: ";
        cin>>letra;
        cout<<endl;

        bool letraEncontrada=false;

        // Verificar si la letra ingresada está en la palabra
        for (int i=0; palabras[i]!='\0'; i++) {
            if (letra==palabras[i]) {
                respuestas[i]=letra;
                letraEncontrada=true;
            }
        }

        // Mostrar el progreso
        cout << "Palabra: ";
        for (int i=0; palabras[i]!='\0'; i++) {
            cout<<respuestas[i]<<" ";
        }
        
        cout<<endl;

        if (!letraEncontrada) {
            intentos++;
            cout<<"Incorrecto. Intentos restantes: "<<6-intentos<<endl;
        }

        // Verificar si todas las letras han sido adivinadas
        adivinado=true;
        for (int i=0; palabras[i]!='\0';i++) {
            if (respuestas[i]=='_') {
                adivinado=false;
                break;
            }
        }
    }

    if(adivinado==true){
        cout<<"¡Felicidades! ¡Has adivinado la palabra!"<<endl;
    } else{
        cout<<"¡Lo siento! Has perdido. La palabra era: "<<palabras<<endl;
    }
}

int main() {
    // Definir la palabra a adivinar
    char palabras[20];
    cout<<" Juego Ahorcado "<<endl;
    cout<<"Ingrese la palabra para adivinar: ";
    cin>>palabras;
    cout<<endl;

    char respuestas[20];
    char letra;

    adivinar(palabras, letra, respuestas);

    return 0;
}

