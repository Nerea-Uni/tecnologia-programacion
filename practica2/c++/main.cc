/*
 * File:	main.cc
 * Date:	march 2023
 * Comms:	Fichero main.cc de la práctica 2 de la asignatura
 * 		de Tecnología de Programación.
 */
#include <iostream>
#include "programa.h"
using namespace std;

int main() {
    Sumar S;
    cout << "Programa:\n";
    S.listar();
    cout << "\nEjecutar:\n";
    S.ejecutar();

    CuentaAtras C;
    cout << "Programa:\n";
    C.listar();
    cout << "\nEjecutar:\n";
    C.ejecutar();

    Factorial F;
    cout << "Programa:\n";
    F.listar();
    cout << "\nEjecutar:\n";
    F.ejecutar();
}
