#include <iostream>
#include <math.h>
using namespace std;

// Funci�n para calcular la media
double media(double *datos, int n) {
  double suma = 0;
  for (int i = 0; i < n; i++) {
    suma += datos[i];
  }
  return suma / n;
}

// Funci�n para calcular la varianza
double varianza(double *datos, int n, double media) {
  double suma = 0;
  for (int i = 0; i < n; i++) {
    suma += (datos[i] - media) * (datos[i] - media);
  }
  return suma / n;
}

// Funci�n para calcular la desviaci�n est�ndar
double desviacion_estandar(double *datos, int n, double varianza) {
  return sqrt(varianza);
}

int main() {
  // Solicitamos al usuario los datos
  int n;
  cout << "�Cu�ntos datos desea ingresar? ";
  cin >> n;
  double *datos = new double[n];
  cout << "Ingrese los datos separados por espacio: ";
  for (int i = 0; i < n; i++) {
    cin >> datos[i];
  }

  // Calculamos la media
  double mediav = media(datos, n);

  // Calculamos la varianza
  double varianzav = varianza(datos, n, mediav);

  // Calculamos la desviaci�n est�ndar
  double desviacion_estandarv = desviacion_estandar(datos, n, varianzav);

  // Imprimimos los resultados
  cout << "Media: " << mediav << endl;
  cout << "Varianza: " << varianzav << endl;
  cout << "Desviaci�n est�ndar: " << desviacion_estandarv << endl;

  // Liberamos la memoria
  delete[] datos;

  return 0;
}
