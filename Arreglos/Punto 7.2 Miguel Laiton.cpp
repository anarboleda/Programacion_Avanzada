#include<iostream>
using namespace std;
//Función punto 7.2 Invertir contenido de n numeros enteros
int invertir(int entero){
    int invertidos=0;   
    while(entero!=0){
        invertidos=invertidos*10+entero%10;
        entero/=10;
    }    
    return invertidos;
}

int main(){
	//Punto 7.2 Invertir contenido de n numeros enteros
    cout<<" Punto 7.2 Invertir contenido de n numeros enteros"<<endl;
    int entero=0;
    cout<<"Ingrese un numero entero: ";    cin>>entero;
	   
    int invertido = invertir(entero);
    cout<<" El numero incial era "<<entero<<" Invertido queda asi "<<invertido<<endl;
	
	system("pause");
    system("cls");
}
