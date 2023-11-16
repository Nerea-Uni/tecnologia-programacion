/*
 * Name:	main.cc
 * Title:	Fichero main.cc de la práctica 1 de la asignatura
 * 		de Tecnología de Programación, realizada con clases.
 * Date:	february 2023
 * Comms:	
 */
#include <iostream>
#include "rational.h"

using namespace std;

int main() {
	// Dos racionales
	Rational	a,b,r;

	// Un racional y un entero
//	int b;
//	Rational a, r;
	// Un entero y un racional
//	int a;
//	Rational b, r;

	char op;

	while (true) {
		cout << "? " << flush;
		a.read(cin);
//		cin >> a;			// Un entero y un racional
		if (cin.fail()){
			break;
		}
		cin >> op;
		b.read(cin);
//		cin >> b;			// Un racional y un entero
		if (cin.fail()){
			break;
		}
		// Calculo del resultado
		if(op == '+'){
			r = a.add(b);
//			r = add(a,b);		//Un entero y un racional
		}
		else if(op == '-'){
			r = a.sub(b);
//			r = sub(a,b);		//Un entero y un racional
		}
		else if(op == '*'){
			r = a.mul(b);
//			r = mul(a,b);		//Un entero y un racional
		}
		else if(op == '/'){
			r = a.div(b);
//			r = div(a,b);		//Un entero y un racional
		}

		// Escritura del resultado
		r.write(cout);
	}
	return 0;
}
