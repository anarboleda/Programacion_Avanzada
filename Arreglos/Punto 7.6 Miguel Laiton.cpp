#include<iostream>
using namespace std;

int main(){
int f=0;
int c=0;

cout<<" Digite las dimensiones de la matriz "<<endl;
cout<<" Fila: "; cin>>f;
cout<<endl;
cout<<" Columna: "; cin>>c;
cout<<endl;
int matriz[f][c];
//Digitar valores en la matriz
cout<<" Digite los valores de la matriz : "<<endl;
for(int i=0; i<f; i++){
	for(int j=0; j<c; j++){
		cout<<" Digite el valor de la fila ["<<i<<"] y la columna ["<<j<<"] ";
		cin>>matriz[i][j];
	}
}
cout<<endl;
//Imprimir la matriz
for(int i=0; i<f; i++){
	for(int j=0; j<c; j++){
		cout<<matriz[i][j]<<"\t";
	}
	cout<<endl;
}
int mayor=0;
int menor=1000;
//Encontrar el mayor y menor 
for(int i=0; i<f; i++){
	for(int j=0; j<c; j++){
		if(mayor<matriz[i][j]){
			mayor=matriz[i][j];
		}
		if(menor>matriz[i][j]){
			menor=matriz[i][j];
		}
	}
	
}
cout<<" El numero mayor de la matriz es : "<<mayor<<endl;
cout<<" El numero menor de la matriz es : "<<menor<<endl;
}
