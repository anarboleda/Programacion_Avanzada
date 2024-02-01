#include <iostream>

using namespace std;
void invertir(int* n, int tam);
int main()
{
    int tam=0;
    cout<<"ingresa el tamaño: ";
    cin>>tam;
    int n[tam];
    for(int i=0; i<tam; i++){
        cout<< "ingrese el numero "<< i+1 <<": ";
        cin >> n[i];
    }
    invertir(n,tam);
    return 0;
}

void invertir(int* n, int tam){
    int aux[tam]; //declarar un nuevo arreglo donde se almacena el invertido
    for(int i =0; i<tam; i++){ //invierte el arreglo y se almacena en aux
        aux[i] = n[tam-i-1];
    }

    cout<<"arreglo original: "<<endl;
    for(int i=0; i<tam; i++){
        cout << n[i] <<" ";
    }

    cout<<endl<<"arreglo invertido: "<<endl;
    for(int i=0; i<tam; i++){
        cout << aux[i]<<" ";
    }
}