/*
 * Name:	rational.cc
 * Title:	Fichero rational.cc de la práctica 1 de la asignatura
 * 		de Tecnología de Programación, realizada con clases.
 * Date:	february 2023
 * Comms:	
 */
#include "rational.h"

// Helper methods -----------------------
int Rational::mcd(int a, int b) {
   return (b == 0 ? a : mcd(b,a%b));
}

void Rational::reduce() {
	int aux = mcd(nume, deno);
	nume /= aux;
	deno /= aux;
}

// Constructor -----------------------
Rational::Rational() 
	: nume(0), deno(1)
{
}

Rational::Rational(int num, int den) 
	: nume(num), deno(den)
{
}

// Input/output ---------------------------------
void Rational::write(std::ostream& os) const {
	os << "= " << nume << "/" << deno << std::endl;
}

void Rational::read(std::istream& is) {
	char trash;
	//guardo el valor del numerador
	is >> nume;
	//ignorar '/'
	is >> trash;
	//guardo el valor del denominador
	is >> deno;
}

/*
 * ----------------------- Add -----------------------
 * Funciones que suman dos números de la siguiente forma:
 * 		- racional + racional
 * 		- racional + int
 * 		- int + racional
 */
Rational Rational::add(const Rational& that) const {
	Rational res;

	res.nume = (this->nume * that.deno) + (this->deno * that.nume);
	res.deno = this->deno * that.deno;

	res.reduce();
	return res;
}

Rational Rational::add(int i) const {
	Rational res;

	res.nume = (this->nume) + (this->deno * i);
	res.deno = this->deno;

	res.reduce();
	return res;
}

Rational add(int i, const Rational& r) {
	Rational ri(i,1);
	return ri.add(r);
}

/*
 * ----------------------- Substract -----------------------
 * Funciones que restan dos números de la siguiente forma:
 * 		- racional + racional
 * 		- racional + int
 * 		- int + racional
 */
Rational Rational::sub(const Rational& that) const {
	Rational res;

	res.nume = (this->nume * that.deno) - (this->deno * that.nume);
	res.deno = this->deno * that.deno;

	res.reduce();
	return res;
}

Rational Rational::sub(int i) const {
	Rational res;

	res.nume = (this->nume) - (this->deno * i);
	res.deno = this->deno;

	res.reduce();
	return res;
}

Rational sub(int i, const Rational& r) {
   	Rational ri(i,1);
	return ri.sub(r);
}

/*
 * ----------------------- Multiply -----------------------
 * Funciones que multiplican dos números de la siguiente forma:
 * 		- racional + racional
 * 		- racional + int
 * 		- int + racional
 */
Rational Rational::mul(const Rational& that) const {
	Rational res;
	
	res.nume = this->nume * that.nume;
	res.deno = this->deno * that.deno;

	res.reduce();
	return res;
}

Rational Rational::mul(int i) const {
	Rational res;
	
	res.nume = this->nume * i;
	res.deno = this->deno;
	
	res.reduce();
	return res;
}

Rational mul(int i, const Rational& r) {
	Rational ri(i,1);
	return ri.mul(r);
}

/*
 * ----------------------- Divide -----------------------
 * Funciones que dividen dos números de la siguiente forma:
 * 		- racional + racional
 * 		- racional + int
 * 		- int + racional
 */
Rational Rational::div(const Rational& that) const {
	Rational res;

	res.nume = this->nume * that.deno;
	res.deno = this->deno * that.nume;

	res.reduce();
	return res;
}

Rational Rational::div(int i) const {
	Rational res;

	res.nume = this->nume;
	res.deno = this->deno * i;

	res.reduce();

	return res;
}

Rational div(int i, const Rational& r) {
	Rational ri(i,1);
	return ri.div(r);
}
