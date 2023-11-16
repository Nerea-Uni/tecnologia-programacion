/*
 * File:	Jumpif.java
 * Date:	march 2023
 * Comms:	Fichero Jumpif.java de la práctica 2 de la asignatura
 * 		de Tecnología de Programación.
 */
import java.util.Stack;

public class Jumpif extends Instruccion {
    private int atributo;
    
    public Jumpif(int atrib) {
        atributo = atrib;
    }

    @Override
    public void ejecutar(Stack<Integer> pila, int[] pc ){
        int num = pila.peek();
        pila.pop();
        if(num >= 0) {
            pc[0] = atributo-1;
        }
    }

    @Override
    public String nombre() {
        return "jumpif " + Integer.toString(atributo);
    }
}
