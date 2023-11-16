/*
 * File:	Read.java
 * Date:	march 2023
 * Comms:	Fichero Read.java de la práctica 2 de la asignatura
 * 		de Tecnología de Programación.
 */
import java.util.Scanner;
import java.util.Stack;

public class Read extends Instruccion {
    
    public Read() {}
    
    @Override
    public void ejecutar(Stack<Integer> pila, int[] pc) {
        System.out.print("? ");
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        pila.push(num);
        //sc.close();
    }
    
    public String nombre() {
        return "read";
    }
}
