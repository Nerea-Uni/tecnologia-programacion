/*
 * File:    Fichero.java
 * Date:    april 2023
 * Comms:   Fichero Fichero.java de la práctica 4 de la asignatura
 * 			de Tecnología de Programación.
 */
public class Fichero extends Nodo {
    protected int tam;

    public Fichero(String _name, int _size) {
        super(_name);
        this.tam = _size;
    }

    @Override
    public int tamagno() {
        return tam;
    }

    public void actTamagno(int _size){
        tam = _size;
    }
}


