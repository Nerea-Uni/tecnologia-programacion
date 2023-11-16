/*
 * File:	Over.java
 * Date:	march 2023
 * Comms:	Fichero Over.java de la práctica 2 de la asignatura
 * 		de Tecnología de Programación.
 */
import java.util.Stack;

public class Over extends Instruccion{
    public Over()      //Constructor
    {
    }

    @Override
    public void ejecutar(Stack<Integer> pila, int[] pc){
        int num1 = pila.pop();             
        int num2 = pila.pop();             
        pila.push(num2);         
        pila.push(num1);     
        pila.push(num2);     
    }

    @Override
    public String nombre() {
        return "over";
    }
}
