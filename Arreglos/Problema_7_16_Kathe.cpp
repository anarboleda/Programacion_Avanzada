#include <iostream>

using namespace std;
int encontrarmayor(int* n, int tam);

int main(){
  int n[]=2,4,6,8,10,12};
  int tam=sizeof(n) / sizeof(n[0]); //calcula tamaño de arreglos
  int mayor=encontrarmayor(n, tam);
  cout << "el mayor de la lista es: "<<mayor<<endl;

  return 0;
}
int encontrarmayor(int* n, int tam){
  int mayor=n[0];
  for(int i=1;i<tam;i++){
    if(n[i]>mayor){
      mayor=n[i];
    }
  }
  return mayor;
}