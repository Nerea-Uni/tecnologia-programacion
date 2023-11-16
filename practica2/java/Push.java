/*
 * File:	Push.java
 * Date:	march 2023
 * Comms:	Fichero Push.java de la práctica 2 de la asignatura
 * 		de Tecnología de Programación.
 */
import java.util.Stack;

public class Push extends Instruccion{
    protected int atributo;

    public Push(int atri)      //Constructor
    {
        this.atributo = atri;
    }

    @Override
    public void ejecutar(Stack<Integer> pila, int[] pc){
        pila.push(atributo);
    }

    @Override
    public String nombre() {
        return "push" + Integer.toString(atributo);
    }
}
