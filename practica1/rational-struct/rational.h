/*
 * Name:	rational.h
 * Title:	Fichero rational.h de la práctica 1 de la asignatura
 * 		de Tecnología de Programación, realizada con structs.
 * Date:	february 2023
 * Comms:	
 */
#pragma once         //para que compile únicamente una vez, no es estándar

#include <iostream>

// Solucion con atributos publicos.
struct Rational {
   int nume, deno;
};

int mcd(int a, int b);
void reduce(Rational& r);

void init(Rational& r);    //numerador 0, denominador 1
void init(Rational& r,int num, int den);     //numerador num, denominador den

// Entrada - salida
            //leer o escribir rationals con el formato indicado en el enunciado
void write(const Rational& r, std::ostream& os);   //
void read(Rational& r, std::istream& is);

// Operaciones aritmeticas

// add
Rational add(const Rational& r1, const Rational& r2);    //rational+rational = rational
Rational add(const Rational& r, int i);                  //rational+entero = rational
Rational add(int i, const Rational& r);                  //entero+rational = rational


// sub
Rational sub(const Rational& r1, const Rational& r2);    
Rational sub(const Rational& r, int i);                  
Rational sub(int i, const Rational& r);                  

// mul
Rational mul(const Rational& r1, const Rational& r2);    
Rational mul(const Rational& r, int i);                  
Rational mul(int i, const Rational& r);                  

// div
Rational div(const Rational& r1, const Rational& r2);    
Rational div(const Rational& r, int i);                  
Rational div(int i, const Rational& r);                  

