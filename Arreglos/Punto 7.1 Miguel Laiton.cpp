#include<iostream>
using namespace std;

//Funcion para el punto 7.1 
int convertir(char romano[]) {
    int arabigo=0;
    int prev=0;
    
    for (int i=0; romano[i]!='\0'; i++) {
        int valor=0;
        switch (romano[i]) {
            case 'I':
                valor=1;
                break;
            case 'V':
                valor=5;
                break;
            case 'X':
                valor=10;
                break;
            case 'L':
                valor=50;
                break;
            case 'C':
                valor=100;
                break;
            case 'D':
                valor=500;
                break;
            case 'M':
                valor=1000;
                break;
            default:
                return -1; // Error: Car�cter no v�lido
        }
        
        if (valor>prev) {
            arabigo+=valor-2*prev;
        } else {
            arabigo+=valor;
        }
        prev=valor;
    }
    
    return arabigo;
}
int main(){

// Punto 7.1 Convertir un numero romano en numeros arabigos
    cout<<" Punto 7.1 Convertir un numero romano en numeros arabigos"<<endl;    
    char numero_romano[20]; 
    
    cout<<"Introduce un numero romano: ";    cin>>numero_romano;
    int numero_arabigo=convertir(numero_romano);
    
    if (numero_arabigo!=-1){	
        cout<<" Numero ar�bigo correspondiente a "<<numero_romano<<" es: "<<numero_arabigo<<endl;
    } 
    else{
        cout<<" Error: Car�cter no v�lido en el n�mero romano."<<endl;
    return 0;
    }    
    system("pause");
    system("cls");
}
