/*
 * File:	Write.java
 * Date:	march 2023
 * Comms:	Fichero Write.java de la práctica 2 de la asignatura
 * 		de Tecnología de Programación.
 */
import java.util.Stack;

public class Write extends Instruccion {
    public Write() {    //Constructor
    }
    
    @Override
    public void ejecutar(Stack<Integer> pila, int[] pc)  {
        int num = pila.peek();
        System.out.println(num);
    }
    
    @Override
    public String nombre() {
        return "write";
    }
}

