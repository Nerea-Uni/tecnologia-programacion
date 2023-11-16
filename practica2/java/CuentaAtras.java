/*
 * File:	CuentaAtras.java
 * Date:	march 2023
 * Comms:	Fichero CuentaAtras.java de la práctica 2 de la asignatura
 * 		de Tecnología de Programación.
 */
public class CuentaAtras extends Programa {
    public CuentaAtras() {
        super(7);
        instrucciones = new Instruccion[7];
        instrucciones[0] = new Read();
        instrucciones[1] = new Dup();
        instrucciones[2] = new Write();
        instrucciones[3] = new Push(-1);
        instrucciones[4] = new Add();
        instrucciones[5] = new Dup();
        instrucciones[6] = new Jumpif(1);
    }
}
