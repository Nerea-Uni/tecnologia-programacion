/*
 * File:	Sumar.java
 * Date:	march 2023
 * Comms:	Fichero Sumar.java de la práctica 2 de la asignatura
 * 		de Tecnología de Programación.
 */
public class Sumar extends Programa {
    public Sumar(){
        super(4);
        instrucciones = new Instruccion[4];
        instrucciones[0] = new Read();
        instrucciones[1] = new Read();
        instrucciones[2] = new Add();
        instrucciones[3] = new Write();
    }
}
