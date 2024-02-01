#include <iostream>
using namespace std;

// Funci�n para verificar si un n�mero es primo
bool Primo(int numero){
    if(numero<1){
    return false;	
	} 
    for(int i = 2; i * i <= numero; i++) {
        if (numero % i == 0){
        	return false;
		} 
    }
    return true;
}

int main() {
    int contador=0;
    // N�mero que se evaluar� si es primo
    int numero=1;

    cout<<"Los primeros 80 numeros primos son:"<<endl;

    // Encontrar los primeros 80 n�meros primos
    while(contador<80){
        // Verificar si el n�mero actual es primo
        if (Primo(numero)&&numero!=2){
            cout<<numero<<"\t";
            contador++;
            // Insertar un salto de l�nea cada 10 n�meros primos
            if(contador%10==0){
                cout<<endl;
            }
        }
        // Pasar al siguiente n�mero
        numero++;
    }

    return 0;
}
