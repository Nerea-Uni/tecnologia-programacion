/*
 * File:	carga.h
 * Date:	march 2023
 * Comms:	Fichero carga.h de la práctica 3 de la asignatura
 * 		de Tecnología de Programación.
 */
#pragma once
#include "cargable.h"
#include <string>
using namespace std;

/*
 * Clase que representa una carga estándar
 */
class Carga : public Cargable {
public:
    Carga(const string& _nom, double _vol, double _pes);
    string tipo() const override;
};

/*
 * Clase que representa un producto
 */
class Producto : public Carga {
public:
    Producto(const string& _nom, double _vol, double _pes);
    string to_string() const override;
};
