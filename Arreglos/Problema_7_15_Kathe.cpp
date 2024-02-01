#include <iostream>

using namespace std; 
//declarar funciones
void invertir(int* n, int tam);
double calcularmedia(int* n, int tam);

int main(){
  int tam = 0;
  cout << "ingresar el tamaño del arreglo: ";
  cin >> tam;

  int n[tam]; //declara arreglo para guardar los numeros, solicitarlos, y guardarlos en el arreglo
  for(int i = 0; i<tam; i++){
    cout << "ingrese el numero: " << i+1<< ":";
    cin>>n[i];
  }
  invertir(n, tam); //llama a la funcion invertir

  double media= calcularmedia(n, tam);
  cout<< "la media es: " <<media <<endl;

  return 0;
}

void invertir(int* n, int tam){
  int aux[tam]; //arreglo aux para guardar el invertido
  for(int i=0; i<tam;i++){
    aux[i]=n[tam-i-1]; //se llena el arreglo invertido
  }
  cout << "arreglo original: "<<endl;
  for(int i=0;i<tam;i++){
    cout<<n[i]<<" ";
  }
  cout<<endl;
}
double calcularmedia(int* n, int tam){
  int suma = 0;
  for (int i=0;i<tam;i++){
    suma+=n[i];
  }
  return suma/tam;
}