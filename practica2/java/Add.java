/*
 * File:	Add.java
 * Date:	march 2023
 * Comms:	Fichero Add.java de la práctica 2 de la asignatura
 * 		de Tecnología de Programación.
 */
import java.util.Stack;

public class Add extends Instruccion{
   public Add()      //Constructor
   {
   }

   @Override
   public void ejecutar(Stack<Integer> pila, int[] pc){
      int a = pila.pop();             //Desapilo primer sumando
      int b = pila.pop();             //Desapilo segundo sumando
      pila.push(a+b);         		  //apilo el resultado de la suma
   }

   @Override
   public String nombre() {
      return "add";
   }
}
