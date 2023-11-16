/*
 * File:    Nodo.java
 * Date:    april 2023
 * Comms:   Fichero Nodo.java de la práctica 4 de la asignatura
 * 			de Tecnología de Programación.
 */
public abstract class Nodo {
    protected String name;
    
    public Nodo (String _name) {
        this.name = _name;
    }

    public String nombre() {
        return name;
    }

    public abstract int tamagno();
}
