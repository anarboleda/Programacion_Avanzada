#include <iostream>
using namespace std;

// Función para verificar si un número es primo
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
    // Número que se evaluará si es primo
    int numero=1;

    cout<<"Los primeros 80 numeros primos son:"<<endl;

    // Encontrar los primeros 80 números primos
    while(contador<80){
        // Verificar si el número actual es primo
        if (Primo(numero)&&numero!=2){
            cout<<numero<<"\t";
            contador++;
            // Insertar un salto de línea cada 10 números primos
            if(contador%10==0){
                cout<<endl;
            }
        }
        // Pasar al siguiente número
        numero++;
    }

    return 0;
}
