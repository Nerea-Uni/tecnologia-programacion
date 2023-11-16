/*
 * File:	Dup.java
 * Date:	march 2023
 * Comms:	Fichero Dup.java de la práctica 2 de la asignatura
 * 		de Tecnología de Programación.
 */
import java.util.Stack;

public class Dup extends Instruccion{
    public Dup()      //Constructor
    {
    }

    @Override
    public void ejecutar(Stack<Integer> pila, int[] pc){
        int num = pila.peek();
        pila.push(num);
    }

    @Override
    public String nombre() {
        return "dup";
    }
}
