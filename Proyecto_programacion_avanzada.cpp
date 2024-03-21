#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>

using namespace std;

const int FILAS = 10;
const int COLUMNAS = 10;

// Símbolos para representar el estado de las casillas en el tablero
const char AGUA = '~';
const char BARCO = 'H';
const char ATINADO = 'X';
const char FALLO='O';

struct Jugador {
    string nombre;
    char tablero[FILAS][COLUMNAS];
    int gano;
};
struct Ganador{
	string nombre_del_ganador;
};

void crear(){
  ofstream juegos;
  juegos.open("resultadosx.txt", ios::out);
  // Si el archivo tiene una falla
  if(juegos.fail()){
    // imprime
  cout<<"No se pudo abrir el archivo";
  exit(1); // termina el programa.
  }

  juegos.close();

}


void crear_binario(){
    ofstream binario;
    binario.open("ganadores.dat", ios::out | ios::binary);
    if(binario.fail()){
        cout<<"El archivo no pudo abrirse"<<endl;
        exit(1);
    }
    binario.close();
}



void imprimirTablero(Jugador jugador) {
    cout << "  ";
    for (int i = 0; i < COLUMNAS; i++) {
        cout<<"\t"<< i+1 << ' ';
    }
    cout << endl;
    for (int i = 0; i < FILAS; i++) {
        char letraFila = 'A' + i;
        cout<<letraFila<< ' ';
        for (int j = 0; j < COLUMNAS; j++) {
            cout<<"\t"<<jugador.tablero[i][j]<<' ';
        }
        cout << endl;
    }
}


void colocarBarcoEnDireccion(Jugador &jugador, int fila, int columna, int longitud, int direccion, int &aux2) {
    if(direccion>=1&&direccion<=4){

      if(direccion==1){
      // Verificar que la casilla esté disponible
         if (jugador.tablero[fila][columna] == BARCO||fila<=3) {
            cout << " Ya hay un barco en esa posicion o en esta direccion el barco queda por fuera ~> Intentalo de nuevo <~" << endl;
            aux2=0;

          }else{
              for(int i=fila; i>fila-longitud; i--){                    
                 jugador.tablero[i][columna] = BARCO;
                 aux2=1;

                 }            
                   }
    }else if(direccion==2){
        // Verificar que la casilla esté disponible
                if (jugador.tablero[fila][columna] == BARCO||fila>=5) {
                cout << " Ya hay un barco en esa posicion o en esta direccion el barco queda por fuera ~> Intentalo de nuevo <~" << endl;
                  aux2=0;

                }else{
                    for(int i=fila; i<fila+longitud; i++){                    
                        jugador.tablero[i][columna] = BARCO;
                        aux2=1;

                 }            
                   }
    }else if(direccion==3){
        // Verificar que la casilla esté disponible
                if (jugador.tablero[fila][columna] == BARCO||columna>=5) {
                cout << "Ya hay un barco en esa posicion o en esta direccion el barco queda por fuera ~> Intentalo de nuevo <~" << endl;
                  aux2=0;

                }else {
                    for(int i=columna; i<columna+longitud; i++){                    
                        jugador.tablero[fila][i] = BARCO;
                      aux2=1;

                 }          
                   }
    }else if(direccion==4){
        // Verificar que la casilla esté disponible
                if (jugador.tablero[fila][columna] == BARCO||columna<=3) {
                cout << "Ya hay un barco en esa posicion o en esta direccion el barco queda por fuera ~> Intentalo de nuevo <~" << endl;
                  aux2=0;

                }else{
                    for(int i=columna; i>columna-longitud; i--){                    
                        jugador.tablero[fila][i] = BARCO;
                        aux2=1;
                   }
                }            
                }



    }else if(direccion>4||direccion<1){
        cout<<" Opcion incorrecta, vuelva a digitar la direccion : "<<endl;
        aux2=0;
      }
}

