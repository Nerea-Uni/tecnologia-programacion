/*
 * Name:	rational.h
 * Title:	Fichero rational.h de la práctica 1 de la asignatura
 * 		de Tecnología de Programación, realizada con clases.
 * Date:	february 2023
 * Comms:	
 */
#pragma once

#include <iostream>

// Solucion con atributos privados.
class Rational {
private:
	// Miembros		//los atributos, los que representan datos.
	int nume;
	int deno;

	// Funciones auxiliares
	static int mcd(int a, int b);
	void reduce();

public:
	// Constructores
	Rational();			//numerador 0, denominador 1
	Rational(int num, int den);		//numerador num, denominador den

	// Entrada - salida
	void write(std::ostream& os) const;
	void read(std::istream& is);

	// Operadores aritmeticos
	Rational add(const Rational& that) const;		//el rational está implícito
	Rational add(int i) const;
	
	Rational sub(const Rational& that) const;
	Rational sub(int i) const;

	Rational mul(const Rational& that) const;
	Rational mul(int i) const;

	Rational div(const Rational& that) const;
	Rational div(int i) const;
};

// Operadores aritmeticos
Rational add(int i, const Rational& r);
Rational sub(int i, const Rational& r);
Rational mul(int i, const Rational& r);
Rational div(int i, const Rational& r);
