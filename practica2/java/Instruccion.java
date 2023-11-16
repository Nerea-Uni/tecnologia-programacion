/*
 * File:	Instruccion.java
 * Date:	march 2023
 * Comms:	Fichero Instruccion.java de la práctica 2 de la asignatura
 * 		de Tecnología de Programación.
 */
import java.util.Stack;

public abstract class Instruccion
{
    // Constructor
    public Instruccion() {}
    
    public void ejecutar(Stack<Integer> pila, int[] pc){}
    public String nombre(){ return "";}
}