Jugador colocarBarcos(Jugador jugador) {
  cout << jugador.nombre << ", coloca tus barcos en el tablero." << endl;
  int aux=0;
  int bien=0;
  int bien2=0;
    for(int i=0; i<5; i++){
      int fila=0, columna=0, direccion;
      char filas;
      cout<<endl;
      bien2=0;
      while(bien2==0){
       
     
      if(i==0){
      cout << " Ingresa la posicion Inicial de la fila del Portaaviones ( 5 posiciones ) (A-J) : ";
        aux=5;
      }else if(i==1){
      cout << " Ingresa la posicion Inicial de la fila del Fragata ( 4 posiciones ) (A-J) : ";
        aux=4;
      }else if(i==2){
      cout << " Ingresa la posicion Inicial de la fila del Crucero ( 3 posiciones ) (A-J) : ";
        aux=3;
      }else if(i==3){
        cout << " Ingresa la posicion Inicial de la fila del Submarino ( 3 posiciones ) (A-J) : ";
        aux=3;
      }else if(i==4){
        cout << " Ingresa la posicion Inicial de la fila del Destructor ( 2 posiciones ) (A-J) : ";
        aux=2;
      }
      cin>>filas;        
      cout<<endl;

         if(filas=='A'||filas=='a'){
               fila=1;
          }else if(filas=='B'||filas=='b'){
           fila=2;
          }else if(filas=='C'||filas=='c'){
           fila=3;
          }else if(filas=='D'||filas=='d'){
           fila=4;
          }else if(filas=='E'||filas=='e'){
           fila=5;
          }else if(filas=='F'||filas=='f'){
           fila=6;
          }else if(filas=='G'||filas=='g'){
           fila=7;
          }else if(filas=='H'||filas=='h'){
           fila=8;
          }else if(filas=='I'||filas=='i'){
           fila=9;
          }else if(filas=='J'||filas=='j'){
           fila=10;
          }

          if(i==0){
          cout << " Ingresa la posicion Inicial de la columna del Portaaviones ( 5 posiciones ) (1-10) : ";
          }else if(i==1){
          cout << " Ingresa la posicion Inicial de la columna del Fragata ( 4 posiciones ) (1-10) : ";
          }else if(i==2){
          cout << " Ingresa la posicion Inicial de la columna del Crucero ( 3 posiciones ) (1-10) : ";
          }else if(i==3){
            cout << " Ingresa la posicion Inicial de la columna del Submarino ( 3 posiciones ) (1-10) : ";
          }else if(i==4){
            cout << " Ingresa la posicion Inicial de la columna del Destructor ( 2 posiciones ) (1-10) : ";
          }
          cin>>columna;
          cout<<endl;

          if(fila<=10&&fila>=1&&columna<=10&&columna>=1&&jugador.tablero[fila-1][columna-1]!=BARCO&&fila<='J'){
            //Cuando ya hay un barco en la posicion bien debe ser igual a 0
            int aux2=0;
            bien=0;
            while(bien==0){
             
            cout << "Ingresa la direccion del barco (1=Arriba, 2=Abajo, 3=Derecha, 4=Izquierda): ";
            cin >> direccion;
            colocarBarcoEnDireccion(jugador, fila - 1, columna - 1, aux, direccion,aux2);
            bien=aux2;
            bien2=1;

            system("pause");
             system("cls");

            }
         }else{
              cout<<" Digitaste un valor fuera del tablero, vuelve a digitar la fila y columna "<<endl;
              bien2=0;
            system("pause");
            system("cls");

            }
      }
    }    
    return jugador;
}

