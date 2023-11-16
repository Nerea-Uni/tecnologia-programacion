/*
 * File:	Swap.java
 * Date:	march 2023
 * Comms:	Fichero Swap.java de la práctica 2 de la asignatura
 * 		de Tecnología de Programación.
 */
import java.util.Stack;

public class Swap extends Instruccion{
   public Swap()      //Constructor
   {
   }

   @Override
   public void ejecutar(Stack<Integer> pila, int[] pc){
      int num1 = pila.peek();
      pila.pop();
      int num2 = pila.peek();
      pila.pop();
      pila.push(num1);
      pila.push(num2);
   }

   @Override
   public String nombre() {
      return "swap";
   }
}
