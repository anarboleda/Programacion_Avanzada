package batallanavalproyecto;

// Definición de la clase Tablero
import java.util.Arrays;

public class Tablero {
    private static final int FILAS = 10;
    private static final int COLUMNAS = 10;
    private static final char AGUA = '~';
    private static final char ATINADO = 'X';
    private static final char FALLO = 'O';
    private char[][] tablero;

    public Tablero() {
        tablero = new char[FILAS][COLUMNAS];
        for (char[] fila : tablero) {
            Arrays.fill(fila, AGUA);
        }
    }

    public void imprimirTablero() {
        System.out.print("  ");
        for (int i = 1; i <= COLUMNAS; i++) {
            System.out.print("\t" + i);
        }
        System.out.println();
        for (int i = 0; i < FILAS; i++) {
            char letraFila = (char) ('A' + i);
            System.out.print(letraFila + " ");
            for (int j = 0; j < COLUMNAS; j++) {
                System.out.print("\t" + tablero[i][j]);
            }
            System.out.println();
        }
    }

    public void colocarBarco(char filaInicial, int columnaInicial, Barco barco, int direccion) throws Exception {
        int fila = filaInicial - 'A';
        int columna = columnaInicial - 1;
        int longitud = barco.getLongitud();
        char simbolo = barco.getSimbolo();

        if (direccion < 1 || direccion > 4) {
            throw new Exception("Dirección inválida. Debe ser entre 1 y 4.");
        }

        if (!esPosicionValida(fila, columna, longitud, direccion)) {
            throw new Exception("Posición inválida o barco fuera del tablero. Intenta de nuevo.");
        }

        if (direccion == 1) { // Arriba
            for (int i = 0; i < longitud; i++) {
                tablero[fila - i][columna] = simbolo;
            }
        } else if (direccion == 2) { // Abajo
            for (int i = 0; i < longitud; i++) {
                tablero[fila + i][columna] = simbolo;
            }
        } else if (direccion == 3) { // Derecha
            for (int i = 0; i < longitud; i++) {
                tablero[fila][columna + i] = simbolo;
            }
        } else if (direccion == 4) { // Izquierda
            for (int i = 0; i < longitud; i++) {
                tablero[fila][columna - i] = simbolo;
            }
        }
    }

    private boolean esPosicionValida(int fila, int columna, int longitud, int direccion) {
        if (direccion == 1) { // Arriba
            if (fila - longitud + 1 < 0) return false;
            for (int i = 0; i < longitud; i++) {
                if (tablero[fila - i][columna] != AGUA) return false;
            }
        } else if (direccion == 2) { // Abajo
            if (fila + longitud - 1 >= FILAS) return false;
            for (int i = 0; i < longitud; i++) {
                if (tablero[fila + i][columna] != AGUA) return false;
            }
        } else if (direccion == 3) { // Derecha
            if (columna + longitud - 1 >= COLUMNAS) return false;
            for (int i = 0; i < longitud; i++) {
                if (tablero[fila][columna + i] != AGUA) return false;
            }
        } else if (direccion == 4) { // Izquierda
            if (columna - longitud + 1 < 0) return false;
            for (int i = 0; i < longitud; i++) {
                if (tablero[fila][columna - i] != AGUA) return false;
            }
        }
        return true;
    }

    public boolean disparar(char fila, int columna) {
        int filaIndex = fila - 'A';
        int columnaIndex = columna - 1;

        if (filaIndex < 0 || filaIndex >= FILAS || columnaIndex < 0 || columnaIndex >= COLUMNAS) {
            System.out.println("Disparo fuera del tablero. Intenta de nuevo.");
            return false;
        }

        if (tablero[filaIndex][columnaIndex] == AGUA) {
            tablero[filaIndex][columnaIndex] = FALLO;
            return false;
        } else {
            tablero[filaIndex][columnaIndex] = ATINADO;
            return true;
        }
    }

    public boolean quedanBarcos() {
        for (char[] fila : tablero) {
            for (char celda : fila) {
                if (celda != AGUA && celda != ATINADO && celda != FALLO) {
                    return true;
                }
            }
        }
        return false;
    }
}