void visualizar() {
    ifstream juegos;
    string texto;
    juegos.open("resultadosx.txt", ios::in); // Apertura del archivo en modo lectura
    if (juegos.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    // Leer línea por línea hasta que no haya más líneas
    while (getline(juegos, texto)) {
    	
        cout <<"\t -> " << texto << endl;
        cout<<endl;
    }
    juegos.close(); // Cerrar el archivo después de terminar la lectura
}
void disparar(Jugador &atacante, Jugador &defensor, Ganador &ganador) {

    cout << "\t\t" << atacante.nombre << ", es tu turno." << endl;
    int fila=0, columna=0;
  char filas;
    cout<<"-> Ingresa la posicion de la fila a la que quieres disparar: ";
    cin>>filas;        
    cout<<endl;
    if(filas=='A'||filas=='a'){
          fila=1;
     }else if(filas=='B'||filas=='b'){
      fila=2;
     }else if(filas=='C'||filas=='c'){
      fila=3;
     }else if(filas=='D'||filas=='d'){
      fila=4;
     }else if(filas=='E'||filas=='e'){
      fila=5;
     }else if(filas=='F'||filas=='f'){
      fila=6;
     }else if(filas=='G'||filas=='g'){
      fila=7;
     }else if(filas=='H'||filas=='h'){
      fila=8;
     }else if(filas=='I'||filas=='i'){
      fila=9;
     }else if(filas=='J'||filas=='j'){
      fila=10;
     }
          cout<<"-> Ingresa la posicion de la columna a la que quieres disparar: ";  
          cin>>columna;
          cout<<endl;

    if (defensor.tablero[fila - 1][columna - 1] == BARCO) {

      cout<<endl;            
    cout << "¡ HAS ACERTADO A UN BARCO !"<<endl;
        defensor.tablero[fila-1][columna-1]=ATINADO;
        system("pause");
        system("cls");

    } else {

            cout<<" ~ Has disparado al agua ~"<<endl;
            if(atacante.tablero[fila-1][columna-1]==AGUA){
            atacante.tablero[fila-1][columna-1]=FALLO;
            }
            system("pause");
            system("cls");                      
    }
    // Comprobar si el defensor ha perdido
    int barcos = 0;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (defensor.tablero[i][j] == BARCO) {
                barcos++;
            }
        }
    }

    if (barcos == 0) {
      cout<<"\t ~> FELICIDADES "<<atacante.nombre<<" !HAS GANADO¡ <~ "<<endl;
      atacante.gano=1;
      cout<<endl;
      cout<<"                                            mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm                  "<<endl;
      cout<<"                                        mmmm                                       mmmm                  "<<endl;
      cout<<"                                        mmmm                                       mmmm                  "<<endl;
      cout<<"                                        mmmm       000000             000000       mmmm                  "<<endl;
      cout<<"                                        mmmm       000000             000000       mmmm                  "<<endl;
      cout<<"                                        mmmm       000000             000000       mmmm                  "<<endl;
      cout<<"                                        mmmm                  II                   mmmm                  "<<endl;
      cout<<"                                        mmmm                  II                   mmmm                  "<<endl;
      cout<<"                                        mmmm                  II                   mmmm                  "<<endl;
      cout<<"                                        mmmm                 VVVV                  mmmm                  "<<endl;
      cout<<"                                        mmmm                                       mmmm                  "<<endl;
      cout<<"                                        mmmm            WWW        WWW             mmmm                  "<<endl;
      cout<<"                                        mmmm               WWWWWWWW                mmmm                  "<<endl;
      cout<<"                                        mmmm                                       mmmm                  "<<endl;
      cout<<"                                            mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm                  "<<endl;
    //agregar al archivo
        ofstream juegos;
        juegos.open("resultadosx.txt", ios::app);
        if(juegos.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
        }
        juegos<<atacante.nombre<<" Le gano a "<<defensor.nombre<<endl;
        juegos.close();
        // Guarda el ganador en un archivo binario
	    
	    ganador.nombre_del_ganador = atacante.nombre;
	
	    ofstream binario("ganadores.dat", std::ios::binary | std::ios::app);
	    if (!binario) {
	        cerr << "Error al abrir archivo" << std::endl;
	        exit(1);
	    }
	
	    binario.write((char*)&ganador, sizeof(Ganador));
	    binario.close();
			
	    }else if (barcos>0){
	      cout<<atacante.nombre<<" ~ Aun le quedan barcos ~"<<endl;
	    }

}


