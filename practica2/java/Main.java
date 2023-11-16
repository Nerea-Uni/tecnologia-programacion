/*
 * File:	Main.java
 * Date:	march 2023
 * Comms:	Fichero Main.java de la práctica 2 de la asignatura
 * 		de Tecnología de Programación.
 */
public class Main {
    public static void main(String[] args)
    {
        Sumar S = new Sumar();
        System.out.println("Programa:\n");
        S.listar();
        System.out.println("Ejecutar:\n");
        S.ejecutar();

        CuentaAtras C = new CuentaAtras();
        System.out.println("Programa:\n");
        C.listar();
        System.out.println("Ejecutar:\n");
        C.ejecutar();

        Factorial F = new Factorial();
        System.out.println("Programa:\n");
        F.listar();
        System.out.println("Ejecutar:\n");
        F.ejecutar();
    }
}
