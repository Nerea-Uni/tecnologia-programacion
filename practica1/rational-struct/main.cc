/*
 * Name:	main.cc
 * Title:	Fichero main.cc de la práctica 1 de la asignatura
 *		de Tecnología de Programación, realizada con structs.
 * Date:	february 2023
 * Comms:	
 */
#include "rational.h"
#include <iostream>

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

		read(a,cin);		//a = dato introducido en cin
//		cin >> a;			// Un entero y un racional
		if (cin.fail()){		//lee hasta que detecta algo que no encaja en las operaciones (ejemplo: un '.')
			break;
		}
		cin >> op;

		read(b,cin);		//b = dato introducido en cin
//		cin >> b;			// Un racional y un entero
		if (cin.fail()){
			break;
		}
		
		// Cálculo del resultado
		if(op == '+'){
			r = add(a, b);
		}
		else if(op == '-'){
			r = sub(a, b);
		}
		else if(op == '*'){
			r = mul(a, b);
		}
		else if(op == '/'){
			r = div(a, b);
		}

		// Escritura del resultado
		write(r, cout);
	}

	return 0;
}