int main() {
    int opcion;
    string nombres;
    bool op = true;
    Jugador jugador1;
    Jugador jugador2;
    Ganador ganador;
    while (op == true) {

        cout << "\t \t \t____________________________________________________________________________________" << endl;
        cout << "\t \t \t|************************************BATALLA NAVAL*********************************|" << endl;
        cout << "\t \t \t|----------------------------------------------------------------------------------|" << endl;
        cout << "\t \t \t|-----------------------------------------MENU-------------------------------------|" << endl;
        cout << "\t \t \t|                                                                                  |" << endl;
        cout << "\t \t \t| Opcion 1: Ingreso de nuevos Jugadores                                            |" << endl;
        cout << "\t \t \t| Opcion 2: Dar Inicio a Nueva partida (Despues de dar ingreso a nuevos jugadores) |" << endl;
        cout << "\t \t \t| Opcion 3: Resultado de partidas anteriores                                       |" << endl;
        cout << "\t \t \t| Opcion 4: Ganador reciente                                                       |" << endl;
        cout << "\t \t \t| Opcion 5: Salir                                                                  |" << endl;
        cout << "\t \t \t|__________________________________________________________________________________|" << endl;
        cin >> opcion;
        cout << "/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// " << endl;
        cout << "________________________________________________________________________________________________________________________" << endl;
 
        system("cls");

        if (opcion == 1) {

            // Crear dos jugadores
            cout << "Jugador 1, ingresa tu nombre: ";
            cin >> jugador1.nombre;
            cout << "Jugador 2, ingresa tu nombre: ";
            cin >> jugador2.nombre;

            // Inicializar tableros de juego
            for (int i = 0; i < FILAS; i++) {
                for (int j = 0; j < COLUMNAS; j++) {
                    jugador1.tablero[i][j] = AGUA;
                }
            }
            for (int i = 0; i < FILAS; i++) {
                for (int j = 0; j < COLUMNAS; j++) {
                    jugador2.tablero[i][j] = AGUA;
                }
            }
            system("pause");
            system("cls");
        } else if (opcion == 2) {
            // Colocar barcos en los tableros
            jugador1 = colocarBarcos(jugador1);
            jugador2 = colocarBarcos(jugador2);
            jugador1.gano = 0;
            jugador2.gano = 0;
            
            while (jugador1.gano == 0 && jugador2.gano == 0) {
           
                cout << "Tablero de " << jugador1.nombre << ":" << endl;
                imprimirTablero(jugador1);
                disparar(jugador1, jugador2,ganador);
               
                if (jugador1.gano == 0) {
               
                    cout << "Tablero de " << jugador2.nombre << ":" << endl;
                    imprimirTablero(jugador2);
                    disparar(jugador2, jugador1,ganador);
                }
            }
            system("pause");
            system("cls");

        } else if (opcion == 3) {
          //Cargar archivo de texto
          
          visualizar();
          system("pause");
          system("cls");
        } else if(opcion==4) {
        	
        	Ganador ganador;

		    ifstream binario2("ganadores.dat", ios::binary);
		    if (!binario2) {
		        cerr << "Error al abrir archivo" << endl;
		        
		    }
			cout << "Ganador reciente:" <<endl;
		    while(!binario2.eof()){
			    binario2.read((char*)&ganador, sizeof(Ganador));
			    if(!binario2.eof()){
			      cout << ganador.nombre_del_ganador << endl;
			    }
			   
			  }
		
		    binario2.close();
		    
        	
		}else if (opcion == 5) {
			cout<<endl;
            cout << "\t\t------------------------GRACIAS POR JUGAR----------------------- "<<endl;
            cout<<endl;
            op = false;
        } else if (opcion == 0 || opcion > 5) {
            cout << " Opcion Incorrecta, Por Favor digite una de las opciones del MENU ";
        }
    }
    system("pause");
    system("cls");
return 0;
}
