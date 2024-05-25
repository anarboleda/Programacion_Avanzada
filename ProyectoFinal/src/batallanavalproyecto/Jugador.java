/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package batallanavalproyecto;

import java.util.Scanner;

abstract class Jugador {
    private String nombre;
    private Tablero tablero;
    private boolean gano;

    public Jugador(String nombre) {
        this.nombre = nombre;
        this.tablero = new Tablero();
        this.gano = false;
    }

    public String getNombre() {
        return nombre;
    }

    public Tablero getTablero() {
        return tablero;
    }

    public boolean haGanado() {
        return gano;
    }

    public void setGano(boolean gano) {
        this.gano = gano;
    }

    public abstract void colocarBarcos();

    public abstract void disparar(Jugador oponente);

    public void imprimirTablero() {
        System.out.println("Tablero de " + getNombre() + ":");
        getTablero().imprimirTablero();
    }
}

class JugadorHumano extends Jugador {
    public JugadorHumano(String nombre) {
        super(nombre);
    }

    @Override
    public void colocarBarcos() {
        Scanner scanner = new Scanner(System.in);
        Barco[] barcos = {
            new Portaaviones(),
            new Fragata(),
            new Crucero(),
            new Submarino(),
            new Destructor()
        };

        for (Barco barco : barcos) {
            boolean colocado = false;
            while (!colocado) {
                try {
                    System.out.println(getNombre() + ", coloca tu " + barco.getSimbolo() + " de longitud " + barco.getLongitud());
                    System.out.print("Fila inicial (A-J): ");
                    char filaInicial = scanner.next().charAt(0);
                    System.out.print("Columna inicial (1-10): ");
                    int columnaInicial = scanner.nextInt();
                    System.out.print("Dirección (1=Arriba, 2=Abajo, 3=Derecha, 4=Izquierda): ");
                    int direccion = scanner.nextInt();

                    getTablero().colocarBarco(filaInicial, columnaInicial, barco, direccion);
                    colocado = true;
                } catch (Exception e) {
                    System.out.println(e.getMessage());
                }
            }
        }
    }

    @Override
    public void disparar(Jugador oponente) {
        Scanner scanner = new Scanner(System.in);
        boolean disparoValido = false;
        while (!disparoValido) {
            System.out.println(getNombre() + ", ingresa tu disparo.");
            System.out.print("Fila (A-J): ");
            char fila = scanner.next().charAt(0);
            System.out.print("Columna (1-10): ");
            int columna = scanner.nextInt();

            disparoValido = oponente.getTablero().disparar(fila, columna);

            if (disparoValido) {
                System.out.println("¡Disparo acertado!");
            } else {
                System.out.println("Disparo fallido.");
            }

            if (!oponente.getTablero().quedanBarcos()) {
                oponente.setGano(true);
                setGano(false);
                break;
            }
        }
    }
}



