
package batallanavalproyecto;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class Principal {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean salir = false;
        String nombreJugador1 = null;
        String nombreJugador2 = null;

        while (!salir) {
            System.out.println("\t \t \t______________________________");
            System.out.println("\t \t \t|************* BATALLA NAVAL ************|");
            System.out.println("\t \t \t|-----------------------------------------|");
            System.out.println("\t \t \t|                  MENU                   |");
            System.out.println("\t \t \t|-----------------------------------------|");
            System.out.println("\t \t \t| Opcion 1: Ingreso de nuevos Jugadores   |");
            System.out.println("\t \t \t| Opcion 2: Iniciar Nueva Partida         |");
            System.out.println("\t \t \t| Opcion 3: Ver Ganadores Anteriores      |");
            System.out.println("\t \t \t| Opcion 4: Salir                         |");
            System.out.println("\t \t \t|-----------------------------------------|");
            System.out.print("Seleccione una opción: ");
            int opcion = scanner.nextInt();
            scanner.nextLine(); // consumir la nueva línea

            switch (opcion) {
                case 1:
                    System.out.print("Ingrese el nombre del Jugador 1: ");
                    nombreJugador1 = scanner.nextLine();
                    System.out.print("Ingrese el nombre del Jugador 2: ");
                    nombreJugador2 = scanner.nextLine();
                    
                    System.out.println("Jugadores registrados correctamente.");
                    break;

                case 2:
                    if (nombreJugador1 == null || nombreJugador2 == null) {
                        System.out.println("Debe ingresar los nombres de los jugadores antes de iniciar una partida.");
                    } else {
                        Jugador jugador1 = new JugadorHumano(nombreJugador1);
                        Jugador jugador2 = new JugadorHumano(nombreJugador2);

                        Partida partida = new Partida(jugador1, jugador2);
                        partida.jugar();
                    }
                    break;

                case 3:
                    mostrarGanadores();
                    break;

                case 4:
                    System.out.println("Gracias por jugar. ¡Hasta la próxima!");
                    salir = true;
                    break;

                default:
                    System.out.println("Opción incorrecta. Por favor, seleccione una opción válida.");
                    break;
            }
        }
        scanner.close();
    }

    private static void mostrarGanadores() {
        try (BufferedReader lector = new BufferedReader(new FileReader("registro_ganadores.txt"))) {
            String linea;
            System.out.println("Ganadores anteriores:");
            while ((linea = lector.readLine()) != null) {
                System.out.println(linea);
            }
        } catch (IOException e) {
            System.out.println("Ocurrió un error al leer el archivo de ganadores: " + e.getMessage());
        }
    }
}


