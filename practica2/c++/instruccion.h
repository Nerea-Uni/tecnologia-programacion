/*
 * File:	instruccion.h
 * Date:	march 2023
 * Comms:	Fichero instruccion.h de la práctica 2 de la asignatura
 * 		de Tecnología de Programación.
 */
#pragma once

#include <iostream>
#include <stack>
#include <string>
using namespace std;


class Instruccion {
public:
    Instruccion();
    virtual void ejecutar(stack<int>& pila, int& pc) const = 0;
    virtual string nombre() = 0;
};


// ---------------------------- READ -------------------------
// Pide un valor al usuario por la entrada estándar (indicando 
// al usuario de alguna forma que espera una entrada de datos)
// y lo apila en la pila.
class Read : public Instruccion {
public:
    Read();
    virtual void ejecutar(stack<int>& pila, int& pc) const override;
    string nombre() override;
};


// ---------------------------- WRITE -------------------------
// Desapila un valor de la pila y lo muestra por la salida
// estándar (pantalla) al usuario.
class Write : public Instruccion {
public:
    Write();
    virtual void ejecutar(stack<int>& pila, int& pc) const override;
    string nombre() override;
};


// ---------------------------- ADD -------------------------
// Desapila dos valores de la pila y apila su suma.
class Add : public Instruccion{
public:
    Add();
    virtual void ejecutar(stack<int> &pila, int& pc) const override;
    string nombre() override;
};


// ---------------------------- DUP -------------------------
// Duplica la cima de la pila (desapila su valor y lo reapila dos veces).
class Dup : public Instruccion {
public:
    Dup();
    virtual void ejecutar(stack<int>& pila, int& pc) const override;
    string nombre() override;
};


// ---------------------------- PUSH -------------------------
// Apila la constante <c> (parámetro de la instrucción) en la pila.
class Push : public Instruccion {
protected:
    int atributo;
public:
    Push(int atri);
    virtual void ejecutar(stack<int>& pila, int& pc) const override;
    string nombre() override;
};


// ---------------------------- JUMPIF -------------------------
// Desapila la cima de la pila, y si su valor es mayor o igual 
// que cero salta la ejecución del programa a la línea <l> 
// (parámetro de la instrucción).
class Jumpif : public Instruccion {
private:
    int atributo;
public:
    Jumpif(int atri);
    virtual void ejecutar(stack<int>& pila, int& pc) const override;
    string nombre() override;
};


// ---------------------------- OVER -------------------------
// Copia (apila) el valor que está tras la cima de la pila 
// (desapila dos valores, apila el segundo desapilado, después
// el primero y por último el segundo otra vez).
class Over : public Instruccion {
public:
    Over();
    virtual void ejecutar(stack<int>& pila, int& pc) const override;
    string nombre() override;
};


// ---------------------------- SWAP -------------------------
// Intercambia dos elementos en la cima de la pila (desapila 
// dos valores y los reapila en orden inverso).
class Swap : public Instruccion {
public:
    Swap();
    virtual void ejecutar(stack<int>& pila, int& pc) const override;
    string nombre() override;
};


// ---------------------------- MUL -------------------------
// Desapila dos valores de la pila y apila su producto.
class Mul : public Instruccion {
public:
    Mul();
    virtual void ejecutar(stack<int>& pila, int& pc) const override;
    string nombre() override;
};

