/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package batallanavalproyecto;

abstract class Barco {
    private int longitud;
    private char simbolo;

    public Barco(int longitud, char simbolo) {
        this.longitud = longitud;
        this.simbolo = simbolo;
    }

    public int getLongitud() {
        return longitud;
    }

    public char getSimbolo() {
        return simbolo;
    }
}

class Portaaviones extends Barco {
    public Portaaviones() {
        super(5, 'P');
    }
}

class Fragata extends Barco {
    public Fragata() {
        super(4, 'F');
    }
}

class Crucero extends Barco {
    public Crucero() {
        super(3, 'C');
    }
}

class Submarino extends Barco {
    public Submarino() {
        super(3, 'S');
    }
}

class Destructor extends Barco {
    public Destructor() {
        super(2, 'D');
    }
}

