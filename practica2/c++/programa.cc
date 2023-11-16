/*
 * File:	programa.cc
 * Date:	march 2023
 * Comms:	Fichero programa.cc de la práctica 2 de la asignatura
 * 		de Tecnología de Programación.
 */
#include "programa.h"

//Constructor
Programa::Programa(int _nInstrucciones)
    : nInstrucciones(_nInstrucciones), pc(0) //inicializo la pila vacía y sin instrucciones
{
    instrucciones = new Instruccion*[nInstrucciones];
}

//Destructor
Programa::~Programa()
{
}


/*
 * Función que ejecuta cada instrucción.
 */
void Programa::ejecutar(){
    stack<int> pila;
    this->pc = 0;
    for (pc; pc < nInstrucciones; pc++){
        instrucciones[pc]->ejecutar(pila, pc);   //Ejecuta la instrucción.
    }
}


/*
 * Función que muestra por pantalla el número de la instrucción
 * seguido por el nombre de dicha instrucción.
 */
void Programa::listar() {
    for (pc; pc < nInstrucciones; pc++){
        cout << pc << "  " << instrucciones[pc]->nombre() << endl;
    }
    cout << endl;
}


// ----------------------- SUMAR -----------------------
Sumar::Sumar():Programa(4){
    instrucciones[0] = new Read();
    instrucciones[1] = new Read();
    instrucciones[2] = new Add();
    instrucciones[3] = new Write();
}


// ----------------------- CUENTA ATRAS -----------------------
CuentaAtras::CuentaAtras():Programa(7){
    instrucciones[0] = new Read();
    instrucciones[1] = new Dup();
    instrucciones[2] = new Write();
    instrucciones[3] = new Push(-1);
    instrucciones[4] = new Add();
    instrucciones[5] = new Dup();
    instrucciones[6] = new Jumpif(1);
}


// ----------------------- FACTORIAL -----------------------
Factorial::Factorial():Programa(14){
    instrucciones[0] = new Push(1);
    instrucciones[1] = new Read();
    instrucciones[2] = new Swap();
    instrucciones[3] = new Over();
    instrucciones[4] = new Mul();
    instrucciones[5] = new Swap();
    instrucciones[6] = new Push(-1);
    instrucciones[7] = new Add();
    instrucciones[8] = new Dup();
    instrucciones[9] = new Push(-2);
    instrucciones[10] = new Add();
    instrucciones[11] = new Jumpif(2);
    instrucciones[12] = new Swap();
    instrucciones[13] = new Write();
}

