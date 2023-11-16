/*
 * File:	Programa.java
 * Date:	march 2023
 * Comms:	Fichero Programa.java de la práctica 2 de la asignatura
 * 		de Tecnología de Programación.
 */
import java.util.Stack;

public abstract class Programa {
    
    protected int nInstrucciones;
    protected Instruccion[] instrucciones;
    protected static int[] pc = new int[1];
    
    public Programa(int _nInstrucciones) {
        nInstrucciones = _nInstrucciones;
        instrucciones = new Instruccion[nInstrucciones];
    }
    
    public void ejecutar() {
        Stack<Integer> pila = new Stack<Integer>();
        pc[0]=0;
        while (pc[0] < nInstrucciones) {
            instrucciones[pc[0]].ejecutar(pila, pc);
            pc[0]++;
        }
    }
    
    public void listar() {
        for (int i = 0; i < nInstrucciones; i++) {
            System.out.println(i + "  " + instrucciones[i].nombre());
        }
    }
}
