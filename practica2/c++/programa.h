/*
 * File:	programa.h
 * Date:	march 2023
 * Comms:	Fichero programa.h de la práctica 2 de la asignatura
 * 		de Tecnología de Programación.
 */
#pragma once

#include "instruccion.h"
#include <iostream>
#include <stack>
using namespace std;


class Programa {
protected:
    int pc;
    int nInstrucciones;
    Instruccion** instrucciones;
public:
    Programa(int _nInstrucciones);
    ~Programa();    //Destructor
    
    //operaciones necesarias.
    virtual void ejecutar();
    virtual void listar();
};


// ----------------------- SUMAR -----------------------
class Sumar : public Programa {
public:
    Sumar();
};


// ----------------------- CUENTA ATRAS -----------------------
class CuentaAtras : public Programa {
public:
    CuentaAtras();
};


// ----------------------- FACTORIAL -----------------------
class Factorial : public Programa {
public:
    Factorial();
};
