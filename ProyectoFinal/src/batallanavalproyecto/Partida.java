/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package batallanavalproyecto;

/**
 *
 * @author anloa
 */
import java.io.*; // Importar todas las clases del paquete java.io
import java.util.Scanner;

public class Partida {
    private Jugador jugador1;
    private Jugador jugador2;

    public Partida(Jugador jugador1, Jugador jugador2) {
        this.jugador1 = jugador1;
        this.jugador2 = jugador2;
    }

    public void jugar() {
        System.out.println("Iniciando la partida...");

        jugador1.colocarBarcos();
        jugador2.colocarBarcos();

        while (!jugador1.haGanado() && !jugador2.haGanado()) {
            jugador1.imprimirTablero();
            jugador1.disparar(jugador2);
            if (jugador2.haGanado()) {
                System.out.println(jugador2.getNombre() + " ha ganado la partida!");
                break;
            }
            jugador2.imprimirTablero();
            jugador2.disparar(jugador1);
            
            if (jugador1.haGanado()) {
                System.out.println(jugador1.getNombre() + " ha ganado la partida!");
                break;
            }
        }
    }
}