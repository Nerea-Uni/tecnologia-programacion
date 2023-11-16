/*
 * File:	Mul.java
 * Date:	march 2023
 * Comms:	Fichero Mul.java de la práctica 2 de la asignatura
 * 		de Tecnología de Programación.
 */
import java.util.Stack;

public class Mul extends Instruccion{
   public Mul()      //Constructor
   {
   }

   @Override
   public void ejecutar(Stack<Integer> pila, int[] pc){
      int a = pila.peek();    
      pila.pop();             
      int b = pila.peek();    
      pila.pop();             
      pila.push(a*b);         
   }

   @Override
   public String nombre() {
      return "mul";
   }
}
