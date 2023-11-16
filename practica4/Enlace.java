/*
 * File:    Enlace.java
 * Date:    april 2023
 * Comms:   Fichero Enlace.java de la práctica 4 de la asignatura
 * 			de Tecnología de Programación.
 */
public class Enlace extends Nodo {
    public Nodo link;
    
    public Enlace (String _name){
        super(_name);
    }

    //Devuelve el tamaño del archivo o directorio referenciado.
    public int tamagno() {
        return link.tamagno();
    }

    //Devuelve el link que referencia a un directorio
    public Nodo getLink() {
        return link;
    }
}
