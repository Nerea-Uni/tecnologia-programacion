/*
 * Name:	rational.cc
 * Title:	Fichero rational.cc de la práctica 1 de la asignatura
 * 		de Tecnología de Programación, realizada con structs.
 * Date:	february 2023
 * Comms:	
 */
#include "rational.h"


// Helper functions -----------------------
int mcd(int a, int b) {
   return ( b == 0 ? a : mcd(b,a%b));
}

void reduce(Rational& r) {
   int aux = mcd(r.nume, r.deno);
   r.nume /= aux;
   r.deno /= aux;
}

// Constructor -----------------------
void init(Rational& r) {
   r.nume = 0;
   r.deno = 1;
}
void init(Rational& r,int num, int den) {
   r.nume = num;
   r.deno = den;
}

// Input/output ---------------------------------
void write(const Rational& r, std::ostream& os) {
 	os << "= " << r.nume << "/" << r.deno << std::endl;
}

void read(Rational& r, std::istream& is) {
	char trash;
	//guardo el valor del numerador
	is >> r.nume;
	//ignorar '/'
	is >> trash;
	//guardo el valor del denominador
	is >> r.deno;
}


// Add -----------------------
Rational add(const Rational& r1, const Rational& r2) {
	Rational res;
	//Calculamos numerador y denominador del resultado
	res.nume = (r1.nume * r2.deno) + (r1.deno * r2.nume);
	res.deno = r1.deno * r2.deno;		
	//Simplificamos la fracción
	reduce(res);

	return res;
}

Rational add(const Rational& r, int i) {
	Rational res, ri;
	//Inicializo una variable con el numerador = i y el denominador = 1 (definición de número entero)
	init(ri, i, 1);
	//sumo ambas fracciones con la función definida anteriormente
	res = add(r, ri);
	return res;
}

Rational add(int i, const Rational& r) {
	Rational res, ri;
	//Inicializo una variable con el numerador = i y el denominador = 1 (definición de número entero)
	init(ri, i, 1);
	//sumo ambas fracciones con la función definida anteriormente
	res = add(ri, r);
	return res;
}

// Subtract -----------------------
Rational sub(const Rational& r1, const Rational& r2) {
	Rational res;
	//Calculamos numerador y denominador del resultado
	res.nume = (r1.nume * r2.deno) - (r1.deno * r2.nume);
	res.deno = r1.deno * r2.deno;		
	//Simplificamos la fracción
	reduce(res);

	return res;
}

Rational sub(const Rational& r, int i) {
	Rational res, ri;
	//Inicializo una variable con el numerador = i y el denominador = 1 (definición de número entero)
	init(ri, i, 1);
	//resto ambas fracciones con la función definida anteriormente
	res = sub(r, ri);
	return res;
}

Rational sub(int i, const Rational& r) {
	Rational res, ri;
	//Inicializo una variable con el numerador = i y el denominador = 1 (definición de número entero)
	init(ri, i, 1);
	//resto ambas fracciones con la función definida anteriormente
	res = sub(ri, r);
	return res;
}

// Multiply -------------------------
Rational mul(const Rational& r1, const Rational& r2) {
	Rational res;
	//Calculamos numerador y denominador del resultado
	res.nume = r1.nume * r2.nume; 
	res.deno = r1.deno * r2.deno;

	//Simplificamos la fracción
	reduce(res);

	return res;
}

Rational mul(const Rational& r, int i) {
	Rational res, ri;
	//Inicializo una variable con el numerador = i y el denominador = 1 (definición de número entero)
	init(ri, i, 1);
	//multiplico ambas fracciones con la función definida anteriormente
	res = mul(r, ri);
	return res;
}

Rational mul(int i, const Rational& r) {
	Rational res, ri;
	//Inicializo una variable con el numerador = i y el denominador = 1 (definición de número entero)
	init(ri, i, 1);
	//multiplico ambas fracciones con la función definida anteriormente
	res = mul(ri, r);
	return res;
}

// Divide ------------------------------
Rational div(const Rational& r1, const Rational& r2) {
	Rational res;
	//Calculamos numerador y denominador del resultado
	res.nume = r1.nume * r2.deno;
	res.deno = r1.deno * r2.nume;

	//Simplificamos la fracción
	reduce(res);

	return res;
}

Rational div(const Rational& r, int i) {
	Rational res, ri;
	//Inicializo una variable con el numerador = i y el denominador = 1 (definición de número entero)
	init(ri, i, 1);
	//divido ambas fracciones con la función definida anteriormente
	res = div(r, ri);
	return res;
}

Rational div(int i, const Rational& r) {
	Rational res, ri;
	//Inicializo una variable con el numerador = i y el denominador = 1 (definición de número entero)
	init(ri, i, 1);
	//divido ambas fracciones con la función definida anteriormente
	res = div(ri, r);
	return res;
}
